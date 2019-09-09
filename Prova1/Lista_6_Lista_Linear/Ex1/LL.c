// Definição de Funções

/*------------------------------------------------*/
// Entrada uma Ponteiro de uma Lista
// Saida Uma lista Criada
//1
void criaLista (ListaCF *lt) {
	lt->n = 0;
}

// Entrada uma lista   
//2
void exibe(ListaCF lt){
	int i;
	for(i=0;i < lt.n;i++){
		printf("***** %d *****\n",i);
		printf("Cod: %d.\n",lt.v[i].cod);
		printf("Peso: %.2f KG.\n",lt.v[i].peso);
	}	
}
// Entrada uma lista 
// Saída 1 = Cheia 0 caso contrario.
//3
int estaCheia( ListaCF lt){
	if(lt.n == MAX_NODOS){ 
		return 1;
		
	} else {
		return 0; 
		
	}	
}



// Entrada uma lista
// Retorno Um int que diz se a lista esta vazia = 1, contrario 0.
//4
int estaVazia (ListaCF lt){
	if(lt.n == 0){
		return 1;
	}else {
		return 0;
	}
}
// 5
int excluiDoFim ( ListaCF *lt, Dado  *d){   
	if( lt->n==0 ){ // É assim que faço para passar o ponteiro de que recebo de uma função, para outro função ???????  ?????
		return LISTA_VAZIA;  // Caso esteja errado fazer  if (lt->n==0){ return LISTA_VAZIA;}
		
	}else {
		*d = lt->v[lt->n-1];
		// n-1 por causa que inicia no zero, então menos 1 para pega o ultimo
		lt->n--;
		return SUCESSO;
	}
}
//6
int excluiDoInicio(ListaCF *lt,Dado *d) {
	 int i;
	 if (lt->n==0){                               // Aqui poderia usar a função esta vazia ???? ????
		return LISTA_VAZIA;
	 }
	 else {
		 *d = lt->v[0];
		 for (i=1; i<lt->n; i++){ // Deslocamento
			 lt->v[i-1] = lt->v[i];
		 }
		 lt->n--;
		 return SUCESSO;
	 }
} 

//7
int existe( ListaCF lt, int codg){
	// tem se não da erro
	int i,tem=0;
	for(i=0;i<lt.n;i++){
		if(lt.v[i].cod == codg){
			tem=1;
			break;
		}
	}
	
	if (tem==1){
		return 1;
	
	}else {
		return 0;	
	}
}
//8
int incluiNaPosicao(ListaCF *lt, int pos, Dado dad){	
	if(lt->n==MAX_NODOS){
		return LISTA_CHEIA;
		
	}else if((lt->n == 0) && pos < MAX_NODOS){  // Certo isso para lista que esta vazia ?? Ou Não faz ??????
		lt->v[pos]=dad;
		lt->n++;
		return SUCESSO;
	}else if(pos >= MAX_NODOS){
			return POSICAO_INVALIDA;
		
	}else if(pos == (lt->n -1)){  // Aqui quando adiciono no final no ultima posição do vetor              ?????
		lt->v[pos]=dad;           //Não deveria incrementar antes de   lt->n++;
		lt->n++;
		return SUCESSO;
	}else {
		// Inclui ver professor fiz diferente 
		//lt->n++;                                 // Aqui faço diferente ??????
		int i;
		for(i=lt->n;i>pos;i--){
			lt->v[i]=lt->v[i-1];  // == lt->v[n]=lt->v[n-1];				  
		}
		lt->v[pos]=dad;
		lt->n++;
		return SUCESSO;
	}
		
}
	
//
//9
int incluiAntes(ListaCF *lt, int cod, Dado dad){
	int i,pos,flag=0;
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
		
	}else if((lt->n) < MAX_NODOS){
		// Descobre aonde se encontra o Cod para descobrir aonde será inserido.
		for(i=0;i< lt->n;i++){
		//printf("Cod: %d COD IN: %d\n",cod,lt->v[i].cod);
			if(cod == lt->v[i].cod){
				//printf("Cod: %d i: %d\n",cod,i);
				flag=1;
				pos=i;
				break;
			}
		}
		// 
		if(flag==1){
			for(i=lt->n;i>=pos;i--){  
				lt->v[i]=lt->v[i-1];  				  
			}
			lt->v[pos-1]=dad;
			lt->n++;
			return SUCESSO;
			
		} else if(flag==0){
			return CODIGO_INEXISTENTE;
					
		}
	}
	
}
//10
int incluiNoFim (ListaCF *lt, Dado dad){
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}else {
		lt->v[lt->n]=dad; // tem q ser o lt-> para não subscreve o valor q era o ultimo e passou a ser o penultimo. 
		lt->n++;
		return SUCESSO;
	}

}
//11
int quantidadeDeNodos(ListaCF lt){
	return lt.n;
}
//12
int incluiNoInicio(ListaCF *lt, Dado dad){
	int i;
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	
	}else{
		for(i=lt->n; i>=1 ;i--){
			lt->v[i]=lt->v[i-1];		
		}
		lt->v[0]=dad;
		lt->n++;
		return SUCESSO;	
	} 
	
}
//13
int consultaPorPosicao( ListaCF lt, int pos, Dado *dad){
	//if(lt.n > 0){ // Testa se é vazia
		if(pos < lt.n){ // Testa a posição.
			*dad = lt.v[pos];
			return SUCESSO;
		
		}else{
			return POSICAO_INVALIDA;
		
		} 		
	//}		
}
//14
int consultaPorCodigo(ListaCF lt, int codd,Dado *dad){
	int i,pos,sel=0;
	//if(lt.n > 0){ // Testa se é vazia
	for(i=0;i<lt.n;i++){
		if(lt.v[i].cod == codd){
			pos=i;
			sel=1;
			break;
		}
	}
	if(sel==1){
		*dad=lt.v[pos];
		return SUCESSO;
	
	}else if(sel==0){
		return CODIGO_INEXISTENTE;
		
	}
		
//}
}
//15
int excluiDaPosicao (ListaCF *lt, int pos, Dado *nodo){ // o que é o nodo ? É o dado ????
	int i;
	if(lt->n-1 == pos){ // Para excluir o ultimo nodo.
		*nodo = lt->v[pos];
		lt->n--;
		return SUCESSO;
			
	} else if(pos < lt->n){ // Quando o nodo excluido não é o ultimo.
		*nodo = lt->v[pos];
		for (i=pos; i < lt->n; i++){
			lt->v[i] = lt->v[i+1];
		}
		lt->n--;
		return SUCESSO;
		
	} else if(pos > lt->n){
		return POSICAO_INVALIDA; //indice invalido seria no caso POSIÇÕE MAIORES Q N ??????
		
	}
	
}
//16
int excluiNodo (ListaCF *lt, int cod, Dado *nodo){
	int i,pos;
	for(i=0;i < lt->n ;i++){
		if(cod == lt->v[i].cod){
			pos=i;
			break;
		}
	}
	
	if(lt->n-1 == pos){ // Para excluir o ultimo nodo.
		*nodo = lt->v[pos];
		lt->n--;	
		return SUCESSO;
		
	} else if(pos < lt->n){ // Quando o nodo excluido não é o ultimo.
		*nodo = lt->v[pos];
		for (i=pos; i < lt->n; i++){
			lt->v[i] = lt->v[i+1];
		}
		lt->n--;
		return SUCESSO;
		
	} else if(pos > lt->n){
		return CODIGO_INEXISTENTE; //indice invalido seria no caso POSIÇÕE MAIORES Q N ??????
		
	}
	
}
