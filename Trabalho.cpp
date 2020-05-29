/* Criar uma função que verifique se um número digitado pelo usuário é primo. */

#include<stdio.h>
#include<math.h>
#include <locale.h>


int primo(int numero) {
	
	int contador, teste = 0;
	
	for(contador = numero - 1; contador != 1; contador--) {
		if (numero % contador == 0) {
		 teste++;
		
		}
	}
	return teste;	
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int resultado, numero;
	
	printf("Digite um número: ");
	scanf("%i", &numero);
	
	resultado = primo(numero);
	
	if(resultado == 0) {
	printf("\nO número %i é primo.", numero);
	} else { 
		printf("\nO número %i não é primo.", numero);
	}
}
