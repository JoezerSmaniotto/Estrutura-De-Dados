#include <stdio.h>

void duplaClassificada(int *x,int *y){
	int soma, aux;
	soma=*x+*y;
	if(soma%2==0){ // Par crescente
		if(*x>*y){
			aux=*x;
			*x=*y;
			*y=aux;	
		}		

	}else {  // Impar Decrescente
	 
		if(*y>*x){
			aux=*y;
			*y=*x;
			*x=aux;
		}	
	}
	
}

 
int main (){
	int a,b;
	do{ 
	
		printf("Informe A e B: ");
		scanf("%d %d",&a,&b);
		duplaClassificada(&a,&b);
		printf("%d %d\n",a,b);
	
		}while(a!=-10000000);
	
	return 0;
}

