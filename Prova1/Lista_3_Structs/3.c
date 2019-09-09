#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
		int dia;
		int mes;
		int ano;
	
} Date;

typedef struct aluno{
		int matr;
		Date dn;

}aln;


int main(){
	aln al;
	
	printf("Informe A Matricula do Aluno: ");
	scanf("%d",&al.matr);
	printf("Informe o dia de Nasc: ");
	scanf("%d",&al.dn.dia);
	printf("Informe o mes de Nasc: ");
	scanf("%d",&al.dn.mes);
	printf("Informe o ano de Nasc: ");
	scanf("%d",&al.dn.ano);

	printf("Matricula: %d\n",al.matr);
	printf("%d/%d/%d\n",al.dn.dia,al.dn.mes,al.dn.ano);
	
	
	
	return 0;
}

