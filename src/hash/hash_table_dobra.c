#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../headers/hashing_dobra.h"
#include "../../headers/stc_pessoa.h"

//definicao da estrutura
typedef Pessoa data;

typedef struct _hash_table {
    data *dt;
    int table_size;
} hash_table;

//cabecalhos
hash_table* create_hash(int n);
bool insertion(hash_table *hash, data x);
data search(int key, hash_table *hash);
bool remove_node(int key, hash_table *hash);
void listar_tabela(hash_table *hash);
bool save_table(hash_table *hash);
bool free_table(hash_table *hash);

int main(){
    Pessoa temp;
    char linha[200];
    int erros = 0, sucesso = 0;
    char *filename = "../../dados/dados-500000-lin.csv";
    hash_table *cadastro = create_hash(9000);
    FILE *arquivo = fopen(filename, "r");
    if(arquivo == NULL){
        printf("Erro na Abertura do Arquivo!!\n");
    }
    //ignorando o cabecalho do arquivo
    fgets(linha, sizeof(linha), arquivo);
    //setando linha pessoa
    temp.linha = 0;

    //lendo o intervalo estabelecido pelo professor
    while(feof(arquivo) || temp.linha <= 9000){
        fgets(linha, sizeof(linha), arquivo);
        temp = parseData(linha);
        if(temp.linha >= 8000 && temp.linha <=9000){
            printPessoa(temp);
            //inserir esse intervalo na tabela
            if(insertion(cadastro, temp)){
                sucesso++;
            }else {
                erros++;
            }
        }
    }
 
    //listar_tabela(cadastro);
    printf("Ocorreram : %d Colisoes, %d Insercoes\n", erros, sucesso);
    save_table(cadastro);
    free_table(cadastro);
    fclose(arquivo);
    return 0;
}


//funçoes
hash_table* create_hash(int n){
    hash_table *ht = (hash_table*) malloc(sizeof(hash_table));
    if(ht != NULL){
        //criar os vetores
        ht->dt = (data*) malloc(n*sizeof(data));
        //CHAVE -1 REPRESENTA POSICAO VAZIA
        for(int i = 0; i<n; i++){
            ht->dt[i].chave = -1;
        }
        ht->table_size = n;
        if(ht->dt == NULL){
            printf("Erro de Alocacao no vetor de hash!!\n");
            return NULL;
        }
    }
    return ht;
}

bool insertion(hash_table *hash, data x){
    if(hash == NULL && hash->dt == NULL){
        return false;
    }
    int key = x.chave;
    int pos = hashing(key, hash->table_size);
    if(hash->dt[pos].chave == -1){
        //posicao vazia
        hash->dt[pos] = x;
        return true;
    } else {
        return false;
    }
    
    
}

data search(int key, hash_table *hash){
    int pos = hashing(key, hash->table_size);
    if(hash->dt[pos].chave != -1){
        //existe alguem no indice buscado
        return hash->dt[pos];
    } 
}

bool remove_node(int key, hash_table *hash){
    int pos = hashing(key, hash->table_size);
    if(hash->dt[pos].chave == key){
        //tudo certo
        hash->dt[pos].chave = -1;
        return true;
    }
    return false;
}

bool free_table(hash_table *hash){
    if(hash != NULL){
        free(hash->dt);
        free(hash);
        return true;
    } else {
        return false;
    }
    
}

void listar_tabela(hash_table *hash){
    int n = hash->table_size;
    for(int i = 0; i<n; i++){
        if(hash->dt[i].chave != -1){
            printPessoa(hash->dt[i]);
        }
    }
}
bool save_table(hash_table *hash){
    int n;
    Pessoa temp;
    char *filename = "hashtable.txt";
    FILE *arquivo = fopen(filename, "w");
    if(hash == NULL || arquivo == NULL){
        return false;
    }
    n = hash->table_size;
    for(int i = 0; i<n; i++){
        if(hash->dt[i].chave != -1){
            //gravar
            temp = hash->dt[i];
            //Sequencia Tabela: linha,Address,id,Birth Date,Name,Email Address,Phone Number
            fprintf(arquivo, "%d,", temp.linha);
            fprintf(arquivo, "%s,", temp.endereco);
            fprintf(arquivo, "%d,", temp.chave);
            fprintf(arquivo, "%s,", temp.datanasc);
            fprintf(arquivo, "%s,", temp.nome);
            fprintf(arquivo, "%s,", temp.email);
            fprintf(arquivo, "%s\n", temp.celular);
        }
    }
    fclose(arquivo);

}
