#include <stdio.h>

int main(){
	int x=10;
	int *p=&x;
	int **p2=&p;
	
	// Endereço p2
	printf("p2: %d\n",p2);  //&p
	//Conteudo do endereço
	printf("*p2: %d\n",*p2);
	//Conteudo do endereço do endereço
	printf("**p2: %d\n",**p2);
	
	
	
	return 0;
}

