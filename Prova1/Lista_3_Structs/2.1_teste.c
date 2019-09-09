#include <stdio.h>
#include <stdlib.h>


typedef struct Horarario{
		int hora;
		int min;
		int seg;
	
} hor;


int main(){
	hor time1,time2;

		printf("Informe Hora: ");
		scanf("%d",&time1.hora);
		printf("Informe Minutos: ");
		scanf("%d",&time1.min);
		printf("Informe Segundos: ");
		scanf("%d",&time1.seg);	
		
		printf("Informe Hora: ");
		scanf("%d",&time2.hora);
		printf("Informe Minutos: ");
		scanf("%d",&time2.min);
		printf("Informe Segundos: ");
		scanf("%d",&time2.seg);	
		
		if(time2 > time1){
				printf("%d:%d:%d\n",time1.hora,time1.min,time1.seg);
			
		} else if (time1 > time2) {
				printf("%d:%d:%d\n",time2.hora,time2.min,time2.seg);
			
			} else {
				printf("Horarios Iguais !!\n");	
				
			}


	
	return 0;
}

