#include <stdio.h>

int main(){
	int hc,mc,ha,ma,hct,mct,horasC,horasA,horasT,horasAA,horasF=0,minF;
	printf("Informe Sua Hora De Chegada De Manha: ");
	scanf("%d",&hc);
	printf("Informe Seu Minuto De Chegada De Manha: ");
	scanf("%d",&mc);
	printf("Informe Sua Hora De Saida de Manha: ");
	scanf("%d",&ha);
	printf("Informe Sua Hora De Saida de Manha: ");
	scanf("%d",&ma);
	printf("Informe Sua Hora De Retorno Do Almoco: ");
	scanf("%d",&hct);
	printf("Informe os Minutos De Retorno Do Almoco: ");
	scanf("%d",&mct);
	horasC=(hc*60)+mc;
	horasA=(ha*60)+ma;
	//horasT=(hct*60)+mct;
	horasAA=horasA-horasC;
	horasT=525-horasAA;
	horasF=hct+(horasT/60);
	minF=mct+(horasT%60);
	if((minF)>=60){
		horasF+=1;
		minF-=60;	
	}
	printf("Hora de Saida: %d:%d\n",horasF,minF);
	
	return 0;
}

