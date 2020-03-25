#include <stdio.H>
#include <stdlib.h>
#define TAM 50

// Prototipos
int menu();
void InserirInicio();
void Listar();

// Estrutur` de dados da nova musica que sera inóerida
struct NovaMusica{
	char nome_da_musica[TAM];
	char nome_da_banda[TAM];
	float tempo_musica;
	NovaMusica* prox;
} *Head;

// Inycio da execuçãoM
// Inicio da execução
int main() {
	int op, c;
	float tempo; // armazena o tempo da musica
	char nome_musica[TAM]; // armazena o nome da musica
	char nome_banda[TAM]; // armazena o nome do cantor

	// laço infinito que retorna o menu ao final
	// de cada função
	while (1) {
		op = menu();
		switch (op) {
		case 1: // inserir no inicio da lista
			InserirInicio();
			break;
		case 2: // mostrar toda a lista
			Listar();
			break;
		case 3: // sair do programa
			return 0;
		default:
			break;
		}
	}
	return 0;
}
// Função que exibe o menu
int menu() {
	int op, c;

	system("Cls");
	printf("\n\n--------------- PLAY LIST ---------------");
	printf("\n|                                       |");
	printf("\n|       1.Inserir nova musica           |");
	printf("\n|       2.Listar todas as musicas       |");
	printf("\n|       3.sair                          |");
	printf("\n|                                       |");
	printf("\n-----------------------------------------\n");

	printf("\n|       Escolha uma opcao: ");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {}

	system("Cls");
	return op;
}

// Função para inserir a nova musica no inicio da lista
void InserirInicio() {
	NovaMusica* NovoElemento;

	// alocar o elemento na memoria
	NovoElemento = (struct NovaMusica*)malloc(sizeof(struct NovaMusica));

	printf("Digite o nome da musica: ");
	fgets(NovoElemento->nome_da_musica, TAM, stdin);
	printf("Nome do Artista/Banda: ");
	fgets(NovoElemento->nome_da_banda, TAM, stdin);
	printf("Digite o tempo de duracao[ex: 1.30]: ");
	scanf_s("%f", &NovoElemento->tempo_musica);

	// condição que verifica se a lista esta vazia
	if (Head == NULL) {
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else {
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

// Função para listar todas as faixas
void Listar() {
	NovaMusica* ElementoVarredura;
	ElementoVarredura = (struct NovaMusica*)malloc(sizeof(struct NovaMusica));

	ElementoVarredura = Head;

	// condição que verifica se a lista esta vazia
	if (ElementoVarredura == NULL) {
		return;
	}

	// Laço que imprime a lista encadeada
	while (ElementoVarredura != NULL) {
		printf("\n- Musica: %s", ElementoVarredura->nome_da_musica);
		printf("- Artista: %s", ElementoVarredura->nome_da_banda);
		printf("- Duracao: %.2f min\n", ElementoVarredura->tempo_musica);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");

	system("pause");
}