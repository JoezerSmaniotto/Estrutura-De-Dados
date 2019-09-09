#include<stdio.h>

int main (){
	int *p, A=10;
	p=&A;
	*p=A+3;
	(*p)++;
	printf("A: %d\n",A);
	printf("&A: %d\n",&A);
	printf("&p: %d\n",&p);
	printf("P: %d\n",p);
	printf("*p: %u\n",*p);
	printf("Incrementado P: %d\n",p);
	printf("*p: %d\n",*p);
	printf("A: %d\n",A);
	printf("&A: %d\n",&A);

	return 0;
}

