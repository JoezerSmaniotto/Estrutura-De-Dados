#include <stdio.h>
#include <stdlib.h>

struct endereco{
	char rua [50];
	int numero;	
};

struct pessoa {
	char nome [50];
	int idade;
	struct endereco end;
}

int main(){
	
	struct pessoa p;
	
	p.idade = 25;
	p.end.numero = 82; 
	
	return 0;
}

