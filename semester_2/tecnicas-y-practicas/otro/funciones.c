#include <stdio.h>

int potencia(int a);

int main(){
	printf("%d", potencia(2));
	return 0;
}

int potencia(int a){
	return a * a;
}