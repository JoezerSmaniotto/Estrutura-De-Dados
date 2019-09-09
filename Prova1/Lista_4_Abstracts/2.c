#include <stdio.h>
#include <stdlib.h>

// Structs--------------------------------------------------------------------------------------------------------
typedef struct Circulo {
	int x,y;
	int raio;	
}Cir;


// Funções -------------------------------------------------------------------------------------------------------
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

int comparaCirculos(Cir circ1, Cir circ2){
	if( circ1.raio >  circ2.raio ){
		return 1;

	}else if(circ2.raio > circ1.raio){
			return -1;
		
	}else {
		return 0;
		
	}
	
	
}

void exibeCirculo(Cir circl){
	printf("Circulo X: %d\n",circl.x);
	printf("Circulo Y: %d\n",circl.y);
	printf("Circulo Raio: %d\n",circl.raio);
}

void moveCirculo ( Cir *circ,int nx,int ny){
		circ->x = circ->x + nx;
		circ->y = circ->y + ny;
}

void estaDentroDoCirculo(Cir *circ,int x,int y){
	//(Cx – Px)^2 + (Cy – Py)^2 < Raio^2
	if(( ((circ->x - x)*(circ->x - x)) +((circ->y - y)*(circ->y - y))) < (circ->raio * circ->raio)){
		printf("Esta Dentro da Circunferencia !!\n");
		
	}else {
		printf("Nao Esta Dentro da Circunferencia !!\n");
		
	}
	
}

// main ---------------------------------------------------------------------------------------------
int main(){
	Cir cir[2];	// como ira funcionar a questão de ler dois circulos ? for ??
	int i,r,x,y, retor,desX,desY;
		
	
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
	 //	comparaCirculos
	 i=0;
	 retor = comparaCirculos(cir[i],cir[i+1]);
	 if(retor == 1){
		 printf("Primeiro Circulo Maior Q o Segundo!\n");
	 
	 } else if (retor == -1){
			printf("Primeiro Circulo Menor Q o Segundo!\n");
		 
		 
	 }  else if (retor ==  0){
			printf("Primeiro Igual Ao Segundo!\n");
		 
	 } 
	 
	 //exibeCirculo
	 for(i=0;i<2;i++){
		exibeCirculo(cir[i]);	
	}
	
	// moveCirculo
	printf("Informe o Descolamento de X: ");
	scanf("%d",&desX);
	printf("Informe o Descolamento de Y: ");
	scanf("%d",&desY);
	
	moveCirculo(&cir[1],desX,desY);
	
	 //exibeCirculo
	printf("Circulo 2 Deslocado!\n");
	exibeCirculo(cir[1]);	
	
	
	
	return 0;
}

