
// Definição de Fnções

/*------------------------------------------------*/
void criaTalao(int numc,int numpc, talao *tal){
	tal->numCont = numc;
	int i,j;
	//Cheque cheq;
	for(i=0,j=numpc;i<10;i++,j++){
		criaCheque( j , &tal->che[i]);
		 //tal->che[i]= cheq;
		 //printf("Nr Ch: %d Valor Ch: %.2f Sit: %d\n",tal->che[i].num,tal->che[i].valor,tal->che[i].sit);
	}
		
}


void exibeTalao(talao tal){
	int i;
	printf("Numero Conta: %d\n",tal.numCont);
	printf("Cheques\n");
	for(i=0;i<10;i++){
		exibeCheque( tal.che[i]	);
	}
}

int emiteChequeDoTalao ( talao *tal, int nc, float val){
	int i, ret;	
	for(i=0;i<10;i++){
		if(obtemNumero(tal->che[i])==nc ){
			ret=emiteCheque(&tal->che[i], val);
				
		}
	
	}
	
	if(ret==0){
		return 0;
	}else{
		return 1;

	}

}

int compensaChequeDoTalao( talao *tal, int nc){
	int ret,i;
	for(i=0;i<10;i++){
		if(obtemNumero(tal->che[i])==nc){
			ret=compensaCheque(&tal->che[i]);		
		}
	}
	
	if(ret==0){
		return 0;
	}else{
		return 1;

	}
}


float somaChequesDoTalao( talao tal, int situ  ){
	int i;
	float vltot=0;
	for(i=0;i<10;i++){
		if( obtemSituacao(tal.che[i]) == situ){
			vltot=vltot+ obtemValor( tal.che[i]);
		}
	}
	return vltot;		
}

