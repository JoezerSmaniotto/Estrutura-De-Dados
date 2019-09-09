#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

// Structs
typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *prox;
};

typedef struct {
	Nodo *inicio;
} ListaSE;

// Funcoes
void criaLista(ListaSE *lt) {
	lt->inicio = NULL;
}

void exibe(ListaSE lt){
	Nodo *pAux;
	pAux = lt.inicio;
	if(lt.inicio!=NULL){
		while (pAux != NULL) {
			printf("Cod: %d  Peso: %f\n",pAux->info.cod,pAux->info.peso);
			pAux = pAux->prox;	
		}
	}
}
	
int estaVazia(ListaSE lt)
{
	if(lt.inicio == NULL)
	{
		 return LISTA_VAZIA; 
    }else 
    {
		 return 0;
	}	
}

int incluiNoFim(ListaSE *lt, Dado d)
{
     Nodo *pNodo,*pAux;
	 pNodo = (Nodo *) malloc (sizeof (Nodo));
	 if (pNodo == NULL)
	 {
		return FALTOU_MEMORIA;
	
	 } else 
	 {
		// Cria uma aux.
		pNodo->info=d; //Inclui o conteudo
		pNodo->prox = NULL;
		
		
		if(lt->inicio==NULL)
		{
			lt->inicio = pNodo;
			//printf("OII1\n");
			return SUCESSO;
		}else 
		{
			pAux = lt->inicio; 
			while(pAux->prox !=NULL){
				pAux = pAux->prox;
			} 
			pAux->prox = pNodo; // Antes apontava para null, agora não mais.
		}
		//printf("OII2\n");
		return SUCESSO; 
   	}

}
int excluiDoInicio(ListaSE *lt, Dado *d){
	if(lt->inicio == NULL){
		return LISTA_VAZIA;
	}else {
		Nodo *pTemp;
		*d=lt->inicio->info;
		pTemp=lt->inicio;
		lt->inicio=lt->inicio->prox;
		free(pTemp);
		return SUCESSO;
	}
}

int existe(ListaSE lt, int cod){
	if(lt.inicio == NULL){
		return 0;
	}else{
	
		Nodo *pAux;
		pAux = lt.inicio; 
		while(pAux!=NULL){                              // While pAux.prox ???
			if(pAux->info.cod == cod){
				return 1; // Se existe já retorna aqui
			}
			pAux = pAux->prox;
		}
		
		return 0; // Se não existe chega ate aqui.
	}		
}

int incluiDepois (ListaSE *lt, int cod, Dado d){
	
	Nodo *pAux,*pNodo; 
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if (pNodo == NULL){
		return FALTOU_MEMORIA;
		
	}else {
		
		pAux = lt->inicio; 
		while(pAux!=NULL){ 											// pAux->prox  ?? TIREI pq no ultimo dava problema
			if(pAux->info.cod == cod){
				pNodo->info=d; // Insero novo elemento se não for na ultima posição
				pNodo->prox=pAux->prox; //
				pAux->prox=pNodo; //
				return SUCESSO;
			}
			pAux = pAux->prox;
		}	
	
		return CODIGO_INEXISTENTE;		
	}	
}

int incluiNoInicio(ListaSE *lt, Dado d) {
	Nodo *pNodo;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if (pNodo == NULL){
		return FALTOU_MEMORIA;
		
	} else {
		pNodo->info=d;
		pNodo->prox=lt->inicio;
		lt->inicio=pNodo;
		return SUCESSO;
	}	
}

int quantidadeDeNodos(ListaSE lt){
	int cont=0;
	Nodo *pAux;
	pAux = lt.inicio;
	while(pAux!=NULL){
		cont++;	
		pAux= pAux->prox;
	}
	return cont;	
}

int excluiDoFim (ListaSE *lt, Dado *d) { 
	
	if(lt->inicio == NULL){
		return LISTA_VAZIA;
	
	}else{
		Nodo *pAux,*pAnt;
		
		pAux=lt->inicio;       // Só tem um nodo
		if(pAux->prox == NULL){
			*d = pAux->info;
			free(pAux);
			lt->inicio=NULL;
			return SUCESSO;
			
		}else{
		
			pAux = lt->inicio; // lt->inicio->prox; Caso tenha 2 ou mais nodos na lista
			//pAnt = lt->inicio;
			while(pAux->prox!=NULL){
				pAnt = pAux;
				pAux = pAux->prox;
			}
			*d=pAux->info;
			pAnt->prox=NULL;
			free(pAux);
			return SUCESSO;
		}	
	}
}

int consultaPorCodigo(ListaSE lt,int cod, Dado *d){
	Nodo *pAux;
	pAux=lt.inicio;
	while(pAux != NULL){                                     // Assim ele vai ate o ultimo nodo ?? Ou quando ele 
		if(pAux->info.cod == cod){                           //  Quando ele identifica o ultimo nodo aponta para NULL
			*d=pAux->info;                                    // Ele cai fora ? Se ele não acessa os dados do ultimo tenho
			return SUCESSO;                                   // verifcar esse dado.
		}
		pAux = pAux->prox;		
	}
	return CODIGO_INEXISTENTE;	
}

int excluiNodo(ListaSE *lt,int cod, Dado *d){
	Nodo *pAux,*pAnt;
	pAux=lt->inicio->prox;
	pAnt=lt->inicio;// para o primeiro
	
	while(pAux->prox != NULL){ // pAux->prox
		if(pAux->info.cod==cod){
			*d=pAux->info;
			pAnt->prox = pAux->prox;
			return SUCESSO;
		}
		pAnt=pAux;
		pAux=pAux->prox;	
	}
	return CODIGO_INEXISTENTE;		
}


int main(){
	ListaSE lt;
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
					printf("Informe o Peso: ");
					scanf("%f",&dad.peso);
					ret=incluiNoFim(&lt,dad);
					if(ret==SUCESSO){
						printf("\nSucesso\n");
					}else if(ret==FALTOU_MEMORIA){
						printf("\nErro MEMORIA CHEIA\n");
						
					}
					
					break;
					
				case 2:	
					exibe(lt);
					printf("SucessoOI\n");
					break;
					
				case 3:	
					ret=quantidadeDeNodos(lt);
					printf("Quantidade de Nodos: %d SUCESSO\n",ret);
					break;
					
				case 4:
					ret=excluiDoFim(&lt,&dad);
					if(ret==SUCESSO){
						printf("Dado Excluido\n");
						printf("Cod: %d\n",dad.cod);
						printf("Peso: %.2f\n",dad.peso);
						printf("Sucesso\n");
					}else if(ret==LISTA_VAZIA) {
						printf("Lista Vazia Sucesso\n ");
						
					}
					break;
					
				case 5:
					printf("Informe o Cod: ");
					scanf("%d",&dad.cod);
					printf("Informe o Peso: ");
					scanf("%f",&dad.peso);
					ret=incluiNoInicio(&lt,dad);
						if(ret==SUCESSO){
						printf("\nSucesso\n");
					}else if(ret==FALTOU_MEMORIA){
						printf("\nErro FALTOU MEMORIA\n");
						
					}
					break;
				
				case 6:		
					ret=excluiDoInicio(&lt,&dad); 
					if(ret==SUCESSO){
						printf("Dado Excluido\n");
						printf("Cod: %d\n",dad.cod);
						printf("Peso: %.2f\n",dad.peso);
						printf("Sucesso\n");
					}else if(ret==LISTA_VAZIA) {
						printf("Lista Vazia Sucesso\n ");
						
					}
					
					break;
					
				case 7:	
					printf("Informe o Cod a Ser Pesquisado: ");
					scanf("%d",&cod);
					ret=consultaPorCodigo(lt,cod,&dad);
					printf("Cod: %d\n",dad.cod);
					printf("Peso: %f\n",dad.peso);
					if(ret==SUCESSO){
						printf("Sucesso\n");
						
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
					printf("Informe o Peso: ");
					scanf("%f",&dad.peso);
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
					printf("Peso: %.2f\n",dad.peso);
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
