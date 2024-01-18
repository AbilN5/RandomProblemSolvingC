#include <stdio.h>

int main() {
	char texto[101] = {};
	int n = 0;
	int caractere = 0;
	int contador = 0;
	int posini = 0;
	int j=0;
	
	printf("Digite um texto: \n");
	gets(texto);	// lê a string com espaços (scanf não armazena espaços)
	printf("\nDigite um numero inteiro positivo: \n\n"); //Lê um nro que será o tamanho da substring
	scanf("%d", &n);
	for (caractere=0; texto[caractere]!='\0'; caractere++) {
		//Leitura dos caracteres da string \0 Fim da string
		if (texto[caractere] == ' ') {
				if (contador>=n) {
					for (j=posini; j<caractere; j++) printf("%c", texto[j]);
					printf("\n");
					// contador=-1; <-- ERRO: reinicializa contador apenas se for maior ou igual a n em vez de reinicializar sempre que há uma nova substring (' ' - espaço)
				}
			contador=-1; 		//  <-- SOLUÇÃO: reinicializar o contador sempre que há uma nova substring
			posini=caractere+1;
		}
		contador++;
	}
	if (contador>=n) {
		for (j=posini; j<caractere;j++) printf("%c",
		texto[j]);
		printf("\n");
	}
}
