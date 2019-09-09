#include<stdio.h>
float calcDivisao(float x, int y){
	float div;
	div=x/y;
	if(y==0){
		return 1;
	}else {
	
		return div;
	}
	
}

int main (){
	int n,b,i;
	float a,resp=0;
	printf("Informe Um Valor a Ser Repetido: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Informe 2 valores: ");
		scanf("%f%d",&a,&b);
		resp=calcDivisao(a,b);	
		
		if(resp==1 && b==0){
			printf("Divisão por zero\n");
			
		
		} else{
				printf("%.1f\n",resp);
			
		}
		
	}
	return 0;
}

