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
int vazia(alunos *no);
void inserirdinamica(alunos *lista);
void inseriraleatorio(alunos *lista, int i);
void escolher_pesquisa();
void exibe(alunos *lista);
alunos* pesquisabinaria(alunos *lista, int qnt);
void pesquisasequencial(alunos *lista, int qnt);
void ordena(alunos *lista);
void excluir(alunos *lista, int qnt);
