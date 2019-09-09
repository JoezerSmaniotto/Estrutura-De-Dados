#include <stdio.h>
#include <stdlib.h>

void exibeOnzeTracos (){
	int i;
	for(i=0;i<11;i++){
		printf("-");
	}
	printf("\n");
}

void retanguloTracos(){
	int i;
	for(i=0;i<4;i++){
		exibeOnzeTracos();
	}

}


int main(){
	
	retanguloTracos();
	printf("\n\n");
	retanguloTracos();
	
	
	
	
	return 0;
}

