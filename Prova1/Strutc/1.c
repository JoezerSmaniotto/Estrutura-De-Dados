#include <stdio.h>
#include <stdlib.h>

struct pessoa {
	char nome[50],rua[50];
	int idade, numero;
	
};

int main(){
	
	struct pessoa p;
	
	scanf("%s",p.nome);
	printf("Nome: %s\n",p.nome);
	

	
	
	
	return 0;
}

