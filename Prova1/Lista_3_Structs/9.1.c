#include <stdio.h>
#include <stdlib.h>
// Structs
typedef struct Jogador{
	int camisa;
	int golm;
		
}jog;

typedef struct Equipe{
	int ano;
	jog jogad[5];
	
	
}Equi;
// Funções
jog lejogador (){
	jog jogad;
	
	printf("Informe O Nº da Camisa do Jogador: ");
	scanf("%d",&jogad.camisa);
	printf("Informe O Nº Gols do Jogador: ");
	scanf("%d",&jogad.golm);
	
	return jogad;
}

void leEquipe( Equi *equip){
	int i;
	printf("Informe o Ano da Equipe: ");
	scanf("%d",&equip->ano);
	for(i=0;i<5;i++){
		equip->jogad[i] = lejogador();
		/*printf("Informe O Nº Da Camisa Do Jogador: ");
		scanf("%d",&equip->jogad[i].camisa);
		printf("Informe O Nº De Gols Do Jogador: ");
		scanf("%d",&equip->jogad[i].golm);*/
	}
	
}

void marcouGol(int num, Equi *equi){
	 int i;
	 for(i=0;i<5;i++){
		 if(num==equi->jogad[i].camisa){ // Encontra a Camiseta
			 printf("Informe a Quantidade Atual de Gols:");  // Altera a QT de Gols da Camiseta
			 scanf("%d",&equi->jogad[i].golm);
			 printf("Oi GOLS: %d\n",equi->jogad[4].golm); // Como printar o conteudo de uma struct por referencia ????
		 }
	 }
	
	
}

jog ObtemGoleador(Equi equipy){
	jog jogadorG;
	
	jogadorG.golm = equipy.jogad[0].golm;
	jogadorG.camisa=equipy.jogad[0].camisa;
	
	for(int i=1;i<5;i++){
		if(jogadorG.golm < equipy.jogad[i].golm){
			jogadorG.golm = equipy.jogad[i].golm;
			jogadorG.camisa = equipy.jogad[i].camisa;
		}
		
	}
	return jogadorG;
}

void escreveJogador(jog jogad){
	printf("Numero da Camisa do JOgador: %d\n",jogad.camisa);
	printf("Numero de Gols Marcador: %d\n",jogad.golm);
}

// Main
int main(){
	Equi equipa;
	jog jogadorGol;
	int nrcam;
	// 1
	leEquipe(&equipa);
	// 2
	printf("Informe O Nº Da Camiseta: ");
	scanf("%d",&nrcam);	
	while(nrcam!=99){
		
		marcouGol(nrcam, &equipa);
		printf("Informe O Nº Da Camiseta A Ser Alterado Os Gols: ");
		scanf("%d",&nrcam);	
		
	}
	//3
	jogadorGol = ObtemGoleador(equipa);
	printf("Jogador Goleador !!!\n");
	escreveJogador(jogadorGol);
		
	return 0;
}

