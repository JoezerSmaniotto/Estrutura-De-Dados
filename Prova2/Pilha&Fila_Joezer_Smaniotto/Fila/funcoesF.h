	// Structs
	typedef struct {
	 int num;
	 char cia[10];
	} Voo;

	typedef struct nodo Nodo;

	struct nodo {
	 Voo v;
	 Nodo *prox;
	};

	typedef struct {
	 Nodo *frente;
	 Nodo *re;
	} FilaSE;

	// Funcoes

	void criaFila(FilaSE *f);
	void exibeFila(FilaSE f);
	int quantidadeDeVoos(FilaSE f);
	int insere(FilaSE *f, Voo d);
	int retira (FilaSE *f, Voo *d);
	int consultaExistencia(FilaSE f,int cod);
