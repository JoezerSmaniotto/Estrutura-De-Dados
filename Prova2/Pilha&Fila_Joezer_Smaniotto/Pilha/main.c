#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

#include "funcoes.h"
#include "funcoes.c"

int main(){
	PilhaSE p;
	criaPilha(&p);
	int op,ret,cod;
	Funcionario d;
			
	 do{
		printf("0 -Fim\n");	
		printf("1 -Inclui Funcionario\n");	
		printf("2 -Exclui Funcionario\n");	
		printf("3 -Consulta a Existencia de Func.\n");	
		printf("4 -Exibe Funcionarios\n");
		printf("5 -Esta Vazia\n");
		
		
		scanf("%d",&op);
		if(op>=0 && op<=5){
			switch(op){
				case 0:	
					op=15; // Para Sair do Prog, seta op para 15
					break;
				
				case 1:		
					printf("Informe o Cod: ");
					scanf("%d",&d.cod);
					printf("Informe o Salario: ");
					scanf("%f",&d.salario);
					ret=empilha(&p,d);
					if(ret==SUCESSO){
						printf("Sucesso\n");
					}else if(ret==FALTOU_MEMORIA){
						printf("Erro MEMORIA CHEIA\n");
						
					}
					
					break;
					
				case 2:	
					
					ret=desempilha(&p,&d); 
					if(ret==SUCESSO){
						printf("Dado Excluido\n");
						printf("Cod: %d - Sal: %f\n",d.cod,d.salario);

					}else if(ret==PILHA_VAZIA) {
						printf("PILHA Vazia Sucesso\n ");
						
					}
					
					break;
					
				case 3:	
					printf("Informe o Cod: a Ser Pesquisado: ");
					scanf("%d",&cod);
					ret=consultaExistencia(p,cod);
					if(ret==SUCESSO){
						printf("Sucesso - Cod Existe:\n");
						//printf("Cod: %d - Sal: %f\n",d.cod,d.salario);
						
					}else if(ret==PILHA_VAZIA){
						printf("PILHA VAZIA\n");
					
					}else if(ret==CODIGO_INEXISTENTE){
						printf("CODIGO INEXISTENTE\n");
							
					}
					
					break;
					
				case 4:
					exibe(p);
					break;	
					
				case 5:
					ret=estaVazia(p);
					if(ret==0){
						printf("Pilha Nao Esta Vazia\n");
					}else if(ret==1){
						printf("Pilha Esta Vazia\n");
						
					}
					break;	
				break;
													
			}
			
			exibe(p); 	
		} 
		
    }while (op>=0 && op<=5); 
	
	return 0;
}
