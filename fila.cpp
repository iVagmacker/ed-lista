#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

typedef struct node Node;

struct node {
	int pid;
	char nome[30];
	Node *proximo;
};

Node *inicioFilaComum;
Node *finalFilaComum;
Node *inicioFilaPreferencial;
Node *finalFilaPreferencial;

Node *alocarNovoNode(int valor, char nome[30]);

void menu();

void criarFilaComum();

void criarFilaPreferencial();

int filaVaziaComum();

int filaVaziaPreferencial();

void inserirComum(int valor, char nome[30]);

void inserirPreferencial(int valor, char nome[30]);

void finalizarProcessoPreferencial();

void finalizarProcessoComum();

void imprimirComum();

void imprimirPreferencial();

int main() {

	int opcao;
	int fila;
	int pid;
	char nome[30];

	setlocale(LC_ALL, "Portuguese");
	
	menu();
	scanf("\n%d", &opcao);
	system("cls");
	
	criarFilaComum();
	criarFilaPreferencial();
	
	do {
		nome[30] = NULL;
		switch (opcao) {
			case 1: 
				printf("\n1 - Fila comum.");
				printf("\n2 - Fila preferencial.\n");
				scanf("%d", &fila);
				if (fila == 1) {
					
					printf("\nDigite o PID: ");
					scanf("%d", &pid);
					printf("\nDigite o nome do processo: ");
					scanf("%s", &nome);
					inserirComum(pid, nome);
					
					system("cls");	
				} else if (fila == 2) {				
					
					printf("\nDigite o PID: ");
					scanf("%d", &pid);
					printf("\nDigite o nome do processo: ");
					scanf("%s", &nome);
					inserirPreferencial(pid, nome);
					
					system("cls");
				}
				system("cls");
			break;
			case 2: if(!filaVaziaPreferencial()) {
				finalizarProcessoPreferencial();
				inserirComum(pid, nome);		
			} else {
				finalizarProcessoComum();	
			}
			break;
			case 3:
				printf("\n---- Fila Comum ----");
				imprimirComum();
				printf("\n---- Fila Preferencial ----");
				imprimirPreferencial();
			break;
			default: exit(0);
		}
		menu();
		scanf("%d", &opcao);
	} while (opcao < 4);
}

void criarFilaComum() {
	inicioFilaComum = NULL;
	finalFilaComum = NULL;
}

void criarFilaPreferencial() {
	inicioFilaPreferencial = NULL;
	finalFilaPreferencial = NULL;
}

void menu() {
	printf("---- MENU ----");
	printf("\n1 - Inserir dados na fila.");
	printf("\n2 - Finalizar processo.");
	printf("\n3 - Imprimir a lista.");
	printf("\n4 - Sair.\n");
}

int filaVaziaComum() {
	if (inicioFilaComum == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int filaVaziaPreferencial() {
	if (inicioFilaPreferencial == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void inserirComum(int valor, char nome[30]) {
	
	Node *novo = alocarNovoNode(valor, nome);
	
	if (filaVaziaComum()) {
		inicioFilaComum = novo;
		finalFilaComum = novo;
	} else {
		finalFilaComum->proximo = novo;
		finalFilaComum = novo;
	}
}

void inserirPreferencial(int valor, char nome[30]) {
	
	Node *novo = alocarNovoNode(valor, nome);
	
	if (filaVaziaPreferencial()) {
		inicioFilaPreferencial = novo;
		finalFilaPreferencial = novo;
	} else {
		finalFilaPreferencial->proximo = novo;
		finalFilaPreferencial = novo;
	}
}

void finalizarProcessoPreferencial() {
	if(filaVaziaPreferencial()) {
		printf("\nImpossível remover. A fila está vazia!\n\n");
	} else {
		Node *dado = inicioFilaPreferencial;
		
		inicioFilaPreferencial = dado->proximo;
		free(dado);
	}
}

void finalizarProcessoComum() {
	if(filaVaziaComum()) {
		printf("\nImpossível remover. A fila está vazia!\n\n");
	} else {
		Node *dado = inicioFilaComum;
		
		inicioFilaComum = dado->proximo;
		free(dado);
	}
}

void imprimirComum() {
	
	Node *atual = inicioFilaComum;
	
	if(filaVaziaComum() ) {
		
		printf("\nA fila está vazia!\n\n");
		} else {
			while (atual != NULL) {
			
			printf("\nValor: %d\n", atual->pid);
			printf("\nNome do processo: %s\n", atual->nome);
			atual = atual->proximo;
		}
	}
}

void imprimirPreferencial() {
	
	Node *atual = inicioFilaPreferencial;
	
	if(filaVaziaPreferencial() ) {
	
		printf("\nA fila está vazia!\n\n");
		} else {
			while (atual != NULL) {
				
			printf("\nValor: %d\n", atual->pid);
			printf("\nNome do processo: %s\n", atual->nome);
			atual = atual->proximo;
		}
	}
}

Node *alocarNovoNode(int valor, char nome[30]) {
	Node *novo =  (Node *) malloc(sizeof(Node));
	novo->pid = valor;
	novo->nome[30] = nome[30];
	novo->proximo = NULL;
	
	return novo;
}








