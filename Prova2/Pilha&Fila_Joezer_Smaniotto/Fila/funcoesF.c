
// Funcoes

void criaFila(FilaSE *f){
	f->frente=NULL;
	f->re=NULL;
}

void exibeFila(FilaSE f){
	if(f.frente != NULL && f.re != NULL){	
		Nodo *pNodo;
		pNodo=f.frente;
		printf("*********EXIBE FILA*********\n");
		while(pNodo != NULL){
			printf("COMP: %s  - VOO: %d\n",pNodo->v.cia,pNodo->v.num);
			printf("************************\n");
			pNodo=pNodo->prox;
		}	
	}	
}


int quantidadeDeVoos(FilaSE f){
	int cont=0;
	Nodo *pAux;
	pAux=f.frente;
	while(pAux != NULL){
		cont++;
		pAux = pAux->prox;
	}
	return cont;
}

int insere(FilaSE *f, Voo d){
	 Nodo *pNodo;
	 pNodo = (Nodo *) malloc (sizeof (Nodo));
	 if (pNodo == NULL){
		return FALTOU_MEMORIA;
	
	 } else if(f->frente == NULL && f->re == NULL){
			
			 pNodo->v=d; 
			 pNodo->prox=NULL;
			 f->frente=pNodo;
			 f->re=pNodo;
			 return SUCESSO;
	 
	 }else if(f->frente != NULL && f->re != NULL) { 
			Nodo *pAux;
			pAux=f->frente;
			while(pAux->prox != NULL){
				pAux = pAux->prox;
			}
			pNodo->v=d;						
			pNodo->prox=NULL;
			pAux->prox=pNodo;
			f->re=pNodo;
			return SUCESSO;		 
	 }
	
}

int retira (FilaSE *f, Voo *d){
	if(f->frente == NULL && f->re == NULL){
		return FILA_VAZIA;
		
	}else if(f->frente->prox == NULL && f->re->prox == NULL){
		
		Nodo *pAux;
		*d=f->frente->v;
		pAux=f->frente;
		f->frente=NULL;
		f->re=NULL;
		free(pAux);
		return SUCESSO;
		
	}else {
		Nodo *pAux;
		*d=f->frente->v;
		pAux=f->frente;
		f->frente=f->frente->prox;
		free(pAux);
		return SUCESSO;
		
	}	
}


int consultaExistencia(FilaSE f,int cod){
	if(f.frente == NULL  &&  f.re == NULL){
		return FILA_VAZIA;
	
	}else {
		
		Nodo *pAux;
		pAux=f.frente;
		while(pAux != NULL){
			if(pAux->v.num == cod){
				return SUCESSO;
			}
			pAux= pAux->prox;
		}
		return NUMERO_INEXISTENTE;
	}	
}
