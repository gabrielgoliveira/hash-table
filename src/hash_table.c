#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stc_pessoa.h"

#define MAXSIZE 100

typedef Pessoa data;

typedef struct _hash_table {
    data *dt;
} hash_table;

hash_table* create_hash();
int insertbydivision(hash_table *ht, data r, int tablesize);

int main(){
    /*Essa função principal é so pra testes, esse arquivo se tornara um arquivo de cabeçalho*/
    Pessoa r;
    int temp;
    hash_table *pessoas = create_hash(MAXSIZE);
    strncpy(r.nome, "Joao Gomes", sizeof(r.nome));
    r.chave = 13;
    printPessoa(r);
    temp = insertbydivision(pessoas, r, MAXSIZE);
    printf("Função Principal\n");
    printPessoa(pessoas->dt[temp]);

}

hash_table* create_hash(int n){
    hash_table *ht = (hash_table*) malloc(sizeof(hash_table));
    if(ht != NULL){
        //criar os vetores
        ht->dt = (data*) malloc(n*sizeof(data));
        if(ht->dt == NULL){
            printf("Erro de Alocacao no vetor de hash!!\n");
            return NULL;
        }
    }
    return ht;
}

int insertbydivision(hash_table *ht, data r, int tablesize){
    /* 
    * About: Inserção na tabela hash utilizando o metodo da divisão para realizar os calculos de chave
    * Retorno: Posição onde foi inserido
    */
    int key;
    int pos;
    if(ht == NULL){
        printf("ERRO: Voce deve alocar a hash table ou o no em memoria !!\n");
        return -1;
    }
    key = r.chave;
    pos = key%tablesize;
    ht->dt[pos] = r;
    printf("Elemento na pos: %d\n", pos);
    printPessoa(ht->dt[pos]);
    return pos;
}

int searchbydivision(hash_table *ht, int key, int tablesize){
    /* 
    * About: Calcula a posição de um determinado elemento a partir de uma chave
    * Retorno: Retorna a posição do elemento
    * Ps: Não vai funcionar se buscar por um elemento que foi inserido por outro metodo
    */
    int pos = key%tablesize;
    return pos;
}

void removebydivision(){

}