#include <stdio.h>
#include <stdlib.h>

int main(){
	int q;
	printf("Informe a QT: ");
	scanf("%d",&q);
	int m[q],i,z,w[q],cont=0,j;
	
	for(i=0;i<q;i++){
		printf("Informe Um Valor Para a POS %d: ",i);
		scanf("%d",&m[i]);
	}
	
	printf("|");
	for(i=0;i<q;i++){
		printf("%d|",m[i]);
	}
	
	printf("\nInforme Um Valor: ");
	scanf("%d",&z);
	
	for(i=0,j=0;i<q;i++){
		if(m[i]>z){
			w[j]=m[i];
			j++;
			cont++;
		}	
	}
	
	printf("Vetor W\n|");
	for(i=0;i<cont;i++){
			printf("%d|",w[i]);
	}
	
	return 0;
}

