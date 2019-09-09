#include <stdio.h>

int main(){
	int *p,*p1, x=10;
	p=&x;
	p1=&p;
	printf("x: %d\n",x);
	printf("&x: %d\n",&x);
	printf("p: %d\n",p);
	printf("*p: %d\n",*p);	
	printf("&p: %d\n",&p);
	printf("p1: %d\n",p1);
	printf("*p1: %d\n",*p1);	
	printf("&p1: %d\n",&p1);
	
	return 0;
}

