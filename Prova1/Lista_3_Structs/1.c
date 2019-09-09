#include <stdio.h>

struct Horarario{
		int hora;
		int min;
		int seg;
	
};

int main(){
	struct Horarario hr;
	
	printf("Informe Hora: ");
	scanf("%d",&hr.hora);
	printf("Informe Minuto: ");
	scanf("%d",&hr.min);
	printf("Informe Segundos: ");
	scanf("%d",&hr.seg);
	
	printf("%d:%d:%d\n",hr.hora,hr.min,hr.seg);
	
	
	return 0;
}

