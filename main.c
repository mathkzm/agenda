#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

/* Tipo definido para a agenda */

typedef struct
{
	char nome[50+1];
	char end[100+1];
	char tel[12+1];
	char aniv[8+1];
}agenda;

/* Função que recebe a primeira posição disponível na agenda e a agenda de endereços e insere elementos na agenda */

void insercao(int i, agenda agenda_end[MAX])
{
	scanf("%s",agenda_end[i].nome);
	scanf("%s",agenda_end[i].end);
	scanf("%s",agenda_end[i].tel);
	scanf("%s",agenda_end[i].aniv);
}

/* Função que recebe a agenda de endereços, a posição do contato a ser removido (i) e o numero de elementos
   da agenda e remove o elemento da agenda */

void remocao(agenda agenda_end[MAX], int i, int indice)
{
	int j;

	for(j = i; j<indice; j++)
	{
		agenda_end[j] = agenda_end[j+1];
	}
}

/* Função que recebe o numero de elementos da agenda e a agenda e imprime os elementos da agenda */

void impressao(int indice, agenda agenda_end[MAX])
{
	int i;

	printf("Listagem:\n");

	if (indice > 0)
	{
		for(i = 0; i < indice; i++)
		{	
			printf("%d- %s\n", i+1,agenda_end[i].nome);
			printf("%s\n", agenda_end[i].end);
			printf("%s\n", agenda_end[i].tel);
			printf("%s\n", agenda_end[i].aniv);

			printf("\n");
		}
	}
	else
		printf("Nenhum registro.\n\n");
}

/* Função que recebe a agenda, recebe o nome a ser buscado e o número de elementos da agenda. Em seguida, busca elementos
   da agenda que contenham o nome informado pelo usuário */

void busca(agenda agenda_end[MAX], char nome_aux[50+1], int indice)
{
	char *ponteiro_auxiliar;
	int i, qnt_itens = 0;

	printf("Resultado da busca:\n");

	for(i=0; i<indice; i++)
	{
		ponteiro_auxiliar = strstr(agenda_end[i].nome, nome_aux);

		if (ponteiro_auxiliar != NULL)
		{
			printf("%d- %s\n", i+1,agenda_end[i].nome);
			printf("%s\n", agenda_end[i].end);
			printf("%s\n", agenda_end[i].tel);
			printf("%s\n", agenda_end[i].aniv);

			printf("\n");

			qnt_itens++;
		}
	}
	if (qnt_itens == 0)
		printf("Nenhum registro.\n\n");
}

/* Função que recebe a agenda, o ponteiro para o arquivo e um ponteiro para o número de elementos da agenda
   e realiza a leitura dos elementos em um arquivo e os coloca na agenda */

void leitura(agenda agenda_end[MAX], FILE *arquivo, int *i)
{
	int val;
	
	val = fscanf(arquivo,"%s %s %s %s", agenda_end[*i].nome,agenda_end[*i].end,agenda_end[*i].tel,agenda_end[*i].aniv);
	*i = *i+1;

	while (val != EOF && *i != MAX)
	{
		val = fscanf(arquivo,"%s %s %s %s", agenda_end[*i].nome,agenda_end[*i].end,agenda_end[*i].tel,agenda_end[*i].aniv);
			
		if (val != EOF)
			*i = *i+1;
	}

	fclose(arquivo);
}

/* Função que recebe a agenda, um ponteiro para o arquivo e o número de elementos da agenda e grava em um arquivo 
   todos os elementos da agenda */

void gravacao(agenda agenda_end[MAX], FILE *arquivo, int indice)
{
	int i;
	
	if(arquivo != NULL)
	{
		for(i=0; i<indice; i++)
			fprintf(arquivo,"%s\n%s\n%s\n%s\n\n", agenda_end[i].nome,agenda_end[i].end,agenda_end[i].tel,agenda_end[i].aniv);

		fclose(arquivo);
	}

	else 
		printf("Impossivel abrir o arquivo para escrita\n\n");
}

/* Função que recebe o número de elementos da agenda e a agenda. Em seguida, imprime os elementos da agenda em ordem crescente 
   (alfabética) */

void impressao_o(int indice, agenda agenda_end[MAX])
{
	int i, j, comparador, num_contatos;
	agenda agenda_ord[MAX];
	agenda auxiliar;

	num_contatos = indice;

	for(i=0; i<indice; i++)
	{
		agenda_ord[i] = agenda_end[i];
	}
	
	for(i=0; i<indice-1;i++)
	{
		for(j=i+1; j<indice;j++)
		{
			comparador = strcmp(agenda_ord[i].nome,agenda_ord[j].nome);

			if(comparador>0)
			{
				auxiliar = agenda_ord[i];
				agenda_ord[i] = agenda_ord[j];
				agenda_ord[j] = auxiliar;
			}
		}
	}
	impressao(num_contatos,agenda_ord);
}

int main(void)
{
	agenda agenda_enderecos[MAX]; 

	char operacao, nome_aux[50+1];
	char nome_arquivo[50];
	int indice = 0;
	int qtd_removidos, i;
	
	FILE *arquivo;

	scanf("%c", &operacao);

	while(operacao != 'f') /* O programa para quando o comando de operação for "f" */
	{

		switch(operacao)
		{
			case 'i': /* i: insere elementos na agenda */

				if(indice < 1000)
				{
					insercao(indice,agenda_enderecos);
					indice++;
					printf("Registro inserido.\n\n");
				}
				else
					printf("Lista cheia!\n\n");

				break;

			case 'r': /* r: remove elementos da agenda */

				scanf("%s", nome_aux);

				qtd_removidos = 0;

				for (i = indice-1; i >= 0; i--)
				{
					if (strcmp(nome_aux,agenda_enderecos[i].nome) == 0)
					{
						remocao(agenda_enderecos,i,indice);
						indice--;
						qtd_removidos++;
					}
				}

				printf("%d registros removidos.\n\n", qtd_removidos);

				break;

			case 'b': /* b: busca elementos na agenda. */

				scanf("%s", nome_aux);

				busca(agenda_enderecos,nome_aux,indice);

				break;

			case 'p': /* p: imprime os elementos da agenda na ordem que foram inseridos */

				impressao(indice,agenda_enderecos);

				break;

			case 'o': /* o: imprime os elementos da agenda em ordem alfabética */

				impressao_o(indice,agenda_enderecos);
				
				break;

			case 'g': /* g: grava os elementos da agenda em um arquivo */

				scanf("%s",nome_arquivo);
				arquivo = fopen(nome_arquivo,"w");

				gravacao(agenda_enderecos,arquivo,indice);

				printf("Arquivo %s gravado.\n\n",nome_arquivo);

				break;

			case 'l': /* l: lê os elementos de um arquivo e os insere na agenda */

				scanf("%s",nome_arquivo);
				arquivo = fopen(nome_arquivo,"r");

				if(arquivo != NULL)
				{
					leitura(agenda_enderecos,arquivo,&indice);
					printf("Arquivo %s lido.\n\n",nome_arquivo);
				}
				
				else 
					printf("Impossivel abrir o arquivo para leitura.\n\n");

				break;
		}
		scanf("%c", &operacao);
	}
	return 0;	
}
