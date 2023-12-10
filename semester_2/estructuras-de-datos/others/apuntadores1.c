#include <stdio.h>

int main(){
	int a;
	int b;
	int* p;
	int* q;
	a = 3;
	p = &a;
	q = p;
	*q = *q + 5;
	printf("%d", *p);
}