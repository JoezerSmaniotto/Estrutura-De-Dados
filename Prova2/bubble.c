/*m?todo de classifica??o bubblesort*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

#define MAX 100

void bubbleSort(int v[MAX]);
void geraVetor(int v[MAX]);
void exibe(int v[MAX]);


int main(){
	setlocale(LC_ALL,"Portuguese"); 
	int v[MAX],ti,tf;
	geraVetor(v);
	//exibe(v);
	system("pause");
	ti = time(NULL);
	bubbleSort(v);
	tf = time(NULL);
	exibe(v);
	printf("Tempo de ordena??o: %d s\n",tf-ti);
	system("pause");
	return 0;
}

void geraVetor(int v[MAX]){ //gera vetor de inteiros aleat?rios 
	int i;
	for(i=0;i<MAX;i++){
		v[i] = rand();
	}		
}

void exibe(int v[MAX]){ //imprime na tela o vetor
	int i;
	for(i=0;i<MAX;i++)
		printf("%d - ", v[i]);
	printf("\n");
}

void bubbleSort(int v[MAX]){ // Ordena
	int troca=1,i=0,aux;
	do{
		for(i=0;i<MAX;i++){
			if(v[i] > v[i+1]){
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				troca=0;
			}
		}
	}while(troca==0);
		
}
