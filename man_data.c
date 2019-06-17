#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Pessoa parseData(char linha[]);

int main(){
    int i = 0;
    FILE *p = NULL;
    char linha[200];
    Pessoa hash[N];

    //abrindo o arquivo
    p =  fopen("dados/dados-500000-lin.csv", "r");
    
    //verificando se foi aberto
    if(p == NULL){
        return ;
    }
    //essa linha vai ler o cabeçalho, para que a iteração desconsidere ele como um dado valido
    fgets(linha, sizeof(linha), p);

    //lendo os dados
    while(i<N){
        fgets(linha, sizeof(linha), p);
        hash[i] = parseData(linha);
        i++;
    }

/* 
    for(int j = 0; j<i; j++){
        printf("pos: %d - %s\n",j,  hash[j].nome);
    }
*/
    fclose(p);
 
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