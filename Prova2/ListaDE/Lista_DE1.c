#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

// Structs
typedef struct {
	int cod;
	float sal;
} Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *prox;
	Nodo *ant;
};

typedef struct {
 Nodo *inicio;
 Nodo *fim;
 int n;
} ListaDE;

// Funções

void criaLista(ListaDE *lt){
	lt->inicio = NULL;
	lt->fim = NULL;
	lt->n = 0;		
}

void exibe(ListaDE lt){
	Nodo *pAux;
	pAux = lt.inicio;
	printf("* * * * * INICIO EXIBE* * * * *\n");
	printf("Inicio: %p\n",lt.inicio);
	while(pAux !=NULL){
		printf("Ant: %p | Cod: %d | End: %p | Sal: %f | Prox: %p |\n",pAux->ant,pAux->info.cod,pAux,pAux->info.sal,pAux->prox);		
		pAux = pAux->prox;	
	}
	printf("Fim: %p\n",lt.fim);	
}

int estaVazia(ListaDE lt){
	if(lt.n == 0){
		return 1;
	}else{
		return 0;
	}
}

int incluiNoFim(ListaDE * lt, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo*) malloc (sizeof(Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	}else {
		if(lt->inicio==NULL && lt->fim==NULL){ // Lista Vazia
			pNodo->info = d;
			pNodo->ant = NULL;
			pNodo->prox = NULL;
			lt->inicio = pNodo;
			lt->fim= pNodo;
			lt->n++;
			return SUCESSO;
			
		}else {                 // Quando Já tem Elementos
			pNodo->info = d;
			pNodo->prox = NULL;
			pNodo->ant= lt->fim;
			lt->fim->prox= pNodo;// mudo para aonde o ultimo elemento estava apontando
			lt->fim= pNodo;
			lt->n++;
			return SUCESSO;	
			
		}
		
	}
}


int existe (ListaDE lt, int cod){
	Nodo *pAux;
	pAux = lt.inicio;
	while (pAux!=NULL){
		if(pAux->info.cod == cod){
				return 1;
		}
		pAux=pAux->prox;	
	}
	return 0;
}

int incluiDepois(ListaDE *lt, int cd, Dado d){
	Nodo *pAux,*pNodo; 
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if (pNodo == NULL){
		return FALTOU_MEMORIA;
		
	}else {
		
		pAux = lt->inicio; 
		while(pAux!=NULL){ 										
			if(pAux->info.cod == cd){ 
				if(pAux->prox == NULL){ // Para o ultimo elemento
					pNodo->info = d;
					pNodo->ant=lt->fim;
					pNodo->prox=pAux->prox;
					pAux->prox = pNodo;
					lt->fim=pNodo;
					
				}else {
					pNodo->info = d;
					pNodo->prox = pAux->prox;
					pNodo->ant = pAux;
					pAux->prox =  pNodo;  
					
				}
				
				lt->n++;
				return SUCESSO;
			}
			pAux = pAux->prox;
		}
		return CODIGO_INEXISTENTE;
	}
}

int incluiNoInicio(ListaDE *lt, Dado d){
	Nodo *pNodo;
	pNodo =  (Nodo *) malloc (sizeof (Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	
	}else{
		
		if(lt->n == 0){
			pNodo->info=d;
			pNodo->ant=NULL;
			pNodo->prox=NULL;
			lt->inicio = pNodo;
			lt->fim = pNodo;
			
		}else {
			pNodo->info=d;
			pNodo->ant=NULL;
			pNodo->prox=lt->inicio;
			lt->inicio = pNodo;	
		}
		lt->n++;
		return SUCESSO;		
	}	
}

int quantidadeDeNodos(ListaDE lt){
	return lt.n;	
}

int excluiDoInicio(ListaDE *lt, Dado *d){
	if(lt->n ==0){
		return LISTA_VAZIA;
	}else {
		Nodo *pAux;
		pAux=lt->inicio;
		*d= lt->inicio->info;
		lt->inicio=lt->inicio->prox;
		if(lt->n ==1){ // Aqui se só tiver um
			lt->fim = NULL;
		}else{ // Quando tem mais de um
			lt->inicio->ant = NULL;
		}
		lt->n--;
		free(pAux);
		return SUCESSO;
	}	
}

int excluiDoFim(ListaDE *lt, Dado *d){
	if(lt->n ==0){
		return LISTA_VAZIA;
	}else {
		Nodo *pAux;
		pAux=lt->fim;
		*d= lt->inicio->info;
		//lt->inicio=lt->inicio->prox;
		if(lt->n ==1){ // Aqui se só tiver um
			lt->inicio = NULL;
			lt->fim = NULL;
		}else{ // Quando tem mais de um
			lt->fim->ant->prox=NULL;
			lt->fim = lt->fim->ant;
		}
		lt->n--;
		free(pAux);
		return SUCESSO;
	}	
}

int consultaPorCodigo(ListaDE lt, int cd, Dado *d){
	Nodo *pAux;
	pAux= lt.inicio;
	while(pAux!=NULL){
		if(pAux->info.cod == cd){
			*d=pAux->info;
			return SUCESSO;
		}
		
		pAux = pAux->prox;
		
	}
	return CODIGO_INEXISTENTE;
	
}


int excluiNodo(ListaDE *lt, int cd, Dado *d){
	Nodo *pAux;
	pAux= lt->inicio;
	while (pAux != NULL){
		if(pAux->info.cod==cd){	
			if(pAux->prox == NULL  && lt->n ==1){ // Aqui só tem um elemento
				*d=pAux->info;
				free(pAux);
				lt->inicio=NULL;
				lt->fim=NULL;
				lt->n--;
				printf("1");
				return SUCESSO;
			
			}else if( lt->n >1 && pAux->prox == NULL){  // Aqui tenho 2 ou mais e quero excluir o ultimo
				*d=pAux->info;
				pAux->ant->prox = NULL; // lt->fim->ant->prox
				lt->fim = pAux->ant; // lt->fim-ant;
				free(pAux);
				lt->n--;
				printf("2");
				return SUCESSO;		
				//pAux->prox!=NULL && lt->inicio == pAux
			}else if(lt->n > 1 && lt->inicio == pAux){ // // Aqui tenho 2 ou mais e quero excluir o Primeiro
				*d =  lt->inicio->info;
				lt->inicio =  lt->inicio->prox;
				pAux->prox->ant = NULL;
				lt->n--;
				free(pAux);
				printf("3");
				return SUCESSO;

			}else  { // Excluir do meio
				*d=pAux->info;
				pAux->ant->prox = pAux->prox;
				pAux->prox->ant = pAux->ant;
				lt->n--;
				free(pAux);
				printf("4");
				return SUCESSO;
			
			}
			
		}
		
		pAux =  pAux->prox;
	}
		
}


int main(){
	ListaDE lt;
	Dado dad;
	criaLista(&lt);
	int op,ret,cod;
			
	 do{
		printf("0 -Fim\n");	
		printf("1 -Inclui no fim\n");	
		printf("2 -Exibe na lista\n");	
		printf("3 -Quantidade de nodos\n");	
		printf("4 -Exclui do fim\n");
		printf("5 -Inclui no inicio\n");
		printf("6 -Exclui do inicio\n");
		printf("7 -Consulta por codigo\n");
		printf("8 -Verifica existencia\n");
		printf("9 -Inclui Depois\n");
		printf("10-Exclui nodo\n");
		printf("11-Esta Vazia\n");
		
		scanf("%d",&op);
		if(op>=0 && op<=11){
			switch(op){
				case 0:	
					op=15; // Para Sair do Prog, seta op para 15
					break;
					
				case 1:		
					printf("Informe o Cod: ");
					scanf("%d",&dad.cod);
					printf("Informe o Sal: ");
					scanf("%f",&dad.sal);
					ret=incluiNoFim(&lt,dad);
					if(ret==SUCESSO){
						printf("Sucesso\n");
					}else if(ret==FALTOU_MEMORIA){
						printf("Erro MEMORIA CHEIA\n");
						
					}
					
					break;
					
				case 2:	
					exibe(lt);
					//printf("Sucesso\n");
					break;
					
				case 3:	
					ret=quantidadeDeNodos(lt);
					printf("Quantidade de Nodos: %d\n",ret);
					break;
					
				case 4:
					ret=excluiDoFim(&lt,&dad);
					if(ret==SUCESSO){
						printf("Dado Excluido\n");
						printf("Cod: %d\n",dad.cod);
						printf("Sal: %.2f\n",dad.sal);
						printf("Sucesso\n");
					}else if(ret==LISTA_VAZIA) {
						printf("Lista Vazia\n ");
						
					}
					break;
					
				case 5:
					printf("Informe o Cod: ");
					scanf("%d",&dad.cod);
					printf("Informe o Sal: ");
					scanf("%f",&dad.sal);
					ret=incluiNoInicio(&lt,dad);
						if(ret==SUCESSO){
						printf("Sucesso\n");
					}else if(ret==FALTOU_MEMORIA){
						printf("\nErro FALTOU MEMORIA\n");
						
					}
					break;
				
				case 6:		
					ret=excluiDoInicio(&lt,&dad); 
					if(ret==SUCESSO){
						printf("Dado Excluido\n");
						printf("Cod: %d\n",dad.cod);
						printf("Sal: %.2f\n",dad.sal);
						printf("Sucesso\n");
					}else if(ret==LISTA_VAZIA) {
						printf("Lista Vazia Sucesso\n ");
						
					}
					
					break;
					
				case 7:	
					printf("Informe o Cod a Ser Pesquisado: ");
					scanf("%d",&cod);
					ret=consultaPorCodigo(lt,cod,&dad);
					if(ret==SUCESSO){
						printf("Sucesso\n");
						printf("Cod: %d\n",dad.cod);
						printf("Sal: %f\n",dad.sal);
						
					}else if(ret==CODIGO_INEXISTENTE){
						printf("CODIGO INEXISTENTE\n");
					}		
					break;
							
				
				case 8:	
					printf("Informe o Cod a Ser Pesquisado: ");
					scanf("%d",&cod);
					ret=existe(lt,cod);
					if(ret==1){
						printf("Existe Sucesso\n");
						
					}else if(ret==0){
						printf("NAO Existe\n");
					}		
					break;
					
				case 9:	
					printf("Informe o Cod: ");
					scanf("%d",&dad.cod);
					printf("Informe o Sal: ");
					scanf("%f",&dad.sal);
					printf("Informe a Posicao A Ser Inserido Igual ou Maior Q 1: ");
					scanf("%d",&cod);
					ret=incluiDepois(&lt,cod,dad);
					if(ret==SUCESSO){
						printf("Sucesso\n");
					
					}else if(ret==FALTOU_MEMORIA){
						printf("FALTOU MEMORIA\n");
						
					}else if(ret==CODIGO_INEXISTENTE){
						printf("Cod Nao Existe\n");
					}
					
					break;
				
				case 10:
					printf("Informe o Cod: ");
					scanf("%d",&cod);
					ret=excluiNodo(&lt,cod,&dad);
					printf("Cod: %d\n",dad.cod);
					printf("Sal: %.2f\n",dad.sal);
					if(ret==SUCESSO){
						printf("SUCESSO\n");
					}else if(ret==CODIGO_INEXISTENTE){
						printf("COD Inexistente\n");
					}
					break;
							
				case 11:		
					ret=estaVazia(lt);
					if(ret==0){
						printf("Lista Nao Esta Vazia\n");
					}else if(ret==LISTA_VAZIA){
						printf("Lista Esta Vazia\n");
						
					}
					break;		
			}
			exibe(lt); 	
		} 
    }while (op>=0 && op<=11); 
	return 0;
}
