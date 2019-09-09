#include <stdio.h>
#include <stdlib.h>
#define MAX_NODOS 5
#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define POSICAO_INVALIDA 3
#define CODIGO_INEXISTENTE 4
#define INDICE_INVALIDO 6

// Strutcs
typedef struct{
	int cod;
	float peso;	
}Dado;

typedef struct{
	int n;
	Dado v[MAX_NODOS];
}ListaCF;

// Funções;

void criaLista (ListaCF *lt) {
	lt->n=0;
	
}

void exibe(ListaCF lt){
	int i;
	if(lt.n>0){
		for(i=0;i<lt.n;i++){
			printf("*****%d*****\n",i);
			printf("Cod: %d\n",lt.v[i].cod);
			printf("Peso: %.2f\n",lt.v[i].peso);
		}
	}
}

int estaCheia(ListaCF lt){
	if(lt.n == MAX_NODOS){  // Não ter que ser ate Max_NODOS -1 ?? 
		return 1;	
	}else {		
		return 0;		
	}	
}


int excluiDoFim ( ListaCF *lt, Dado  *d){  
		if(lt->n==0){
			return LISTA_VAZIA;
		}else {
			*d=lt->v[lt->n-1]; // Menos um pq o começa em Zero
			lt->n--;
			return SUCESSO;		
		}	
}

int excluiDoInicio(ListaCF *lt,Dado *d) {
		if(lt->n==0){
			return LISTA_VAZIA;
		}else {
			int i;
			*d=lt->v[0]; // Menos um pq o começa em Zero
			for(i=1;i < lt->n;i++){
				lt->v[i-1]=lt->v[i];
			}
			lt->n--;
			return SUCESSO;		
		}	
}


int existe( ListaCF lt, int codg){
	int i;
	for(i=0;i<lt.n;i++){
		if(lt.v[i].cod==codg){
			return 1;
		}	
	}
	return 0;	
}

int incluiNaPosicao(ListaCF *lt, int pos, Dado dad){	
	if(lt->n == MAX_NODOS){ // CHEIA
		return LISTA_CHEIA;
	
	}else if(pos > (MAX_NODOS-1)){ // POSIÇÂO INVALIDA
		return POSICAO_INVALIDA;
		
	}else if(pos==(MAX_NODOS-1)){ // Ultima Posição
			lt->v[pos]=dad;
			lt->n++;
			return SUCESSO;
	}else if(lt->n==0 && pos < MAX_NODOS){   // Quando a lista esta vazia q quero inserir em qualquer posição;
		lt->v[pos]=dad;
		lt->n++;
		return SUCESSO;
		
	}else {                    // Demias Posições que Não são a ultima
		int i;
		for(i=lt->n;i>pos;i--){
			lt->v[i]=lt->v[i-1];
		}
		lt->v[pos]=dad;
		lt->n++;
		return SUCESSO;
	}
}

int incluiAntes(ListaCF *lt, int cod, Dado dad){
	int i,pos, flag=0;
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}else {
	
		for(i=0;i<lt->n;i++){
			if(lt->v[i].cod==cod){
				pos=i;
				flag=1;
				break;
			}
		}
		if(flag==0){
			return CODIGO_INEXISTENTE;
		}else if(flag==1){
			int i;

			for(i=lt->n;i>=pos;i--){ // ASSIM NÂO PERCO O DADO DO ANTES INDO ATE O POS COM lt->v[i]=lt->v[i-1];
				lt->v[i]=lt->v[i-1];
				
			}
			lt->v[pos-1]=dad;
			lt->n++;
			return SUCESSO;
		}
		
	}
		
}



int incluiNoFim(ListaCF *lt, Dado d){
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}else{
		lt->v[lt->n]=d;
		lt->n++;
		return SUCESSO;
	}
	
}


int quantidadeDeNodos(ListaCF lt){
	return lt.n;	
}

int estaVazia(ListaCF lt){
	if(lt.n==0){
		return 1;
	}else {
		return 0;	
	}
	
}

int incluiNoInicio(ListaCF *lt, Dado d){
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;	
	}else{
		int i;
		for(i=lt->n;i>=1;i--){
			lt->v[i]=lt->v[i-1];
		}
		lt->v[0]=d;
		lt->n++;
		return SUCESSO;
	}
}


int consultaPorPosicao( ListaCF lt, int pos, Dado *d){
	if(pos>lt.n){
		return POSICAO_INVALIDA;
	}else {
		*d=lt.v[pos];
		return SUCESSO;
	}	
}

int consultaPorCodigo(ListaCF lt, int codd,Dado *dad){
	int i,pos,flag=0;
	// Encontra o Cod
	for(i=0;i<lt.n;i++){
		if(lt.v[i].cod==codd){
			pos=i;
			flag=1;
			break;
		}
	}
	if(flag==0){
		return CODIGO_INEXISTENTE;	
	}else {
		*dad=lt.v[pos];
		return SUCESSO;
	}
}

int excluiDaPosicao (ListaCF *lt, int pos, Dado *nodo){
	if(pos > lt->n){
		return POSICAO_INVALIDA;
	}else {                    // Não coloquei a ultima posição
		*nodo=lt->v[pos];
		int i;
		for(i=pos;i<lt->n;i++){
			lt->v[i]=lt->v[i+1];
		}
		lt->n--;
		return SUCESSO;
	}
	
}

int excluiNodo (ListaCF *lt, int cod, Dado *nodo){
	int i,pos,flag=0;
	// Encontra a Posição 
	for(i=0;i<lt->n;i++){
		if(lt->v[i].cod==cod){
			pos=i;
			flag=1;
			break;
		}
	}
	if(flag==0){
		return CODIGO_INEXISTENTE;
	
	}else {
		*nodo=lt->v[pos];
		for(i=pos; i < lt->n;i++){
			lt->v[i]=lt->v[i+1];
		}
		lt->n--;
		return 0;
		
	}
	
}

int main(){
	 ListaCF lt;
	 Dado dad;
	 int ret,cod,op,pos;
	 criaLista(&lt);
	 do{
		printf("0 -Fim\n");	
		printf("1 -Inclui no fim\n");	
		printf("2 -Exibe lista\n");	
		printf("3 -Quantidade de nodos\n");	
		printf("4 -Exibe situação da lista\n");
		printf("5 -Exclui do fim\n");
		printf("6 -Inclui no inicio\n");
		printf("7 -Exclui do inicio\n");
		printf("8 -Consulta por posicao\n");
		printf("9 -Verifica existencia\n");
		printf("10 -Consulta por codigo\n");
		printf("11 -Inclui na posição\n");
		printf("12 -Exclui da posição\n");
		printf("13 -Inclui Antes\n");
		printf("14 -Exclui nodo\n");
		scanf("%d",&op);
		if(op>=0 && op<=14){
			switch(op){
				case 0:	
					op=15; // Para Sair do Prog, seta op para 15
					exibe(lt);
					printf("\nSucesso\n");
					break;
				
				case 1:		
					printf("Informe o Cod: ");
					scanf("%d",&dad.cod);
					printf("Informe o Peso: ");
					scanf("%f",&dad.peso);
					ret=incluiNoFim(&lt,dad);
					if(ret==0){
						printf("\nSucesso\n");
					}else if(ret==2){
						printf("\nErro Lista Lista Cheia\n");
						
					}
					break;
					
				case 2:	
					exibe(lt);
					printf("Sucesso\n");
					break;
					
				case 3:	
					ret=quantidadeDeNodos(lt);
					printf("Quantidade de Nodos: %d SUCESSO\n",ret);
					break;
					
				case 4:	
					ret=quantidadeDeNodos(lt);
					if(ret==0){
						printf("Lista Vazia Sucesso\n");
					}else if(ret==MAX_NODOS){
						printf("Lista Cheia Sucesso\n");
						
					}else{
						printf("A lista possui 1 ou mais nodos\n");
					}
					break;
					
				case 5:
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
				
				case 6:		
					printf("Informe o Cod: ");
					scanf("%d",&dad.cod);
					printf("Informe o Peso: ");
					scanf("%f",&dad.peso);
					ret=incluiNoInicio(&lt,dad);
					if(ret==SUCESSO){
						printf("\nSucesso\n");
					}else if(LISTA_CHEIA==ret){
						printf("\nErro Lista Lista Cheia\n");
						
					}
					
					break;
					
				case 7:	
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
					
				case 8:	
					printf("Informe o Cod a Ser Pesquisado Maior ou Igual a 1: ");
					scanf("%d",&cod);
					while(cod<1){
						printf("Informe o Cod a Ser Pesquisado Maior ou Igual a 1: ");
						scanf("%d",&cod);
					}
					ret=consultaPorPosicao(lt,cod,&dad);
					printf("Cod: %d\n",dad.cod);
					printf("Peso: %f\n",dad.peso);
					if(ret==SUCESSO){
						printf("Sucesso\n");
						
					}else if(ret == POSICAO_INVALIDA){
						printf("POSICAO INVALIDA\n");
					}
					
					break;
					
				case 9:	
					printf("Informe o Cod a Ser Pesquisado: ");
					scanf("%d",&cod);
					ret=existe(lt,cod);
					if(ret==1){
						printf("Existe Sucesso\n");
						
					}else if(ret==0){
						printf("NAO Existe\n");
					}		
					break;
					
				case 10:
					printf("Informe o Cod a Ser Pesquisado: ");
					scanf("%d",&cod);
					ret=consultaPorCodigo(lt,cod,&dad);
					printf("Cod: %d\n",dad.cod);
					printf("Peso: %f\n",dad.peso);
					if(ret==SUCESSO){
						printf("Sucesso\n");
						
					}else if(ret==CODIGO_INEXISTENTE){
						printf("POSICAO INVALIDA\n");
					}		
					break;
							
				case 11:		
					printf("Informe o Cod: ");
					scanf("%d",&dad.cod);
					printf("Informe o Peso: ");
					scanf("%f",&dad.peso);
					printf("Informe a Posicao Maior ou Igual a 1: ");
					scanf("%d",&pos);
					/*while (pos<1){
						printf("Informe a Posicao Maior ou Igual a 1: ");
						scanf("%d",&pos);
					}*/
					ret=incluiNaPosicao(&lt,pos,dad);
					if(ret == SUCESSO){
						printf("Sucesso\n");
					
					}else if(ret==POSICAO_INVALIDA){
						printf("POSICAO INVALIDA\n");
					}else if(ret==LISTA_CHEIA){
						printf("LISTA CHEIA\n");
					}
					
					break;
					
				case 12:	
					printf("Informe a Posicao Maior ou Igual a 1: ");
					scanf("%d",&pos);
					while (pos<1){
						printf("Informe a Posicao Maior ou Igual a 1: ");
						scanf("%d",&pos);
					}
					ret=excluiDaPosicao (&lt,pos,&dad);
					printf("Cod: %d\n",dad.cod);
					printf("Peso: %.f\n",dad.peso);
					if(ret==SUCESSO){
						printf("Sucesso\n");
					}else if(ret == POSICAO_INVALIDA){
						printf("Posicao Invalida\n");
					}
					break;
					
				case 13:	
					printf("Informe o Cod: ");
					scanf("%d",&dad.cod);
					printf("Informe o Peso: ");
					scanf("%f",&dad.peso);
					printf("Informe a Posicao A Ser Inserido Igual ou Maior Q 1: ");
					scanf("%d",&pos);
					while(pos<1){
						printf("Informe a Posicao A Ser Inserido Igual ou Maior Q 1: ");
						scanf("%d",&pos);
					}
					ret=incluiAntes(&lt,pos,dad);
					if(ret==SUCESSO){
						printf("Sucesso\n");
					
					}else if(ret==LISTA_CHEIA){
						printf("Lista Cheia\n");
						
					}else if(ret==CODIGO_INEXISTENTE){
						printf("Cod Nao Existe\n");
					}
					break;
					
				case 14:	
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
			}
			
				
		}
		exibe(lt); 	 
	 }while (op>=0 && op<=14);
	
	
	return 0;
}

