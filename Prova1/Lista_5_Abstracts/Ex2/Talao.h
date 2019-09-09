#ifndef Talao_H
#define Talao_H

	// Structs
			
	typedef struct {
		int numCont;
		Cheque che[10];			
	}talao;
	  
	// Funções
	void criaTalao(int numc,int numpc, talao *tal);
	void exibeTalao(talao tal);
	int emiteChequeDoTalao ( talao *tal, int nc, float val);
	int compensaChequeDoTalao( talao *tal, int nc);
	float somaChequesDoTalao ( talao tal, int situ  );


#endif
