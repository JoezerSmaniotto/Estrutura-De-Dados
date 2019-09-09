#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void exibeDivisores(int div){
	int i;
	printf("%d: ",div);
	for(i=1;i<=div;i++){
		if(div%i==0){
			printf(" %d ",i);
		}
	}
	printf("\n");	
}



int main(){
	int i;
	
	for(i=1;i<=20;i++){
		exibeDivisores(i);	
	}
	
	
	return 0;
}

