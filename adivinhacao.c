#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");
    
    int segundos = time(0);
	srand(segundos);
	
	int numerogrande = rand();
	
    int numerosecreto = numerogrande % 100; //resto da divisão é feito pela porcentagem
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    
    int acertou = 0;
	
	int nivel;
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil\n(2) Médio\n(3) Difícil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);
	
	int numerodetentativas ;
	
	switch(nivel){
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 15;
			break;
		default:
			numerodetentativas = 6;	
	}
	printf("%d", numerosecreto);
	int i;
    for ( i = 1; i <= numerodetentativas; i++) {

        printf("\nTentativa %d\n", tentativas);
        printf("---Qual é o seu chute?---\n "); 
        scanf("%d", &chute);
        printf("\nSeu chute foi %d\n", chute);

        if(chute < 0) {
            printf("\nVocê não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou) {
            break;
        }
        else if(maior) {
            printf("\nSeu chute foi maior que o número secreto\n");
        } 
        else {
            printf("\nSeu chute foi menor que o número secreto\n");
        }
        tentativas++;
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("\nFim de jogo!\n");
    if(acertou){
    	printf("\n\n");
    	printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
        
    	printf("Você ganhou!\n");
    	printf("\nVocê acertou em %d tentativas!\n", tentativas);
   	    printf("\nTotal de pontos: %.1f\n", pontos);
	}else{
		printf("Você perdeu! Tente de novo!\n");
		printf("\n\n");
		printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
		printf("\n\n");
	}
    
    
}
