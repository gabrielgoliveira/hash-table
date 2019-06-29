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



int main(){
    hash_table *teste = create_hash(10);
    strcpy(teste->table[0].p.nome, "Gabriel");
    printf("%s\n", teste->table[0].p.nome);
    printf("%p\n", teste->table[0].externa);
}