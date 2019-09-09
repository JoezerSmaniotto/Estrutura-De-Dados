#include <stdio.h>

typedef struct Horarario{
		int hora;
		int min;
		int seg;
	
} hor;


int main(){
	hor time[2];
	int i;
	for(i=0;i<2;i++){
		printf("Informe Hora: ");
		scanf("%d",&time[i].hora);
		printf("Informe Minutos: ");
		scanf("%d",&time[i].min);
		printf("Informe Segundos: ");
		scanf("%d",&time[i].seg);	
	}
	
	if(time[0].hora > time[1].hora){
		printf("%d:%d:%d\n",time[1].hora,time[1].min,time[1].seg);
		
	}else if ( time[1].hora > time[0].hora ){
				printf("%d:%d:%d\n",time[0].hora,time[0].min,time[0].seg);
		
			} else if( time[0].min > time[1].min){ // hora aqui é igual
						printf("%d:%d:%d\n",time[1].hora,time[1].min,time[1].seg);
				
				} else if ( time[1].min >  time[0].min){
							printf("%d:%d:%d\n",time[0].hora,time[0].min,time[0].seg);
					
					} else if ( time[0].seg > time[1].seg){ // aqui hora e minutos são iguais
								printf("%d:%d:%d\n",time[1].hora,time[1].min,time[1].seg);
						
						} else if ( time[1].seg > time[0].seg ){
									printf("%d:%d:%d\n",time[0].hora,time[0].min,time[0].seg);
							
							}else {
								printf("Horarios Iguais ! !\n");
									
							}
	
	
	
	
	return 0;
}

