## Agenda

Trabalho prático realizado para a disciplina Algoritmos e Programação II no semestre 2021/1.

## Linguagem

A linguagem utilizada para o desenvolvimento do trabalho foi a C.

## Sobre o trabalho

- O tipo definido para a agenda foi o struct, composto por 4 vetores do tipo char: nome, endereço, telefone e aniversário.
- Foram desenvolvidas funções para a implementação de cada uma das funcionalidades da agenda.
- A execução do programa é interrompida quando a tecla "f" é digitada.

## Funções

- Inserção: Função que recebe a primeira posição disponível na agenda e a agenda de endereços e, assim, insere elementos na agenda.

- Remoção: Função que recebe a agenda de endereços, a posição do contato a ser removido (i) e o numero de elementos da agenda e, então, remove o elemento da agenda.

- Impressão: Função que recebe o numero de elementos da agenda e a agenda e, assim, imprime na tela os elementos da agenda.

- Busca: Função que recebe a agenda, o nome a ser buscado e o número de elementos da agenda. Em seguida, busca elementos da agenda que contenham o nome informado pelo usuário.

- Leitura: Função que recebe a agenda, o ponteiro para o arquivo e um ponteiro para o número de elementos da agenda e realiza a leitura dos elementos em um arquivo e insere-os na agenda.

- Gravação: Função que recebe a agenda, um ponteiro para o arquivo e o número de elementos da agenda e grava em um arquivo  todos os elementos da agenda.

- Impressão ordenada: Função que recebe o número de elementos da agenda e a agenda. Em seguida, imprime os elementos da agenda em ordem crescente (alfabética).

## Operações da Agenda

Ao executar o arquivo, as seguintes operações podem ser realizadas pelo usuário:

- 'f' - interrompe o programa;
- 'i' - insere elementos na agenda;
- 'r' - remove elementos da agenda;
- 'b' - busca elementos na agenda;
- 'p' - imprime os elementos da agenda na ordem que foram inseridos;
- 'o' - imprime os elementos da agenda em ordem alfabética;
- 'g' - grava os elementos da agenda em um arquivo;
- 'l' - lê os elementos de um arquivo e insere-os na agenda;

## Execução

Para a compilação, no terminal:

```
gcc -Wall -Wextra -Wpedantic -Werror -std=c11 -o agenda main.c
```
Em seguida, para a execução:

```
./agenda
```
##