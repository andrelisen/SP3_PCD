// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 03
// 21 de maio de 2018
// Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).
struct ALUNOS{
	int matricula;
	char nome[40];
	int faltas;
	float nota;
	struct ALUNOS *prox;
};typedef struct ALUNOS alunos;
alunos *cria();
alunos *inserirdinamica(alunos *lista);
alunos *inseriraleatorio(alunos *lista);
void escolher_pesquisa();

