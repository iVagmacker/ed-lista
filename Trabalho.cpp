/* Criar uma fun��o que verifique se um n�mero digitado pelo usu�rio � primo. */

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
	
	printf("Digite um n�mero: ");
	scanf("%i", &numero);
	
	resultado = primo(numero);
	
	if(resultado == 0) {
	printf("\nO n�mero %i � primo.", numero);
	} else { 
		printf("\nO n�mero %i n�o � primo.", numero);
	}
}
