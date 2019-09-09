#define MAX_NODOS 5

// Structs
			
typedef struct {
	int cod;
	float peso;
} Dado;  

typedef struct {
	int n;
	Dado v[MAX_NODOS];
} ListaCF;  
  
	  
// Funções
	
void criaLista (ListaCF *lt);
void exibe(ListaCF lt);
int estaCheia( ListaCF lt);
int estaVazia (ListaCF lt);
int excluiDoFim ( ListaCF *lt, Dado  *d);
int excluiDoInicio(ListaCF *lt,Dado *d);
int existe( ListaCF lt, int codg);
int incluiNaPosicao(ListaCF *lt, int pos, Dado dad);
int incluiAntes(ListaCF *lt, int cod, Dado dad);
int incluiNoFim (ListaCF *lt, Dado dad);
int quantidadeDeNodos(ListaCF lt);
int incluiNoInicio(ListaCF *lt, Dado dad);
int consultaPorPosicao( ListaCF lt, int pos, Dado *dad);
int consultaPorCodigo(ListaCF lt, int codd,Dado *dad);
int excluiDaPosicao (ListaCF *lt, int pos, Dado *nodo);
int excluiNodo (ListaCF *lt, int cod, Dado *nodo);

