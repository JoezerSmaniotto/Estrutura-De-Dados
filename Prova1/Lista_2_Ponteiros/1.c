#include<stdio.h>

void duplaCrescente (int *x,int *y){
	int aux;	
	if(*x>*y){
		aux=*x;
		*x=*y;
		*y=aux;	
		
	}
	
}
 
 
int main (){
	int a,b;
	do{ 
	
		printf("Informe A e B: ");
		scanf("%d %d",&a,&b);
		if(a!=b){
			duplaCrescente (&a,&b);
			printf("%d %d\n",a,b);
		}
	}while(a!=b);
	printf("FIM\n");
	
	return 0;
}

