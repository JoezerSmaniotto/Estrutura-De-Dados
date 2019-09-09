#include <stdio.h>
#include <stdlib.h>
#include "Cheque.h"
#include "Cheque.c"
#include "Talao.h"
#include "Talao.c"

int main(){
	int numcont, numpri,op,nrcomp, ret,sit, nremite;
	float valor, totsit;
	talao tal;
	printf("informe o numero da Conta: ");
	scanf("%d",&numcont);
	printf("informe o Numero do Primeiro Cheque: ");
	scanf("%d",&numpri);
	criaTalao( numcont, numpri,&tal);
	do{
		printf("0 -Fim\n");	
		printf("1 -Exibe talao\n");	
		printf("2 -Emite Cheque\n");	
		printf("3 -Compensa Cheque\n");	
		printf("4 -Soma Cheques do Talao\n");
		printf("Informe sua Opcao: ");
		scanf("%d",&op);
		if(op>=1 && op<=4){
			switch(op){
				case 0:
					break;
				
				case 1:		
					exibeTalao(tal);
					break;
					
				case 2:	
					printf ("Informe o Nr do Cheque a ser Emitido: "); // tava dando erro pq n tinha lido o nr do cheque
					scanf ("%d",&nremite);
					printf("Informe o Valor: ");
					scanf("%f",&valor);	
					ret=emiteChequeDoTalao( &tal, nremite, valor); 
					if(ret==0){
						printf("Sucesso\n");
					}else {
							printf("Erro\n");
					}
					
					break;
					
				case 3:	
					printf("Informe o Nr do Cheque a ser Compensado: ");
					scanf("%d",&nrcomp);
					ret=compensaChequeDoTalao( &tal, nrcomp);
					if(ret==0){
						printf("Sucesso\n");
					}else {
						printf("Erro\n");
					}
					
					
					break;
					
				case 4:	
					printf("Informe a Situacao 0||1||2 : ");
					scanf("%d",&sit);	
					totsit=somaChequesDoTalao (tal,sit);
					printf("Total dos Cheques em Situacao: %d R$%.2f",sit,totsit);
					break;	
			}
				
		}
		
	}while(op!=0);
	
	return 0;
}


