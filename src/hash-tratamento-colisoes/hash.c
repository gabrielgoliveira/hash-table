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
void insert_ht(hash_table *ht, Pessoa p){
    int pos = hashing(p.chave, ht->table_size);
    if(ht == NULL){
        return ;
    }
    if(ht->table == NULL){
        return ;
    }
    if(ht->table[pos].p.chave == -1){
        //posicao vazia
        ht->table[pos].p = p;
    } else {
        printf("\nCOLISAO\n");
        //inserir na lista externa
        if(ht->table[pos].externa == NULL){
            //Lista não existe
            ht->table[pos].externa = create_list();
            insert(ht->table[pos].externa, p);
        } else {
            insert(ht->table[pos].externa, p);
        }
    }
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
    hash_table *teste = create_hash(10);
    Pessoa temp;
    temp.chave = 10;
    strcpy(temp.nome, "Gabriel");
    insert_ht(teste, temp);
    temp.chave = 20;
    strcpy(temp.nome, "Maria Karla");
    insert_ht(teste, temp);
    temp.chave = 33;
    strcpy(temp.nome, "Renato");
    insert_ht(teste, temp);
    temp.chave = 43;
    strcpy(temp.nome, "Cleide");
    insert_ht(teste, temp);
    print_ht(teste);
}