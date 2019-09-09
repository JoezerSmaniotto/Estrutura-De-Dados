#include <stdio.h>
#include <stdlib.h>

//Strutcs 
typedef struct Ponto{
	int x,y;

}pont;

typedef struct Retangulo{
	pont sup;
	pont inf;
	
}ret;

// Funções
void criaRetangulo (int xs,int ys,int xi,int yi,ret *retag){
	retag->sup.x=xs;
	retag->sup.y=ys;
	retag->inf.x=xi;
	retag->inf.y=yi;
}

float areaRetangulo(ret retag){
		float ladx, lady,area;
		ladx = retag.sup.x - retag.inf.x;
		lady = retag.inf.y - retag.sup.y;
		area=ladx * lady;
		return area;
}
	
// Main
int main(){
	int xs,ys,xi,yi;
	ret retang;
	float aream;
	
	printf("Informe Os Ponto Superior X & Y: ");
	scanf("%d%d",&xs,&ys);
	printf("Informe Os Ponto Inferior X & Y: ");
	scanf("%d%d",&xi,&yi);
	
	criaRetangulo ( xs, ys, xi, yi, &retang);
	aream = areaRetangulo(retang);
	printf("Area: %.2f\n",aream);
	
	return 0;
}

