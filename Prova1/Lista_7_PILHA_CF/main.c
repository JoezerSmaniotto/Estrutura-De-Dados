#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0 /* Códigos de erro */
#define PILHA_VAZIA 1
#define PILHA_CHEIA 2
#define MAX_NODOS 5
//#define E 3
#include "funcoes.h"
#include "funcoes.c"

int main(){
	PilhaCF p;
	Dado d;
	int op,ret,codd;
	
	criaPilha(&p);
	
	 do{
		printf("0 -Fim\n");	
		printf("1 -Empilha\n");	
		printf("2 -Desempilha\n");	
		printf("3 -Esta Cheia\n");	
		printf("4 -Esta Vazia\n");
		printf("5 -Consulta\n");
		printf("6 -Pesquisa\n");
		scanf("%d",&op);
		if(op>=0 && op<=7){
			switch(op){
				case 0:	
					op=15; // Para Sair do Prog, seta op para 15
					printf("Fim!\nSucesso\n");
					break;
				
				case 1:	
					
					printf("Informe o Cod: ");
					scanf("%d",&d.cod);
					printf("Informe o Peso: ");
					scanf("%f",&d.peso);
					
					ret=empilha(&p,d);
					if(ret==PILHA_CHEIA){
						printf("PILHA CHEIA\n");
					}else if(ret==SUCESSO){
						printf("SUCESSO - EMPILHADO\n");
						
					}					
					break;
					
				case 2:	
					ret=desempilha(&p,&d);
					if(ret==PILHA_VAZIA){
						printf("PILHA VAZIA\n");
					}else if(ret==SUCESSO){
						printf("Cod: %d\n",d.cod);
						printf("Peso: %f\n",d.peso);
						printf("SUCESSO - DESEMPILHADO\n");
						
					}					
					break;
					
				case 3:	
					ret=estaCheia(p);
					if(ret==PILHA_CHEIA){
						printf("PILHA_CHEIA\n");
						
					}else if(ret==0){
						printf("PILHA NAO ESTA CHEIA\n");
						
					}
					break;
				case 4:	
					ret=estaVazia(p);
					if(ret==PILHA_VAZIA){
						printf("PILHA_VAZIA\n");
						
					}else if(ret==0){
						printf("PILHA NAO ESTA VAZIA\n");
						
					}
					break;					
				case 5:
					
					ret=consulta(p,&d);
					if(ret==PILHA_VAZIA){
						printf("PILHA_VAZIA\n");
						
					}else if(ret==0){
						printf("Consulta\n");
						printf("Cod: %d\n",d.cod);
						printf("Peso: %f\n",d.peso);
						//printf("PILHA NAO ESTA VAZIA\n");
						
					}
					break;
				
				case 6:		
					printf("Informe o Cod a Ser Pesquisado: ");
					scanf("%d",&codd);
					ret=pesquisa (&p,codd,&d);
					if(ret==PILHA_VAZIA){
						printf("PILHA VAZIA\n");
					}else if(ret==SUCESSO){
						printf("Cod: %d\n",d.cod);
						printf("Peso: %f\n",d.peso);
						
					}
					break;
					
			}
			
		}
		exibe(p);
	}while(op>=0 && op<=7);
	
	return 0;
}

