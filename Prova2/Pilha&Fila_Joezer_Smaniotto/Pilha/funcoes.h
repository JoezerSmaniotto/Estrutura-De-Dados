#ifndef Cheque_h
#define Cheque_h

	// Structs
	typedef struct {
		int num;
		float valor;
		int sit;
	}Cheque;// Structs
	typedef struct {
	 int cod;
	 float salario;
	} Funcionario;

	typedef struct nodo Nodo;

	struct nodo {
	 Funcionario func;
	 Nodo *prox;
	};

	typedef struct {
	 Nodo *topo;
	 
	} PilhaSE;

	
	// Funções
	int empilha( PilhaSE *p, Funcionario dado);
	int desempilha (PilhaSE *p, Funcionario *dado);
	int estaVazia(PilhaSE p);
	int consultaExistencia(PilhaSE p,int cod);
	void exibe(PilhaSE p);


#endif
