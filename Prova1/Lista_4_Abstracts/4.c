#include <stdio.h>
#include <stdlib.h>

// Structs
typedef struct Conta{
		int num;
		float saldo;
}Cont;

// Funções
void criaConta(Cont *cont, int Num){
	cont->num=Num;
	cont->saldo=0;
}

void depositaNaConta(Cont *cont, float valor){
	cont->saldo=cont->saldo+valor;
}

void retiraDaConta(Cont *cont, float valor){
	cont->saldo=cont->saldo-valor;
	
}

float obtemSaldo(Cont cont){
		
	return cont.saldo;
	
}

int main(){
	int numCC,numCP,op;
	Cont CC,CP;
	float valor=0,tot=0;
	
	printf("Informe o Numero da CC:");
	scanf("%d",&numCC);
	criaConta(&CC,numCC);
	printf("Informe o Numero da CP:");
	scanf("%d",&numCP);
	criaConta(&CP,numCP);
	
	do{
		printf("--------------------------------\n");
		printf("Escolha a OP:\n");
		printf("1-Deposito em Conta Corrente\n");
		printf("2-Deposito em Conta Poupanca\n");
		printf("3-Retirada em Conta Corrente\n");
		printf("4-Retirada em Conta Poupanca\n");
		printf("5-FIM\n");

		scanf("%d",&op);		
		if(op>=1 && op<5){
			if(op==1){
				printf("Informe o Valor a Ser Depositado Na CC: ");
				scanf("%f",&valor);
				depositaNaConta(&CC,valor);
				printf("--------------------------------\n");
				printf("CC STATUS - Atualizado\n");
				printf("Num CC: %.2f\n",CC.saldo);
				printf("CP STATUS - Atualizado\n");
				printf("Num CP: %.2f\n",CP.saldo);
				printf("--------------------------------\n");		
			
			}else if(op==2){
				printf("Informe o Valor a Ser Depositado Na CP: ");
				scanf("%f",&valor);
				depositaNaConta(&CP,valor);
				printf("--------------------------------\n");
				printf("CP STATUS - Atualizado\n");
				printf("Num CP: %.2f\n",CP.saldo);	
				printf("CC STATUS - Atualizado\n");
				printf("Num CC: %.2f\n",CC.saldo);
				printf("--------------------------------\n");
					
			}else if(op==3){
				printf("Informe o Valor a Ser Retirado Na CC: ");
				scanf("%f",&valor);
				if((CC.saldo - valor) < 0){	
						if( (CC.saldo + CP.saldo) > valor){
							tot=valor-CC.saldo;	
							retiraDaConta( &CP, tot);
							printf("--------------------------------\n");
							printf("CP STATUS - Atualizado\n");
							printf("Num CP: %.2f\n",CP.saldo);	
							printf("CC STATUS - Atualizado\n");
							printf("Num CC: %.2f\n",CC.saldo);
							depositaNaConta(&CC,tot);
							printf("--------------------------------\n");
							printf("CC STATUS - Atualizado\n");
							printf("Num CC: %.2f\n",CC.saldo);
							printf("CP STATUS - Atualizado\n");
							printf("Num CP: %.2f\n",CP.saldo);
							retiraDaConta( &CC, valor);
							printf("--------------------------------\n");
							printf("CC STATUS - Atualizado\n");
							printf("Num CC: %.2f\n",CC.saldo);
							printf("CP STATUS - Atualizado\n");
							printf("Num CP: %.2f\n",CP.saldo);	
							
						}else {
							printf("Saldo Insufucuente !!\n");				
				
						}
					
				}else {	
		
					retiraDaConta( &CC, valor);
					printf("\n--------------------------------\n");
					printf("CC STATUS - Atualizado\n");
					printf("Num CC: %.2f\n",CC.saldo);
					printf("CP STATUS - Atualizado\n");
					printf("Num CP: %.2f\n",CP.saldo);		
					
				}
				
					valor=0;
					tot=0;
				
			}else if(op==4){
				printf("\nInforme o Valor a Ser Retirado Na CP: ");
				scanf("%f",&valor);
				if(CP.saldo - valor > 0){
					retiraDaConta( &CP, valor);
					printf("--------------------------------\n");
					printf("CP STATUS - Atualizado\n");
					printf("Num CP: %.2f\n",CP.saldo);	
					printf("CC STATUS - Atualizado\n");
					printf("Num CC: %.2f\n",CC.saldo);
					
				}
				
				
			}
							
			
		
		}		
	}while(op>=1 && op<5);
	
	return 0;
}

