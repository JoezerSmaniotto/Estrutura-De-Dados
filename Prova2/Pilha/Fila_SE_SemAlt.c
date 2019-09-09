#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2

// Structs
typedef struct nodo Nodo;
struct nodo {
 int info;
 Nodo *prox;
};

typedef struct {
 Nodo *frente;
 Nodo *re;

} Fila;

// Funcoes

void criaFila(Fila *f){
	f->frente=NULL;
	f->re=NULL;
}

int insere(Fila *f, int dado){
	 Nodo *pNodo;
	 pNodo = (Nodo *) malloc (sizeof (Nodo));
	 if (pNodo == NULL){
		return FALTOU_MEMORIA;
	
	 } else if(f->frente == NULL && f->re == NULL){
			
			 pNodo->info=dado; // Quando Estiver vaziu e for colocar o primeiro elemento
			 pNodo->prox=NULL;
			 f->frente=pNodo;
			 f->re=pNodo->prox;
			 return SUCESSO;
	 
	 }else if(f->frente != NULL && f->re == NULL) { // Aqui quando já tiver no minimo um elemento inserido o proximo cai aqui
			Nodo *pAux;
			pAux=f->frente;
			while(pAux->prox != NULL){
				pAux = pAux->prox;
			}
			pNodo->info=dado;						// quando for inserir o Segundo elemento.
			pNodo->prox=NULL;
			pAux->prox=pNodo;
			f->re=pNodo->prox;
			return SUCESSO;		 
	 }
	
}

int retira (Fila *f, int *dado){
	if(f->frente == NULL && f->re == NULL){
		return FILA_VAZIA;
		
	}else {
		Nodo *pAux;
		*dado=f->frente->info;
		pAux=f->frente;
		f->frente=f->frente->prox;
		free(pAux);
		return SUCESSO;
	}	
}

int estaVazia( Fila f){
	if(f.frente == NULL && f.re == NULL){
		return 1;
	}else {
		return 0;	
	}
	
}

int consulta ( Fila f, int *dado){
	if(f.frente == NULL && f.re == NULL){
		return FILA_VAZIA;
	}else {
		Nodo *pAux;
		pAux=f.frente;
		*dado=pAux->info;
		return SUCESSO;	
	}	
}

void exibe (Fila f){
	if(f.frente != NULL && f.re == NULL){	
		Nodo *pNodo;
		pNodo=f.frente;
		while(pNodo != NULL){
			printf("Cod: %d\n",pNodo->info);
			pNodo=pNodo->prox;
		}	
	}	
}

int main(){
	Fila f;
	criaFila(&f);
	int op,ret,dado;
			
	 do{
		printf("0 -Fim\n");	
		printf("1 -Insere\n");	
		printf("2 -Exibe na lista\n");	
		printf("3 -Remove\n");	
		printf("4 -Esta Vazia\n");
		printf("5 -Consulta\n");
		
		
		scanf("%d",&op);
		if(op>=0 && op<=5){
			switch(op){
				case 0:	
					op=15; // Para Sair do Prog, seta op para 15
					break;
				
				case 1:		
					printf("Informe o Cod: ");
					scanf("%d",&dado);
					ret=insere(&f,dado);
					if(ret==SUCESSO){
						printf("\nSucesso\n");
					}else if(ret==FALTOU_MEMORIA){
						printf("\nErro MEMORIA CHEIA\n");
						
					}
					
					break;
					
				case 2:	
					exibe(f);
					printf("Sucesso\n");
					break;
					
				case 3:	
					ret=retira(&f,&dado); 
					if(ret==SUCESSO){
						printf("Dado Excluido\n");
						printf("Cod: %d\n",dado);

					}else if(ret==FILA_VAZIA) {
						printf("Lista Vazia Sucesso\n ");
						
					}
					
					break;
					
				case 4:
					ret=estaVazia(f);
					if(ret==0){
						printf("Lista Nao Esta Vazia\n");
					}else if(ret==1){
						printf("Lista Esta Vazia\n");
						
					}
					break;		
					
				case 5:
				
					ret=consulta(f,&dado);
					if(ret==SUCESSO){
						printf("SUCESSO\n");
						printf("Cod: %d\n",dado);
						
					}else if(ret==FILA_VAZIA){
						printf("PILHA VAZIA\n");
					}		
					break;
									
					
			}
			exibe(f); 	
		} 
    }while (op>=0 && op<=5); 
	return 0;
}
