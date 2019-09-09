
// Definição de Fnções

/*------------------------------------------------*/
void criaCheque(int num ,Cheque *Che ){
	Che->num = num;
	Che->valor = 0;
	Che->sit = 0;
	
}
/*------------------------------------------------*/
int obtemSituacao( Cheque Che){
	
	return Che.sit;
}
/*------------------------------------------------*/
int obtemNumero( Cheque Che){
	
	return Che.num;
}
/*------------------------------------------------*/
int emiteCheque(Cheque *Che, float val){

	if(Che->sit == 0){    // Como assim esse retorno Seria a Situação ??
		Che->valor = val; // Errada Descrição  O cheque só pode ser compensado se a situação é igual a 0 (em branco)
		Che->sit = 1; // NO CASO NÃO É COMPENSADO E SIM EMITIDO
		return 0;
				
	} else {
		
		return 1;
	}
}
/*------------------------------------------------*/
void exibeCheque( Cheque Cheq){
	printf("Numero: %d Valor: %.2f Situacao: %d\n",Cheq.num,Cheq.valor,Cheq.sit);
	
}
/*------------------------------------------------*/
float obtemValor( Cheque Che){
	
	return Che.valor;
}
/*------------------------------------------------*/
int compensaCheque(Cheque *Che){

	if(Che->sit == 1){
		Che->sit = 2;
		return 0;
		
	}else {
		
		return 1;	
	}
}
