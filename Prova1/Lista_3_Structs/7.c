#include <stdio.h>
#include <stdlib.h>

typedef struct Jogador{
	int camisa;
	int golm;
		
}jog;


jog lejogador (){
	jog jogad;
	
	printf("Informe O Nº da Camisa do Jogador: ");
	scanf("%d",&jogad.camisa);
	printf("Informe O Nº Gols do Jogador: ");
	scanf("%d",&jogad.golm);
	
	return jogad;
}

int ehgoleador(jog joga){
	if(joga.golm >5){
		return  1;
	}else {
		return  0;
	}	
}

void escreveJogador(jog jogad){
	printf("Numero da Camisa do JOgador: %d\n",jogad.camisa);
	printf("Numero de Gols Marcador: %d\n",jogad.golm);
}

int main(){
	jog jogAdor;
	int goleadorr;
	jogAdor = lejogador();	
	goleadorr = ehgoleador(jogAdor);
	if(goleadorr==1){
		printf("Goleador!!\n");
	}
	escreveJogador(jogAdor);
	
	
	return 0;
}

