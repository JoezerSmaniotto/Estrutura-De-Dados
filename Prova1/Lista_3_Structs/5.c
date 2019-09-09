#include <stdio.h>

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
	Date dt[5],dth; 
	aln al[5];
	int i,j;
	for(i=0;i<5;i++){
		printf("Informe A Matricula do Aluno: ");
		scanf("%d",&al[i].matr);
		printf("Informe o dia de Nasc: ");
		scanf("%d",&al[i].dn.dia);		
		printf("Informe o mes de Nasc: ");
		scanf("%d",&al[i].dn.mes);
		printf("Informe o ano de Nasc: ");
		scanf("%d",&al[i].dn.ano);	
	}
	
	printf("Informe o Dia Atual: ");
	scanf("%d",&dth.dia);
	printf("Informe o Mes Atual: ");
	scanf("%d",&dth.mes);
	printf("Informe o Ano Atual: ");
	scanf("%d",&dth.ano);
	
	for(i=0,j=0;i<5;i++){
		if(dth.mes==al[i].dn.mes){
			dt[j].dia = al[i].dn.dia;
			dt[j].mes = al[i].dn.mes;
			dt[j].ano = al[i].dn.ano;
			j++;
		
		}
			
	}
	
	for(i=0;i<j;i++){
			printf("%d/%d/%d\n",dt[i].dia,dt[i].mes,dt[i].ano);
		
	}
	
	return 0;
}

