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

// Funcoes
void criaLista(ListaDE *lt) { // OK
	lt->inicio = NULL;
	lt->fim = NULL;
	lt->n = 0;
}

void exibe(ListaDE lt){ //OK
	Nodo *pAux;
	pAux = lt.inicio;
	if(lt.inicio!=NULL){
		printf("* * * * * INICIO EXIBE* * * * *\n");
		printf("Inicio: %p\n",lt.inicio);
		while (pAux != NULL) { // lt.fim
			printf("Ant: %p |  Cod: %d | End: %p | Sal: %f | Prox: %p\n",pAux->ant,pAux->info.cod,pAux,pAux->info.sal,pAux->prox);
			pAux = pAux->prox;	
		}
		printf("Fim: %p\n",lt.fim);
		printf("QT: %d\n",lt.n);
		printf("* * * * *  FIM - EXIBE* * * * *\n");
	}
}
	
int estaVazia(ListaDE lt){ //OK
	
	if(lt.n == 0){
		return LISTA_VAZIA; 

    }else {
		 return 0;
	}	
}

int incluiNoFim(ListaDE *lt, Dado d){  //OK
     Nodo *pNodo;//*pAux;
	 pNodo = (Nodo *) malloc (sizeof (Nodo));
	 if (pNodo == NULL){
		return FALTOU_MEMORIA;
	
	 } else {
		// Cria uma aux
		pNodo->info=d; //Inclui o conteudo
		pNodo->prox = NULL;
		
		
		if(lt->inicio==NULL && lt->fim==NULL){
			pNodo->ant=NULL;
			lt->inicio = pNodo;
			lt->fim = pNodo;
			
		}else{
			lt->fim->prox = pNodo;
			pNodo->ant = lt->fim;
			lt->fim=pNodo;	
		}	
		lt->n++;
		return SUCESSO; 
   	}

} 

int excluiDoInicio(ListaDE *lt, Dado *d) { // ok
	 Nodo *pNodo;
	 if (lt->n==0){
		return LISTA_VAZIA;
	 }else {
		 *d = lt->inicio->info;
		 pNodo = lt->inicio;
		 lt->inicio = lt->inicio->prox;
		 if (lt->n == 1){
			lt->fim = NULL;
		 }else{
			lt->inicio->ant = NULL;
		 }
		 lt->n--;
		 free (pNodo);
		 return SUCESSO;
	 }
} 


int existe(ListaDE lt, int cod){ // OK
	if(lt.inicio == NULL){
		return 0;
	}else{
	
		Nodo *pAux;
		pAux = lt.inicio; 
		while(pAux!=NULL){                            
			if(pAux->info.cod == cod){
				return 1;
			}
			pAux = pAux->prox;
		}
		
		return 0; 
	}		
}

int incluiDepois (ListaDE *lt, int cod, Dado d){ //OK
	
	Nodo *pAux,*pNodo; 
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if (pNodo == NULL){
		return FALTOU_MEMORIA;
		
	}else {
		
		pAux = lt->inicio; 
		while(pAux!=NULL){ 										
			if(pAux->info.cod == cod){
				if(pAux->prox == NULL){ // Aqui se estou inserindo na um novo elemento na ultima posição, tenho que Atualizar o FIM  
					pNodo->info=d; 
					pNodo->ant = pAux;
					pNodo->prox=pAux->prox; 
					pAux->prox=pNodo;
					lt->fim=pNodo;
					
				}else {
					pNodo->info=d; 
					pNodo->ant = pAux;
					pNodo->prox=pAux->prox; 
					pAux->prox=pNodo;		
				}
				lt->n++;				
				return SUCESSO;
			}
			pAux = pAux->prox;
		}	
	
		return CODIGO_INEXISTENTE;		
	}	
} 

int incluiNoInicio(ListaDE *lt, Dado d) { // OK
	 Nodo *pNodo;
	 pNodo = (Nodo *) malloc (sizeof (Nodo));
	 if (pNodo==NULL){
		return FALTOU_MEMORIA;

	 }else {
		pNodo->info=d; 
		pNodo->ant=NULL;
		pNodo->prox=lt->inicio;	 
		lt->inicio = pNodo;
		if (lt->n == 0){
			lt->fim = pNodo;
		}else{
			lt->inicio->prox->ant = pNodo;
		 }
		lt->n++;
		return SUCESSO;
	 }
}



int quantidadeDeNodos(ListaDE lt){ //OK

	return lt.n;	
}


int excluiDoFim (ListaDE *lt, Dado *d) { // OK
	
	if(lt->inicio == NULL){
		return LISTA_VAZIA;
	
	}else{
		Nodo *pAux;
		pAux=lt->fim;      
		*d = pAux->info;
		if(lt->n == 1){  // Só tem um nodo
			free(pAux);
			lt->inicio=NULL;
			lt->fim=NULL;	
		}else{            // Caso tenha 2 ou mais nodos na lista
			
			lt->fim->ant->prox=NULL;
			lt->fim = lt->fim->ant;
		}
		free(pAux);
		lt->n--;
		return SUCESSO;
	}	
	
}

int consultaPorCodigo(ListaDE lt,int cod, Dado *d){
	Nodo *pAux;
	pAux=lt.inicio;
	while(pAux != NULL){                                     
		if(pAux->info.cod == cod){                          
			*d=pAux->info;                                    
			return SUCESSO;                                  
		}
		pAux = pAux->prox;		
	}
	return CODIGO_INEXISTENTE;	
}

int excluiNodo(ListaDE *lt,int cod, Dado *d){
	Nodo *pAux;
	pAux=lt->inicio;

	while(pAux != NULL){ //pAux->prox != NULL 
		if(pAux->info.cod==cod){
			if(pAux->prox==NULL && lt->n == 1){ // Quando só tem um elemento para excluir
				*d=pAux->info;
				free(pAux);
				lt->inicio=NULL;
				lt->fim=NULL;
				lt->n--;
				printf("\n1\n");
				return SUCESSO;
				
			}else if(pAux->prox==NULL && lt->n > 1){ // Quando tenho mais de um elemento para excluir e ele é ultimo
				*d=pAux->info;
				lt->fim->ant->prox=NULL;
				lt->fim=lt->fim->ant;
				free(pAux);
				lt->n--;
				printf("\n2\n");
				return SUCESSO;				
				
			}else if(pAux->prox!=NULL && lt->inicio == pAux){ // Quando quero excluir o primeiro elemento com tem dois ou mais elementos
				*d=pAux->info;
				lt->inicio=pAux->prox;
				pAux->prox->ant=NULL; // alterei
				free(pAux);
				lt->n--;
				printf("\n3\n");
				return SUCESSO;	
				
			}else{ // No meio nem no começo nem no fim
				*d=pAux->info;
				pAux->ant->prox = pAux->prox;
				pAux->prox->ant =  pAux->ant;
				free(pAux);
				lt->n--;
				printf("\n4\n");
				return SUCESSO;		
			}
		}
		pAux=pAux->prox;	
	}
	return CODIGO_INEXISTENTE;		
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
