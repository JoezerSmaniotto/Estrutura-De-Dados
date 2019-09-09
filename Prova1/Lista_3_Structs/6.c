#include <stdio.h>
#include <stdlib.h>

typedef struct Jogador{
	int camisa;
	int golm;
		
}jog;


int main(){
	jog jogad;
	
	printf("Informe O Nº da Camisa do Jogador: ");
	scanf("%d",&jogad.camisa);
	printf("Informe O Nº Gols do Jogador: ");
	scanf("%d",&jogad.golm);
	
	printf("Numero da Camisa do JOgador: %d\n",jogad.camisa);
	printf("Numero de Gols Marcador: %d\n",jogad.golm);
	
	
	return 0;
}

