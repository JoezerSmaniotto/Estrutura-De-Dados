// FUNÇÔES
void criaPilha(PilhaCF *p){
	p->topo=-1;	
}

int empilha( PilhaCF *p, Dado dado){
	if(p->topo == (MAX_NODOS-1)){
		return PILHA_CHEIA;
	
	} else{
		p->topo++;
		p->v[p->topo] = dado;
		return SUCESSO;
	}	
	
}

int desempilha(PilhaCF *p,Dado *dado){
	if(p->topo==-1){
		return PILHA_VAZIA;
	}else {
	
		*dado=p->v[p->topo];
		p->topo--;		
		return SUCESSO;
	}
}

int estaCheia(PilhaCF p){
	if(p.topo==(MAX_NODOS-1)){
		return PILHA_CHEIA;
	}else {
			
		return 0;
	}	
}

int estaVazia(PilhaCF p){
	if(p.topo==-1){
		return PILHA_VAZIA;
	}else {
		return 0;
	}	
}

int consulta(PilhaCF p,Dado *dado){
	if(p.topo > -1){ // Aqui testo se Não é Vazio;
		*dado = p.v[p.topo];
		//p.topo--;
		return SUCESSO;
	} else {
		return PILHA_VAZIA; 
		
	}
}

int pesquisa (PilhaCF *p, int cod, Dado *dado){
	
		if(p->topo==-1){     		// É Lista Vazio
			return PILHA_VAZIA;
		
		}else { 
			PilhaCF PP;             // Não é vazio  
			criaPilha(&PP);              
			while(p->v[p->topo].cod!=cod){
				PP.topo++;
				PP.v[PP.topo]=p->v[p->topo];
				p->topo--;
								
			}
			*dado=p->v[p->topo]; //p.topo--; Não decremento aqui mas subescrevo
			 p->topo++; // Assim não perdo o dado do elemento consultado

			 while (PP.topo > -1){ // Enpilho de volta
				 p->v[p->topo] = PP.v[PP.topo];
				 p->topo++;
				 PP.topo--; 
			 }
			  p->topo--; // vai uma a mais Aqui corrigo
			 return SUCESSO;
		}
}

void exibe (PilhaCF p) {
	int i;
	for(i=0;i<=p.topo;i++){
		printf("*****STATUS*****\n");
		printf("*****%d*****\n",i);
		printf("Cod: %d\n",p.v[i].cod);
		printf("Peso: %f\n",p.v[i].peso);		
	}	
}

