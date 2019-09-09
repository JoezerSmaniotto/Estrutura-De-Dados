
// Funções
void criaPilha(PilhaSE *p){
	p->topo = NULL;	
}

int empilha( PilhaSE *p, Funcionario dado){
	 Nodo *pNodo;
	 pNodo = (Nodo *) malloc (sizeof (Nodo));
	 if (pNodo == NULL){
		return FALTOU_MEMORIA;
	
	 } else {
		 pNodo->func=dado;
		 pNodo->prox=p->topo;
		 p->topo=pNodo;
		 return SUCESSO;
	 }
	
}

int desempilha (PilhaSE *p, Funcionario *dado){
	if(p->topo == NULL){
		return PILHA_VAZIA;
	}else {
		
		Nodo *pTemp;
		*dado=p->topo->func;
		pTemp=p->topo;
		p->topo=p->topo->prox;
		free(pTemp);
		return SUCESSO;			
	}
			
}

int estaVazia(PilhaSE p){
	if(p.topo == NULL){
		return 1;
	}else {
		return 0;
	}	
}

int consultaExistencia(PilhaSE p,int cod){
	if(p.topo == NULL){
		return PILHA_VAZIA;
	
	}else {
		
		Nodo *pAux;
		pAux=p.topo;
		while(pAux != NULL){
			if(pAux->func.cod == cod){
				return SUCESSO;
			}
			pAux= pAux->prox;
		}
		return CODIGO_INEXISTENTE;
	}	
}

void exibe(PilhaSE p){
	if(p.topo != NULL){
		Nodo *pAux;
		pAux=p.topo;
		printf("EXIBE LISTA FUNCIONARIO\n");
		while(pAux!=NULL){
			printf("Cod: %d - Sal: %f\n",pAux->func.cod,pAux->func.salario);
			pAux=pAux->prox;
		}
		
	}
}



