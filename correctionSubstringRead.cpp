#include <stdio.h>

int main() {
	char texto[101] = {};
	int n = 0;
	int caractere = 0;
	int contador = 0;
	int posini = 0;
	int j=0;
	
	printf("Digite um texto: \n");
	gets(texto);	// l� a string com espa�os (scanf n�o armazena espa�os)
	printf("\nDigite um numero inteiro positivo: \n\n"); //L� um nro que ser� o tamanho da substring
	scanf("%d", &n);
	for (caractere=0; texto[caractere]!='\0'; caractere++) {
		//Leitura dos caracteres da string \0 Fim da string
		if (texto[caractere] == ' ') {
				if (contador>=n) {
					for (j=posini; j<caractere; j++) printf("%c", texto[j]);
					printf("\n");
					// contador=-1; <-- ERRO: reinicializa contador apenas se for maior ou igual a n em vez de reinicializar sempre que h� uma nova substring (' ' - espa�o)
				}
			contador=-1; 		//  <-- SOLU��O: reinicializar o contador sempre que h� uma nova substring
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
