#include <stdio.h>
#include <std.h>

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
	Date dth;
	aln al;
	
	printf("Informe o Dia Atual: ");
	scanf("%d",&dth.dia);
	printf("Informe o Mes Atual: ");
	scanf("%d",&dth.mes);
	printf("Informe o Ano Atual: ");
	scanf("%d",&dth.ano);
	
	do{
		printf("Informe A Matricula do Aluno: ");
		scanf("%d",&al.matr);
		printf("Informe o dia de Nasc: ");
		scanf("%d",&al.dn.dia);
		if(al.dn.dia != 99){
			printf("Informe o mes de Nasc: ");
			scanf("%d",&al.dn.mes);
			printf("Informe o ano de Nasc: ");
			scanf("%d",&al.dn.ano);	
			
						
			if( (dth.ano - al.dn.ano) > 18 ){
				
				printf("Maior de Idade\n");
				
				
			} else if( ((dth.ano - al.dn.ano) == 18) && (dth.mes > al.dn.mes)  ){
					printf("Maior de Idade\n");
					
				
				} else if ( ((dth.ano - al.dn.ano) == 18)  && (dth.mes == al.dn.mes) && (dth.dia >= al.dn.dia)  ){ 
						
						printf("Maior de Idade\n");
						
					
					} else{
						printf("Menor de Idade\n");	
						
					}
							
			
		}
		
	}while(al.dn.dia != 99);
	
	
	return 0;
}

