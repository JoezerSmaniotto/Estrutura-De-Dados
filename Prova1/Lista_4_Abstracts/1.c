#include <stdio.h>
#include <stdlib.h>

typedef struct Circulo {
	int x,y;
	int raio;	
}Cir;

void criaCirculo(int ccx, int ccy,int raio, Cir *circ){
	circ->x=ccx;
	circ->y=ccy;
	circ->raio=raio;
}

float perimetroCirculo(Cir circ){
	float pi=3.14,peri;
	peri= (2 * pi) * (circ.raio);
	
	return peri; 
}

float areaCirculo(Cir circ){
	float pi=3.14,area;
	area = pi * (circ.raio * circ.raio);
	
	return area; 
}


int main(){
	Cir cir[2];	// como ira funcionar a questão de ler dois circulos ? for ??
	int i,r,x,y,pos;
	float per, area[2],aux=0;	
	
	for(i=0;i<2;i++){
		printf("Informe o Raio: ");
		scanf("%d",&r);
		printf("Informe a Cord X: ");
		scanf("%d",&x);
		printf("Informe a Cord Y: ");
		scanf("%d",&y);
		criaCirculo(x,y,r, &cir[i]); // &cir[i] pq é um paremetro de saída a pos passar os dados 
		// cria o circulo com as atribuições feitas	
		
	}
	
			
	// Como armazenar as area ? os dois estou mexendo com circulos aonde armazenas para poder comparar ? se for em variavel ok ?
	//  mas se fosse varias circulos ?? iria armazenas em variavel ? não seria melhor criar um vetor  ?
		
	
	// Calculo a area do circulo e armazeno no vetor apos para depois encontrar a maior area e calcular o perimetro do maior circulo.
	for(i=0;i<2;i++){	
		area[i] = areaCirculo(cir[i]);	
		printf("Area Circulo %d: %f\n",i,area[i]);
	}
	
	// Printo o perimetro do maior circulo de acordo com o circulo que tem a area maior.
	for(i=0;i<2;i++){
		if(aux<area[i]){
			aux=area[i];
			pos=i;
		}
	}
	// agora printo a perimetro do circulo com o maior area.
	per = perimetroCirculo(cir[pos]);
	printf("Area do Circulo com maior area: %f\n",per);
	return 0;
}

