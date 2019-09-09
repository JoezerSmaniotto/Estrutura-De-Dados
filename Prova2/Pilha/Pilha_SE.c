#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

// Structs

typedef struct nodo Nodo;

struct nodo {
 int info; /* Informação armazenada */
 Nodo *prox; /* Endereço do próximo */
};

typedef struct {
 Nodo *topo;
 
} Pilha;

// Funções
void criaPilha(Pilha *p){
	p->topo = NULL;	
}

int empilha( Pilha *p, int dado){
	 Nodo *pNodo;
	 pNodo = (Nodo *) malloc (sizeof (Nodo));
	 if (pNodo == NULL){
		return FALTOU_MEMORIA;
	
	 } else {
		 pNodo->info=dado;
		 pNodo->prox=p->topo;
		 p->topo=pNodo;
		 return SUCESSO;
	 }
	
}

int desempilha (Pilha *p, int *dado){
	if(p->topo == NULL){
		return PILHA_VAZIA;
	}else {
		
		Nodo *pTemp;
		*dado=p->topo->info;
		pTemp=p->topo;
		p->topo=p->topo->prox;
		free(pTemp);
		return SUCESSO;			
	}
			
}

int estaVazia(Pilha p){
	if(p.topo == NULL){
		return 1;
	}else {
		return 0;
	}	
}

int consulta(Pilha p,int *dado){
	if(p.topo == NULL){
		return PILHA_VAZIA;
	
	}else {
		Nodo *pNodo;
		pNodo=p.topo;
		*dado=pNodo->info;
		return SUCESSO;
	}	
}

void exibe(Pilha p){
	if(p.topo != NULL){
		Nodo *pAux;
		pAux=p.topo;
		while(pAux!=NULL){
			printf("Dado: %d\n",pAux->info);
			pAux=pAux->prox;
		}
		
	}
}


int main(){
	Pilha p;
	criaPilha(&p);
	int op,ret,dado;
			
	 do{
		printf("0 -Fim\n");	
		printf("1 -Empilha\n");	
		printf("2 -Exibe na lista\n");	
		printf("3 -Desempilha\n");	
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
					ret=empilha(&p,dado);
					if(ret==SUCESSO){
						printf("\nSucesso\n");
					}else if(ret==FALTOU_MEMORIA){
						printf("\nErro MEMORIA CHEIA\n");
						
					}
					
					break;
					
				case 2:	
					exibe(p);
					printf("Sucesso\n");
					break;
					
				case 3:	
					ret=desempilha(&p,&dado); 
					if(ret==SUCESSO){
						printf("Dado Excluido\n");
						printf("Cod: %d\n",dado);

					}else if(ret==PILHA_VAZIA) {
						printf("Lista Vazia Sucesso\n ");
						
					}
					
					break;
					
				case 4:
					ret=estaVazia(p);
					if(ret==0){
						printf("Lista Nao Esta Vazia\n");
					}else if(ret==1){
						printf("Lista Esta Vazia\n");
						
					}
					break;		
					
				case 5:
				
					ret=consulta(p,&dado);
					if(ret==SUCESSO){
						printf("SUCESSO\n");
						printf("Cod: %d\n",dado);
						
					}else if(ret==PILHA_VAZIA){
						printf("PILHA VAZIA\n");
					}		
					break;
									
					
			}
			exibe(p); 	
		} 
    }while (op>=0 && op<=5); 
	return 0;
}
