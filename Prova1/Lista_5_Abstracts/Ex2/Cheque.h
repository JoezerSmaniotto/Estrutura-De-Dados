#ifndef Cheque_H
#define Cheque_H

	// Structs
	typedef struct {
		int num;
		float valor;
		int sit;
	}Cheque;
	
	// Funções
	void criaCheque(int num ,Cheque *Che );
	int obtemSituacao( Cheque Che);
	int obtemNumero( Cheque Che);
	int emiteCheque(Cheque *Che, float val);
	void exibeCheque( Cheque Cheq);
	float obtemValor( Cheque Che);
	int compensaCheque(Cheque *Che);


#endif
