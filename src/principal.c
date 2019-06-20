#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stc_pessoa.h"

#define QTD 1
#define MAXCHAR 200

int main(){
    FILE *fl = NULL;
    char *caminho = "dados/dados-500000-lin.csv";
    char linha[MAXCHAR];
    int i = 0;
    //variaveis de teste
    Pessoa p;
    fl = fopen(caminho, "r");
    if(fl == NULL){
        printf("Nao foi possivel abrir o arquivo %s !!\n", caminho);
        printf("Encerrando o Programa ....\n");
        return 0;
    }
    //essa linha vai ler o cabeçalho, para que a iteração desconsidere ele como um dado valido
    fgets(linha, sizeof(linha), fl);
    
    while(i<QTD && fgets(linha, sizeof(linha), fl)){
        p = parseData(linha);
        printf("Nasc: %s\n", p.datanasc);
        i++;
    }

    fclose(fl);
    return 0;
 
}

