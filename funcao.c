// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 03
// 21 de maio de 2018
//Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include <time.h>
alunos *cria()
{
	alunos *lista=(alunos*) malloc(sizeof(alunos));
	lista->prox=NULL;
	return lista;
}
void inserirdinamica(alunos *lista)
{
	alunos *novo=(alunos*) malloc(sizeof(alunos));
	int cont=0;
		printf("Nome do aluno:\n");
		scanf("%s", novo->nome);
		setbuf(stdin, NULL);
		printf("Matricula do aluno %s:\n", novo->nome);
		scanf("%d", &novo->matricula);
		printf("Numero de faltas do aluno %s:\n", novo->nome);
		scanf("%d", &novo->faltas);
		printf("Nota do aluno %s:\n", novo->nome);
		scanf("%f", &novo->nota);
			novo->prox=NULL;	
			
			if(vazia(lista)==1)
			{	
				lista->prox=novo;
			}
				else{
					alunos *aux=lista->prox;
						while(aux->prox!=NULL)
						{
							if(aux->matricula==novo->matricula)
							{
							cont++;
							}
							aux=aux->prox;
						}
							if(cont==0)
								{
								aux->prox=novo;
								}	
								else{
									printf("O numero de matricula ja existe, insira um diferente\n");
									}
					}	
}
void inseriraleatorio(alunos *lista, int i)
{	
	int j, num, cont=0;
	char *letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *nome=(char *) malloc(sizeof(char));
	srand(time(NULL));
		alunos *novo=(alunos *)malloc(sizeof(alunos));
			novo->matricula=rand()%i;
				num = 3 + (rand() % 10);
					for(j=0;j<num;j++)
					{
						nome[j]=letras[ rand() % strlen(letras)];
					}
						strcpy(novo->nome,nome);
							novo->faltas= rand() %60;
								novo->nota= (rand() % 100)/10;	
									novo->prox=NULL;	
				if(vazia(lista)==1)
				{	
					lista->prox=novo;
				}
				else{
					alunos *aux=lista->prox;
						while(aux->prox!=NULL)
						{
							if(aux->matricula==novo->matricula)
							{
							cont++;
							}
							aux=aux->prox;
						}
							if(cont==0)
								{
								aux->prox=novo;
								}	
								else{
									printf("O numero de matricula ja existe, insira um diferente\n");
									}
					}	
	}
void exibe(alunos *lista)
{
	alunos *aux=lista->prox;
		if(aux==NULL)
		{
			printf("vazio\n");
		}
		else{
		while(aux!=NULL)
		{
			printf("Nome do aluno: %s\tMatricula:%d\tNumero de faltas:%d\tNota:%f\n", aux->nome,aux->matricula, aux->faltas, aux->nota);
			aux=aux->prox;
		}
		}
}
int vazia(alunos *no)
{
	if(no->prox == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
