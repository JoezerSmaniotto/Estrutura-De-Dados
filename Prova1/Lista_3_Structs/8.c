#include <stdio.h>
#include <stdlib.h>

typedef struct Jogador{
	int camisa;
	int golm;
		
}jog;

typedef struct Equipe{
	int ano;
	jog jogad[5];
	
	
}Equi;


int main(){
	Equi equip;
	int i;
	printf("Informe o Ano da Equipe: ");
	scanf("%d",&equip.ano);
	for(i=0;i<5;i++){
		printf("Informe O Nº Da Camisa Do Jogador: ");
		scanf("%d",&equip.jogad[i].camisa);
		printf("Informe O Nº De Gols Do Jogador: ");
		scanf("%d",&equip.jogad[i].golm);
	}
	
	printf("Ano da Cricao: %d\n",equip.ano);
	for(i=0;i<5;i++){
		printf("Camisa do JOgador: %d\n",equip.jogad[i].camisa);
		printf("Gols Marcados do JOgador: %d\n",equip.jogad[i].golm);
	}
		
	return 0;
}

