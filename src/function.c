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

int dobra_v2(){
    /*Essa função obtem valores diferentes da primeira caso o valor procurado
    não seja o minimo possivel, 0 - 9 */
    int n = 12345678;
    int chave;

    chave = n%10;
    while(n != 0){
        n = n/10;
        chave += n%10;
        chave = chave%10;
        if(chave < MAXSIZE){
            return chave;
        }
    }
    return chave;
}
int dobra(int n){
     int chave[10];
     int cont, cont_temp, flag;
    //colocando n em um vetor
    cont=0;
    while(n != 0){
        chave[cont] = n%10;
        n = n/10;
        cont++;
    }
    //dobra
    cont_temp = cont-1;
    for(int i = 0; i<cont/2; i++){
        chave[i] = (chave[i] + chave[cont_temp])%10;
        cont_temp--;
    }
    //setando novo tamanho ao vetor
    cont = cont/2;
    //convertendo vetor para um numero
    flag = parseInt(chave, cont);
    //verificando se a chave obtida eh a desejada
    if(flag > MAXSIZE){
        dobra(flag);
    } else {
        return flag;
    }
}