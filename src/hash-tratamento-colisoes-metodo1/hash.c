#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../headers/hashing.h"
#include "../../headers/stc_pessoa.h"
#include "../lista-encadeada/lista_encadeada.h"

typedef struct _hash_node {
    Pessoa p;
    list *externa;
} hash_node;

typedef struct _hash_table {
    hash_node *table;
    int table_size;
} hash_table;


//funçoes
hash_table* create_hash(int n){
    hash_table *ht = (hash_table*) malloc(sizeof(hash_table));
    if(ht != NULL){
        //criar os vetores
        ht->table = (hash_node*) malloc(n*sizeof(hash_node));
        //CHAVE -1 REPRESENTA POSICAO VAZIA
        for(int i = 0; i<n; i++){
            ht->table[i].p.chave = -1;
            ht->table[i].externa = NULL;;
        }
        ht->table_size = n;
        if(ht->table == NULL){
            printf("Erro de Alocacao no vetor de hash!!\n");
            return NULL;
        }
    }
    return ht;
}
bool insert_ht(hash_table *ht, Pessoa p){
    int pos = hashing(p.chave, ht->table_size);
    if(ht == NULL){
        return false;
    }
    if(ht->table == NULL){
        return false;
    }
    if(ht->table[pos].p.chave == -1){
        //posicao vazia
        ht->table[pos].p = p;
        return true;
    } else {
        printf("\nCOLISAO\n");
        //inserir na lista externa
        if(ht->table[pos].externa == NULL){
            //Lista não existe
            ht->table[pos].externa = create_list();
            insert(ht->table[pos].externa, p);
            return true;
        } else {
            //
            insert(ht->table[pos].externa, p);
            return true;
        }
    }
}

Pessoa search_ht(hash_table *ht, int chave){
    int pos = hashing(chave, ht->table_size);
    if(ht->table[pos].p.chave == chave){
        //achou
        return ht->table[pos].p;
    } else {
        if(ht->table[pos].externa == NULL){
            //não tem essa pessoa na hash table
            exit(1);
        } else {
            return search(ht->table[pos].externa, chave);
        }
    }
}

void delete(hash_table *ht, int chave){
    int pos = hashing(chave, ht->table_size);
    if(ht->table[pos].p.chave == chave){
        //achou
        if(ht->table[pos].externa != NULL){
            ht->table[pos].p = front(ht->table[pos].externa);
            pop_front(ht->table[pos].externa);
        } else {
            ht->table[pos].p.chave = -1;
        }
    } else {
        //apagar valor da lista externa
        erase(ht->table[pos].externa, chave);
    }
}

void destroy_hash(hash_table *ht){
    int tam = ht->table_size;
    for(int i = 0; i<tam; i++){
        if(ht->table[i].p.chave != -1){
            if(ht->table[i].externa != NULL){
                destroy(ht->table[i].externa);
            }
        }
    }
    free(ht->table);
    free(ht);
}

void print_ht(hash_table *ht){
    if(ht == NULL){
        return ;
    }
    if(ht->table == NULL){
        return ;
    }
    int table_size = ht->table_size;
    for(int i = 0; i < table_size; i++){
        if(ht->table[i].p.chave != -1){
            printPessoa(ht->table[i].p);
            if(ht->table[i].externa != NULL){
                printList(ht->table[i].externa);
            }
        }
    }
}
int main(){
     Pessoa temp;
    char linha[200];
    int erros = 0, sucesso = 0;
    char *filename = "../../dados/dados-500000-lin.csv";
    hash_table *cadastro = create_hash(50);
    FILE *arquivo = fopen(filename, "r");
    if(arquivo == NULL){
        printf("Erro na Abertura do Arquivo!!\n");
    }
    //ignorando o cabecalho do arquivo
    fgets(linha, sizeof(linha), arquivo);
    //setando linha pessoa
    temp.linha = 0;

    //lendo o intervalo estabelecido pelo professor
    while(feof(arquivo) || temp.linha <= 16000){
        fgets(linha, sizeof(linha), arquivo);
        temp = parseData(linha);
        if(temp.linha >= 8000 && temp.linha <=16000){
            printPessoa(temp);
            //inserir esse intervalo na tabela
            if(insert_ht(cadastro, temp)){
                sucesso++;
            }else {
                erros++;
            }
        }
    }
 
    //listar_tabela(cadastro);
    printf("Ocorreram : %d Colisoes, %d Insercoes\n", erros, sucesso);
    //save_table(cadastro);
    destroy_hash(cadastro);
    fclose(arquivo);
    return 0;
}