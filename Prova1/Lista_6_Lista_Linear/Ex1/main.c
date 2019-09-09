



#include <stdio.h>
#include <stdlib.h>	
#define MAX_NODOS 5
#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define POSICAO_INVALIDA 3
#define CODIGO_INEXISTENTE 4
#define INDICE_INVALIDO 6
#include "LL.h"
#include "LL.c"


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
		 	 
	 }while (op>=0 && op<=14);
	
	
	return 0;
}
/*   int excluiDaPosicao (ListaCF *lt, int pos, Dado *nodo){ 
     CODIGO_INEXISTENTE NÂO TEM > INDICE_INVALIDO
 */
