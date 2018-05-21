// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 03
// 21 de maio de 2018
//Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include <time.h>

alunos *cria() {
    alunos *lista = (alunos*) malloc(sizeof (alunos));
    lista->prox = NULL;
    return lista;
}

void inserirdinamica(alunos *lista) {
    alunos *atual, *anterior;
    alunos *novo = (alunos*) malloc(sizeof (alunos));
    int cont = 0;
    printf("Nome do aluno:\n");
    scanf("%s", novo->nome);
    setbuf(stdin, NULL);
    printf("Matricula do aluno %s:\n", novo->nome);
    scanf("%d", &novo->matricula);
    printf("Numero de faltas do aluno %s:\n", novo->nome);
    scanf("%d", &novo->faltas);
    printf("Nota do aluno %s:\n", novo->nome);
    scanf("%f", &novo->nota);
    novo->prox = NULL;
    atual = lista;
    anterior = NULL;
    if (vazia(atual) == 1) {
        novo->prox = NULL;
        lista->prox = novo;
    }
    else {
        while (atual != NULL && atual->matricula <= novo->matricula) {
            if (atual->matricula == novo->matricula) {
                cont++;
            }
            anterior = atual;
            atual = atual->prox;
        }
        if (cont == 0) {
            novo->prox = atual;
            if (anterior == NULL) {
                lista->prox = novo;
            }
            else {
                anterior->prox = novo;
            }
        } else {
            printf("ERRO! Numeros de matricula iguais\n");
        }
    }
}

void inseriraleatorio(alunos *lista, int quantidade) {
    alunos *atual, *anterior;
    int j, num, cont = 0, i;
    char *letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *nome = (char *) malloc(sizeof (char));
    srand(time(NULL));
    for (i = 0; i < quantidade; i++) {
        alunos *novo = (alunos *) malloc(sizeof (alunos));
        novo->matricula = i + 1;
        //printf("Valor de quantidade=%d e valor de matricula aleatorio =%d\n", i, novo->matricula);
        num = 3 + (rand() % 10);
        for (j = 0; j < num; j++) {
            nome[j] = letras[ rand() % strlen(letras)];
        }
        strcpy(novo->nome, nome);
        novo->faltas = rand() % 60;
        novo->nota = (rand() % 100) / 10;
        atual = lista;
        anterior = NULL;
        if (vazia(atual) == 1) {
            novo->prox = NULL;
            lista->prox = novo;
        }
        else {
            while (atual != NULL && atual->matricula <= novo->matricula) {
                if (atual->matricula == novo->matricula) {
                    cont++;
                }
                anterior = atual;
                atual = atual->prox;
            }
            if (cont == 0) {
                novo->prox = atual;
                if (anterior == NULL) {
                    lista->prox = novo;
                }
                else {
                    anterior->prox = novo;
                }
            } else {
                printf("ERRO! Numeros de matricula iguais\n");
            }
        }
    }
}

void exibe(alunos *lista) {
    alunos *aux = lista->prox;
    if (aux == NULL) {
        printf("vazio\n");
    } else {
        while (aux != NULL) {
            printf("Nome do aluno: %s\tMatricula:%d\tNumero de faltas:%d\tNota:%.2f\n", aux->nome, aux->matricula, aux->faltas, aux->nota);
            aux = aux->prox;
        }
    }
}

int vazia(alunos *no) {
    if (no->prox == NULL) {
        return 1;
    } else {
        return 0;
    }
}


alunos* pesquisabinaria(alunos *lista, int qnt) {
    alunos *aux = lista;
    alunos *a = lista;
    int valor, matricula = 0, inicio = 0, meio = 0, fim = (qnt - 1), ok = 0, x = 0;
    printf("Digite a matricula: ");
    scanf("%d", &valor);
    while (inicio <= fim) {
        //percorre a lista até achar o aluno do meio
        meio = (inicio + fim) / 2;
        x = 0;
        a = lista;
        while (x != meio) {
            a = a->prox;
            x++;
        }
        matricula = a->matricula; //pega a matricula


        if (valor == matricula) { //se for igual ao meio, exibe e encerra a busca
            printf("--Registro encontrado-- \n");
            printf("Nome do aluno: %s\tNumero de faltas: %d\tNota: %2.f\n", a->nome, a->faltas, a->nota);
            ok = 1;
            break;
        } else if (valor < matricula) { ///se for menor, limita a busca a primeira metade
            fim = meio - 1;
        } else { //se for maior, limita a busca a segunda metade
            inicio = meio + 1;
        }
        aux = aux->prox;
    }
    if (ok == 0) {
        printf("REGISTRO NAO ENCONTRADO");
        matricula = 999999;
    }
    return a;
}

void pesquisasequencial(alunos *lista, int qnt) {
    alunos *aux = lista;
    int valor, cont = 0, i, count = 0;
    setbuf(stdin, NULL);
    printf("Digite a matricula :");
    scanf("%d", &valor);
    while (aux != NULL) {
        cont++;
        if (aux->matricula == valor) {
            count++;
            printf("--Registro encontrado-- \n");
            printf("Nome:%s\tNota:%2.f\tNumero de faltas:%d\n", aux->nome, aux->nota, aux->faltas);
        }
        aux = aux->prox;
    }
    if (count == 0) {
        printf("REGISTRO NAO ENCONTRADO");
    }
    printf("Quantidade de registros visitados: %d\n", cont);
}

void excluir(alunos *lista, int qnt) {
    alunos *a, *anterior;
    int r = 0;
    a = pesquisabinaria(lista, qnt);
    if (a != NULL) {
        printf("Tem certeza que quer excluir esse aluno?\n Não(0)\n Sim(1)\n Opcao: ");
        scanf("%i", &r);
        if (r == 0) {
            return;
        } else {
            //percorre a lista até achar o aluno anterior ao aluno a ser excluido
            do {
                anterior = anterior->prox;
            } while (anterior->prox != a);
            anterior->prox = a->prox;//o anterior passa a apontar para o proximo do aluno a ser excluido
            free(a); 
            printf("Aluno excluido com sucesso!");
        }
    }
}