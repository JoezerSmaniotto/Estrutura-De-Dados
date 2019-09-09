#include <stdio.h>

int main(){
	int l,c;
	printf("Informe Um Valor P/ Linhas e Colunas: ");
	scanf("%d %d",&l,&c);
	int m[l][c],i,j,num,op=0;
	
	// Lê a Matriz
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("Valor: %d:%d:: ",i,j);	
			scanf("%d",&m[i][j]);
		}	
	}
	// Printa a Matriz
	for(i=0;i<l;i++){
		printf("|");
		for(j=0;j<c;j++){
			printf("%d|",m[i][j]);	
		}	
		printf("\n");
	}
	
	printf("Informe Um Numero a Ser Pesq: ");
	scanf("%d",&num);
	
	// Encontra Valores
	while(num>0){
		for(i=0;i<l;i++){
			for(j=0;j<c;j++){
				if(num==m[i][j]){
					op=1;
					break;
					
				} /*else{
					op=0;
				}*/
			}
		}

		
		if(op==1){
			printf("Está na matriz !\n");
			
			
		} else if(op==0){
			printf("Não Está na matriz !\n");

		}
		
		op=0;
		printf("Informe Um Numero a Ser Pesq: ");
		scanf("%d",&num);
	}
		
	
	return 0;
}

