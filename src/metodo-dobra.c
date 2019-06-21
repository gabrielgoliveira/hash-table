#include <stdio.h>
#include <stdlib.h>

int parseInt(int *n, int tam);
int[] parseVector(int n);

int main(){
    int dobra[10];
    int n = 1374;
    int temp = 0;
    int temp_cont, cont;

    cont = 0;
   
    dobra = parseVector(1374);
    printf("Endereco do vetor da funcao Principal: %p\n", &dobra);   
    temp_cont = cont/2;
    for(int i = 0; i<temp_cont; i++){
        temp = dobra[i] + dobra[cont-1];
        if(temp >= 10){
            temp = temp%10;
        }
        printf("TEMP: %d\n", temp);
        cont--;
    }
    return 0;
}

int parseInt(int *n, int tam){
    //recebe o vetor com os numeros em ordem inversa
    int num = 0;
    int dec = 1;
    for(int i = 0; i<tam; i++){
        num += n[i]*dec;
        dec*=10;
    }
    return num;
}

int* parseVector(int n){
    //so funciona com numeros de até 8 digitos
    int dobra[8];
    int cont = 0;
    while(n != 0 && cont<= 8){
        dobra[cont] = n%10;
        n = n/10;
        cont++;
    }
    printf("Endereco do vetor da funcao: %p\n", &dobra);
    return dobra;
}
