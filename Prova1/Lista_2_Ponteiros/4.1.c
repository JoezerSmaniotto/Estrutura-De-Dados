#include <stdio.h>
float calcDivisao(int x, int y, float *div ){
		*div=x / (float) y;
		if(y!=0){
			return 0;
		}else {
			return 1;
			
		}
	
}

int main(){
	float div, ret;
	int qt,x,y,i;
	printf("Informe a QT: ");
	scanf("%d",&qt);
	for(i=0;i<qt;i++){
		printf("Informe os Valores: ");
		scanf("%d%d",&x,&y);
		ret=calcDivisao(x,y,&div);
		if(ret==0){
			printf("%d / %d = %.2f\n",x,y,div);
			
		}else {
			printf("Divisao Por Zero!!\n");
			
		}	
	}
	
	
	
	return 0;
}

