#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2
#define NUMERO_INEXISTENTE 3
#include "funcoesF.h"
#include "funcoesF.c"

int main(){
	FilaSE f;
	criaFila(&f);
	int op,ret,cod;
	Voo d;
			
	 do{
		printf("0 -Fim\n");	
		printf("1 -Insere Voo\n");	
		printf("2 -Retira um Voo\n");	
		printf("3 -Consulta a existência de um voo\n");	
		printf("4 -Qtd de Avioes\n");
		printf("5 -Exibe\n");
		
		
		scanf("%d",&op);
		if(op>=0 && op<=5){
			switch(op){
				case 0:	
					printf("EXIT\n");
					op=15; // Para Sair do Prog, seta op para 15
					break;
				
				case 1:		
					printf("Informe o Cod: ");
					scanf("%d",&d.num);
					printf("Informe o Nome da Empresa Aerea: ");
					scanf("%s",d.cia); // %[^\n]s
					ret=insere(&f,d);
					if(ret==SUCESSO){
						printf("Inserido Com Sucesso\n");
					}else if(ret==FALTOU_MEMORIA){
						printf("Erro MEMORIA CHEIA\n");
						
					}
					
					break;
					
				case 2:	
					
					ret=retira(&f,&d); 
					if(ret==SUCESSO){
						printf("*****Dado Excluido*****\n");
						printf("Num VOO: %d\n",d.num);
						printf("Empressa Aerea: %s\n",d.cia);
						printf("************************\n");
					}else if(ret==FILA_VAZIA) {
						printf("Fila Vazia\n ");
						
					}
					
					break;
					
					
				case 3:	
					printf("Informe o Cod: ");
					scanf("%d",&cod);
					ret=consultaExistencia(f,cod);
					if(ret==SUCESSO){
						printf("Sucesso - Voo Existe:\n");
						
					}else if(ret==FILA_VAZIA){
						printf("FILA VAZIA\n");
					
					}else if(ret==NUMERO_INEXISTENTE){
						printf("Voo Inexistente\n");
							
					}
					
					break;
					
				case 4:
					ret=quantidadeDeVoos(f);
					printf("QT Aviao: %d\n",ret);
					break;		
					
				case 5:
					if(f.frente !=NULL && f.re!= NULL){
						exibeFila(f);
					}
					break;
														
			}
			exibeFila(f); 	
		} 
    }while (op>=0 && op<=5); 
	return 0;
}
