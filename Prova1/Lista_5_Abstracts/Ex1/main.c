#include <stdio.h>
#include <stdlib.h>
#include "Cheque.h"

int main(){
	int n1,n2,retor,retnum;
	float v1,v2;
	Cheque ch1, ch2;
	
	printf("Informe O Numero do Cheque: ");
	scanf("%d",&n1);
	criaCheque(n1,&ch1);
	printf("Informe O Numero do Cheque: ");
	scanf("%d",&n2);
	criaCheque(n2,&ch2);
	
	// Altera o valor dos Cheques
	
	printf("Informe o Valor do Primeiro Cheque: ");
	scanf("%f",&v1);
	printf("Informe o Valor do Segundo Cheque: ");
	scanf("%f",&v2);
	emiteCheque(&ch1,v1);
	emiteCheque(&ch2,v2);
	
	exibeCheque(ch1);
	exibeCheque(ch2);
	
	if( obtemValor(ch1) > obtemValor(ch2)){
		retor=compensaCheque(&ch1);
		if(retor==0){
			printf("Secusso Na Compensacao!\n");
		
		} else if (retor==1){
			printf("Erro Na Compensacao!\n");
		}
	
	} else if ( obtemValor(ch2) > obtemValor(ch1)){
		retor=compensaCheque(&ch2);
		if(retor==0){
			printf("Secusso Na Compensacao!\n");
		
		} else if (retor==1){
			printf("Erro Na Compensacao!\n");
		}
	}
	
	exibeCheque(ch1);
	exibeCheque(ch2);	
	
	retnum=obtemNumero(ch1);
	printf("Cheque 1: Num: %d\n",retnum);
	
	retnum=obtemNumero(ch2);
	printf("Cheque 2: Num: %d\n",retnum);
	
	return 0;
}

