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
	 int tam;
} FilaCF;

// Funções

void criaFila (FilaCF *f){
	f->frente = 0;
	f->re=-1;
	f->tam=0;	
}

int insere(FilaCF *f,int dado){
	if(f->tam==MAX_NODOS){ // Verifico se não esta cheia
		return FILA_CHEIA;
		
	}else if(f->re == (MAX_NODOS)){ // Se fosse igual MAX_NODOS-1 ele não iria escrever na ultima possição do vetor
		f->re=0;
		f->v[f->re] = dado;
		f->tam++;
		return SUCESSO;
		
	}else if(f->re < MAX_NODOS){ // Aqui vou alocando na lista de 1 a 5 
		f->re++;
		f->v[f->re]=dado;
		f->tam++;
		return SUCESSO;
		
	}
		
}

int retira(FilaCF *f,int *dado){
	if(f->tam == 0){	
		return  FILA_VAZIA;
		
	}else if (f->frente != MAX_NODOS){ // Aqui vou RETIRANDO enquanto a frente 
		*dado=f->v[f->frente];
		f->frente++;
		f->tam--;
		return SUCESSO;
	}else {// AQUI QUANDO MINHA FRENTE FOR IGUAL A MAX NODOS ZERO A FRENTE TORNANDO ELA CIRCULAR
		f->frente=0;
		*dado=f->v[f->frente];
		f->tam--;
		return SUCESSO;
	}
}

int estaCheia(FilaCF f){
	if(f.tam == MAX_NODOS){
		return FILA_CHEIA;	
	}else {
		return 0;
	}	
}

int estaVazia(FilaCF f){
	if(f.tam == 0){
		return FILA_VAZIA;
		
	}else {
		return 0;
	}	
}

int consulta(FilaCF f,int *dado){
	if(f.tam==0){// testa se nAO ESTA VAZIO
		return FILA_VAZIA;
		
	}else{
		*dado=f.v[f.frente];
		return SUCESSO;
	}
}

int pesquisa (FilaCF f, int cod, int *dado){
	int auxtam=p.tam;
	if(f.tam ==0){
		return FILA_VAZIA;
		
	}else{
		while(f.v[f.frente]!=cod){
			if(f.frente==MAX_NODOS){
				f.frente=0;			
				
			}else {
				f.frente++;
			}
		}
		*dado=f.v[f.frente];
	}
}


void exibe(FilaCF f){
	int i,j,resp,cont=0;
	
	while(cont!=f.tam){
		if(f.frente==MAX_NODOS){
			f.frente=0;

		}else {
			
			printf("*****%d*****\??????????????????????????n",cont);
			printf("");
			
		}
		
		
	}
	
	
	/*for(i=f.frente,j=0;i<=f.re;i++,j++){
			if((f.re==MAX_NODOS) &&  f.tam < MAX_NODOS){
				
				printf("*****%d*****\n",j);
				printf("Dado: %d\n",f.v[i]);		
			}else {
				printf("*****%d*****\n",j);
				printf("Dado: %d\n",f.v[i]);
				
			}
		}*/		
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
					ret=pesquisa (f,codd,&dado);
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

