#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0 /* Códigos de erro */
#define PILHA_VAZIA 1
#define PILHA_CHEIA 2
#define MAX_NODOS 5

// Structs
typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct {
	int topo;
	Dado v[MAX_NODOS];
}PilhaCF;

// FUNÇÔES
void criaPilha(PilhaCF *p){
		p->topo=-1;
}

int empilha( PilhaCF *p, Dado dado){
	if(p->topo == (MAX_NODOS -1)){
		return PILHA_CHEIA;
	
	}else{
		p->topo++;
		p->v[p->topo]= dado;
		return SUCESSO;
	}	
}

int desempilha(PilhaCF *p,Dado *dado){
	if(p->topo > -1){
		*dado = p->v[p->topo];
		p->topo--;
		return SUCESSO;
		
	}else{
			
		return PILHA_VAZIA;
	}
}

int estaCheia(PilhaCF p){
	if(p.topo == (MAX_NODOS -1)){
		return PILHA_CHEIA;
	}else{
		return 0;
	}
}

int estaVazia(PilhaCF p){
	if(p.topo == -1){
		return PILHA_VAZIA;
		
	}else{	
		return 0;
	}
}

int consulta(PilhaCF p,Dado *dado){
	if(p.topo > -1){
		*dado=p.v[p.topo];
		return SUCESSO;
	}else {
		return PILHA_VAZIA;
	}
}

int pesquisa (PilhaCF *p, int cod, Dado *dado){
	if(p->topo==-1){
		return PILHA_VAZIA;
	
	}else {
		PilhaCF PP;
		criaPilha(&PP);
		
		while(p->v[p->topo].cod != cod){
			PP.topo++;
			PP.v[PP.topo]=p->v[p->topo];
			p->topo--;	
		}
		*dado=p->v[p->topo];
		p->topo++; // Assim não perdo o dado
		
		while(PP.topo > -1){
			p->v[p->topo]=PP.v[PP.topo];
			PP.topo--;
			p->topo++;
		}
		p->topo--; // Vai umam vez a mais.
		return SUCESSO;	
	}				
}		


void exibe (PilhaCF p){
	int i;
	for(i=0;i<=p.topo;i++){
		printf("*****%d*****\n",i);
		printf("Cod: %d.\n",p.v[i].cod);
		printf("Peso: %.2f.\n",p.v[i].peso);
	}
}


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
