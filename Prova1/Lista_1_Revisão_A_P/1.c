#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int qt,cd,i,contF=0;
	float alt,acmAlt=0,medAlt=0,MaisAlt=0;
	
	printf("Informe A Qt de Alunos da Turma: ");
	scanf("%d",&qt);
	
	for(i=0;i<qt;i++){
		printf("Informe 'Altura' & Cod: 1 M - 2 F: ");
		scanf("%f %d",&alt,&cd);
		// Encontra aluno Mais Alto
		if( (cd==1) && alt>MaisAlt){
			//printf("Primeiro IF Alt");
			MaisAlt=alt;
			//printf("Altura: %f - Mais Alto: %f\n",alt,MaisAlt);
		}
		// Faz a Média das Alunas Mais altas
		if(cd==2){
			//printf("Segundo IF Alt");
			acmAlt=acmAlt+alt;
			contF++;
			//printf("AcmAlt: %f - Alt: %f\n",acmAlt,alt);
			//printf("Contador Meninas %d\n",contF);
		}
	}
	
	//printf("AcmAlt: %f\n",acmAlt);
	//printf("ContF: %d\n",contF);
	medAlt=acmAlt/contF;
	printf("O Aluno Mais Alto Med: %f\n",MaisAlt);
	printf("A Med Da Altura Das Alunas: %f\n",medAlt);
	
	return 0;
}

