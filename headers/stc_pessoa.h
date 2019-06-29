typedef struct _pessoa //144 bytes
{
    int  linha;
    char endereco[50];
    int  chave;
    char datanasc[25];
    char nome[40];
    char email[20];
    char celular[13];
} Pessoa;

void printPessoa(Pessoa p){
    printf("Linha: %d, Chave: %d\nNome: %s\n", p.linha, p.chave, p.nome);
    printf("Endereco: %s\nData de Nasc: %s, Email: %s, Celular: %s\n\n", p.endereco, p.datanasc, p.email, p.celular );
    
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
    strncpy(r.datanasc, pt, 25); // data de nascimento
    pt = strtok (NULL, ",");
    strncpy(r.nome, pt, 40); // nome
    pt = strtok (NULL, ",");
    strncpy(r.email, pt, 20); // email
    pt = strtok (NULL, ",");
    strncpy(r.celular, pt, 13); // celular
    return r;
}