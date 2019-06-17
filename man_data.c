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
int metodo_divisao(int x);

int main(){
    int i = 0, pos;
    FILE *p = NULL;
    char linha[200];
    Pessoa hash[N];
    Pessoa temp;
    //abrindo o arquivo
    p =  fopen("dados/dados-500000-lin.csv", "r");
    
    //verificando se foi aberto
    if(p == NULL){
        return 0;
    }
    //essa linha vai ler o cabeçalho, para que a iteração desconsidere ele como um dado valido
    fgets(linha, sizeof(linha), p);

    //lendo os dados
    while(i<1){
        fgets(linha, sizeof(linha), p);
        printf("%s\n", linha);
        
        temp = parseData(linha);
        printf("Nome: %s\n", temp.nome);
        printf("id: %d\n", temp.linha);
        //pos = metodo_divisao(temp.chave);
        printf("posição no array: %d\n", pos);
        i++;
    }

    fclose(p);
    return 0;
 
}

int metodo_divisao(int x){
    return x%N;
}

Pessoa parseData(char linha[]){
    //ID NÃO ESTÁ FUNCIONANDO
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
    printf("FUNCAO:\nid: %d\n", r.chave);
    return r;
}