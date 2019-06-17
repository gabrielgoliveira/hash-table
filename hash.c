#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct _pessoa //144 bytes
{
    int  linha;
    char endereco[50];
    int  chave;
    char datanasc[10];
    char nome[40];
    char email[20];
    char celular[13];
} Pessoa;

typedef struct _node {
    Pessoa *p;
} Node;

node* create_hash(int n);
Pessoa parseData(char linha[]);

int main(){

}

node* create_hash(int n){
    Node *h = (Node*) malloc(sizeof(Node)*n);
    return h;
}

Pessoa parseData(char linha[]){

    Pessoa r;
    char *pt;
    pt = strtok (linha, ",");
    r.linha = atoi(pt); // numero da linha
    pt = strtok (NULL, ",");
    strncpy(r.endereco, pt, 50); // endereco
    pt = strtok (NULL, ",");
    r.chave = atoi(pt); // id
    pt = strtok (NULL, ",");
    strncpy(r.datanasc, pt, 10); // data de nascimento
    pt = strtok (NULL, ",");
    strncpy(r.nome, pt, 40); // nome
    pt = strtok (NULL, ",");
    strncpy(r.email, pt, 20); // email
    pt = strtok (NULL, ",");
    strncpy(r.celular, pt, 13); // celular
    return r;
}