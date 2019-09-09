#include <stdio.h>
#include <stdlib.h>

int maiorNumero(int nn1, int nn2){
	if(nn1>nn2){
		return nn1;
		
	} else if( nn2 > nn1){
			return nn2;
		
		
	}else {
		return -1;	
		
	}
	
	
	
}


int main(){
	int qt, n1,n2,resp,i;
	printf("Informa a Qt: ");
	scanf("%d",&qt);
	for(i=0;i<qt;i++){
		printf("Informa N1 e N2: ");
		scanf("%d %d",&n1,&n2);
		resp=maiorNumero(n1,n2);
		if(resp==-1){
			printf("São Iguais !!\n");
		
		}else{
			printf("%d\n",resp);
			
		}
	}
	
	return 0;
}

