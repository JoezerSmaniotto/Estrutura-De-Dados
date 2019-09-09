// STRUCTS
typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct {
	int topo;
	Dado v[MAX_NODOS];
}PilhaCF;

// FUNÇÔES
void criaPilha(PilhaCF *p);

int empilha( PilhaCF *p, Dado dado);
int desempilha(PilhaCF *p,Dado *dado);
int estaCheia(PilhaCF p);
int estaVazia(PilhaCF p);
int consulta(PilhaCF p,Dado *dado);
int pesquisa (PilhaCF *p, int cod, Dado *dado);
void exibe (PilhaCF p);
