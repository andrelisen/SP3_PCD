// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 03
// 21 de maio de 2018
// Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcao.h"
int main()
{
	int opc, opcinserir, qnt=0, i;
		alunos *controle;
		int *vet=(int *) malloc(sizeof(int));
		controle=cria();
		do{
			printf("--MENU--\n1)INSERIR\n2)CONSULTAR\n3)EXCLUIR\n4)EXIBIR TUDO\n5)ENCERRAR PROGRAMA\n-->DIGITE SUA OPCAO: ");
			scanf("%d", &opc);
					switch(opc)
					{
						case 1: 
									printf("Qual a maneira de insercao?\n1-Aleatorio\n2-Estático\n-->OPCAO:");
										scanf("%d", &opcinserir);
											if(opcinserir==1)
											{
												printf("Qual a quantidade de alunos para gerar automaticamente?");
													scanf("%d", &qnt);
														for(i=0;i<qnt;i++)
														{
															inseriraleatorio(controle, qnt);
														}
											}
												if(opcinserir==2)
												{
													qnt++;
												inserirdinamica(controle);
												}
						break;
						opcinserir=0;
						case 2: 
								printf("Pesquisar como\n1-binaria\n2-sequencial\n-->Opcao:");
								scanf("%d", &opcinserir);
								if(opcinserir==1)
								{
								//	pesquisabinaria(controle, qnt);
								}
									if(opcinserir==2)
									{
										pesquisasequencial(controle, qnt);
									}
						break;
						//case 3:
						//break;
						case 4: 
						exibe(controle);
						break;
				}
	}while(opc!=5);
	free(controle);
	return 0;
}


