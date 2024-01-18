#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

int main(){
	//Inicializa��o
	setlocale(LC_ALL, "");
	
	int contador, conta_aprov, conta_rec, conta_invalidos, alunos;
	float nota1, nota2, media, media_geral, menor_media, maior_media, soma;
	char lixo[100];
	bool primeiro_valido = true;
	conta_aprov = conta_rec = soma = conta_invalidos = 0;
	
	//Entrada quantidade de alunos
	printf("Insira a quantidade de alunos avaliados: ");
	while (1) {
		if (scanf(" %i", &alunos) == 1) {
			if (alunos < 1) {
			printf("ERRO: Entrada inv�lida\nInsira a quantidade de alunos avaliados: ");
			continue;
			} 
			break;
		} else {
			scanf("%s", lixo);
			printf("ERRO: Entrada inv�lida\nInsira a quantidade de alunos avaliados: ");
		}	
	}
	
	for(contador = 0; contador < alunos; contador++) { 
		//entrada/valida��o notas
		printf("Digite a nota 1: \n");
		if (scanf(" %f", &nota1) != 1) {
			scanf("%s", lixo);
			conta_invalidos++;
			printf("ERRO: Entrada inv�lida\nSeguindo para o pr�ximo aluno...\n---------------------------\n");
			continue; 		//for�a uma nova itera��o e incrementa a vari�vel de controle
			
		}
		printf("Digite a nota 2: \n");
		if (scanf(" %f", &nota2) != 1) {
			scanf("%s", lixo);
			conta_invalidos++;
			printf("ERRO: Entrada inv�lida\nSeguindo para o pr�ximo aluno...\n---------------------------\n");
			continue; 		//for�a uma nova itera��o e incrementa a vari�vel de controle
		}
		
		if (nota1 == 0 || nota2 ==0 || nota1 > 10 || nota2 >10) {
			conta_invalidos++;
			printf("ERRO: Entrada inv�lida\nSeguindo para o pr�ximo aluno...\n---------------------------\n");
			continue; 		//for�a uma nova itera��o e incrementa a vari�vel de controle
		}
		
		//atualizar menor/maior media
		media = (float)(nota1+nota2*2.0)/3.0;
		if (primeiro_valido == true) {
			menor_media = maior_media = media;
			primeiro_valido = false;
		} else {
			menor_media = (media < menor_media) ? media : menor_media;
			maior_media = (media > maior_media) ? media : maior_media;
		}
		
		//somar media ao total e determinar aprova��o
		printf("M�dia: %.2f\n", media);
		soma+=media;
		(media>6.0) ? conta_aprov++ : conta_rec++;
		
		printf("---------------------------\n");
	}
	
	media_geral = soma/(contador - conta_invalidos); //desconta as notas invalidas
	printf("Nro de alunos aprovados: %d\n", conta_aprov);
	printf("Nro de alunos reprovados: %d\n", conta_rec);
	printf("M�dia geral da turma: %.2f\n", media_geral);
	printf("Menor m�dia: %.2f\n", menor_media); 
	printf("Maior media: %.2f\n", maior_media);
}
