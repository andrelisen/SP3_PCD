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
	int opc, opcinserir;
		alunos *controle;
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
											//	inseriraleatorio(controle);
											}
												if(opcinserir==2)
												{
													controle = inserirdinamica(controle);
												}
													else{
														printf("Tente novamente! Opcao errada\n\n");
													}
						break;
						//case 2: 
						//break;
						//case 3:
						//break;
						//case 4: 
						//break;
				}
	}while(opc!=5);
	return 0;
}
