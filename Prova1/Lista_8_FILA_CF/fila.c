#include <stdio.h>
#include <stdlib.h>
/* Códigos de erro */
#define SUCESSO 0 
#define FILA_VAZIA 1
#define FILA_CHEIA 2
#define MAX_NODOS 5

// Strutcs
typedef struct {
	 int v[MAX_NODOS];
	 int frente; /* índice da frente */
	 int re; /* índice da re */
} FilaCF;

// Funções

void criaFila (FilaCF *f){
	f->frente = 0;
	f->re=-1;	
}

int insere(FilaCF *f,int dado){
	if(f->re == (MAX_NODOS -1) && f->frente==0){ // Verifico se não esta cheia
		return FILA_CHEIA;
		
	}else if(f->re == (MAX_NODOS -1) && f->frente > 0){
		int i,j;
		for(i=0,j=f->frente;j <=f->re;i++,j++){
			f->v[i]=f->v[j];
		}
		f->frente=0;
		f->re=i; // Já esta incrementado para mais uma por causa do teste
		f->v[f->re] = dado;
		return SUCESSO;
		
	}else {
		f->re++;
		f->v[f->re]=dado;
		return SUCESSO;
		
	}
		
}

int retira(FilaCF *f,int *dado){
	if(f->re  < f->frente){	
		return  FILA_VAZIA;
		
	}else {
		*dado=f->v[f->frente];
		f->frente++;
		return SUCESSO;
	}
}

int estaCheia(FilaCF f){
	if(f.re == (MAX_NODOS-1) && f.frente ==0){
		return FILA_CHEIA;	
	}else {
		return 0;
	}	
}

int estaVazia(FilaCF f){
	if(f.frente > f.re){
		return FILA_VAZIA;
		
	}else {
		return 0;
	}	
}

int consulta(FilaCF f,int *dado){
	if(f.frente > f.re){// testa se nAO ESTA VAZIO
		return FILA_VAZIA;
		
	}else{
		*dado=f.v[f.frente];
		return SUCESSO;
	}
}

int pesquisa (FilaCF f, int cod, int *dado){
	if(f.frente > f.re){
		return FILA_VAZIA;
		
	}else{
		//FilaCF FF;
		//criaFila(&FF);
		while(f.v[f.frente]!=cod){
			f.frente++;			
		}
		*dado=f.v[f.frente];
		return SUCESSO;
	}
}


void exibe(FilaCF f){
	int i;
	
		//printf("*****EXIBE*****\n");
		for(i=f.frente;i<=f.re;i++){
			printf("*****%d*****\n",i);
			printf("Dado: %d\n",f.v[i]);		
		}
			//printf("*****FIM EXIBE*****\n");
	
}

// Main
int main(){
	FilaCF f;
	criaFila(&f);
	int dado,ret,op,codd;
		
	 do{
		printf("0 -Fim\n");	
		printf("1 -Insere\n");	
		printf("2 -Retira\n");	
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
					
					printf("Informe o Dado: ");
					scanf("%d",&dado);
					
					ret=insere(&f,dado);
					if(ret==FILA_CHEIA){
						printf("FILA CHEIA\n");
					}else if(ret==SUCESSO){
						printf("SUCESSO - INSERIDO\n");
						
					}					
					break;
					
				case 2:	
					ret=retira(&f,&dado);
					if(ret==FILA_VAZIA){
						printf("FILA VAZIA\n");
					}else if(ret==SUCESSO){
						printf("Dado: %d\n",dado);
						printf("SUCESSO - RETIRADO\n");
						
					}					
					break;
					
				case 3:	
					ret=estaCheia(f);
					if(ret==FILA_CHEIA){
						printf("FILA_CHEIA\n");
						
					}else if(ret==0){
						printf("FILA NAO ESTA CHEIA\n");
						
					}
					break;
					
				case 4:	
					ret=estaVazia(f);
					if(ret==FILA_VAZIA){
						printf("FILA_VAZIA\n");
						
					}else if(ret==0){
						printf("FILA NAO ESTA VAZIA\n");	
					}
					break;		
								
				case 5:
					ret=consulta(f,&dado);
					if(ret==FILA_VAZIA){
						printf("FILA VAZIA\n");
						
					}else if(ret==SUCESSO){
						printf("Consulta\n");
						printf("Dado: %d\n",dado);
						
						
					}
					break;
				
				case 6:		
					printf("Informe o Dado a Ser Pesquisado: ");
					scanf("%d",&codd);
					ret=pesquisa(f,codd,&dado);
					if(ret==FILA_VAZIA){
						printf("FILA VAZIA\n");
					}else if(ret==SUCESSO){
						printf("DADO: %d\n",dado);
										
					}
					break;
					
			}
			
		}
		exibe(f);
	}while(op>=0 && op<=7);
	
	
	
	return 0;
}

