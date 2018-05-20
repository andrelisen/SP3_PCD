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
	lista=NULL;
	return lista;
}
alunos *inserirdinamica(alunos *lista)
{
	alunos *novo=(alunos*) malloc(sizeof(alunos));
	int cont=0;
		setbuf(stdin, NULL);
		printf("Nome do aluno:\n");
		scanf("%s", novo->nome);
		setbuf(stdin, NULL);
		printf("Matricula do aluno %s:\n", novo->nome);
		scanf("%d", &novo->matricula);
		setbuf(stdin, NULL);
		printf("Numero de faltas do aluno %s:\n", novo->nome);
		scanf("%d", &novo->faltas);
		setbuf(stdin, NULL);
		printf("Nota do aluno %s:\n", novo->nome);
		scanf("%f", &novo->nota);
		setbuf(stdin, NULL);
			if(lista == NULL)
			{
				novo->prox=NULL;
				printf("aqui");
				return novo;
			}
				else{
					alunos* aux=lista;
						while(aux!=NULL)
						{
							if(aux->matricula == novo->matricula)
							{
								cont++;
							}
							aux=aux->prox;
						}
							if(cont==0)
							{
								novo->prox=NULL;
								lista->prox=novo;
								printf("aqui2");
								return lista;
							}
								else{
									printf("O numero de matricula ja existe, insira um diferente\n");
								}
					}	
}
