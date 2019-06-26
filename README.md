# AED2 - Algoritmos e Estrutura de Dados 2

# Descrição do Trabalho Trabalho 1

Neste trabalho serão realizados alguns experimentos com tabelas Hash. As tabelas hash construídas deverão conter funções de:
* Inserção;
* Busca e
* Remoção.

Para isto, está disponibilizado um arquivo texto, no formato csv, com 500 mil linhas.

## Definição do trabalho

Neste trabalho será usado somente as primeiras **10.000** linhas.

O trabalho consistirá das seguintes etapas:

1. Construir um hash ideal (Sem tratamento de colisões) e calcular o total de colisões por posição conforme a seguir:
    * Usar o método da divisão considerando o tamanho padrão da tabela;
    * Usar uma tabela de tamanho baseado em número primo e usar o método da divisão;
    * Usar o método da dobra;
    * Usar o método da multiplicação simples;
    * Usar o método da multiplicação considerand o quadrado da chave.
2. Construir um hash com tratamento de colisões:
    * Usar o método de encadeamento externo em que o 1o registro é considerado na tabela;
    * Usar o método de encadeamento externo em que o nenhum registro é considerado na tabela;
    * Usar o método de zona de colisão.

Para a parte 2 pode ser considerada a função hashing da sua preferência, ou aquela que oferecer a menor taxa de colisões.
Na parte 2 deverá ser feita uma simulação de busca aleatória de um total de 1000 chaves, considerando as 10.000 chaves inseridas e chaves aleatórias não existentes, para ser obter a quantidade média de operações para se obter o registro desejado. Os registros inexistentes, obviamente, não serão encontrados na busca, mas terão seu tempo de busca computado.

## Artefatos

Ao final deste trabalho deverá ser enviado:
* Todos os códigos fontes utilizados. Sugiro usar um programa para cada caso descrito na seção de definição.
* Relatório dos experimentos. Deverá conter:
    * Membros do grupo que desenvolveu o trabalho;
    * Introdução com explicações fundamentadas sobre tabela hash e seus componentes;
    * Descrição dos métodos utilizados;
    * Resultados experimentais;
    * Conclusões ou Considerações finais e
    * Referências.

Será avaliado o código com comentários, clareza e grau de detalhamento do relatório e coerência dos resultados obtidos com experados pelo professor, bem como com as conclusões.

A submissão deverá ser feita via moodle em link a ser disponibilizado em breve. Os grupos poderão ter até **3 integrantes**.

## Instruções

Cada linha do arquivo representa um registro de uma pessoa com os campos a seguir na seguinte ordem:

* Numero da linha
* Address
* id (**Campo chave**)
* Birth Date
* Name
* Email Address
* Phone Number

Para efetuar a leitura do arquivo, deverá ser usadas as funções de abertura (fopen), leitura (fgets) e fechamento (fclose).
