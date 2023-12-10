#include <stdio.h>

void programa1(){
	int n;
	int m = 18;
	while(n != -1){
		scanf("%i", &n);
		if (n > m){
			printf("es mayor de edad");
		}else if(n < m){
			printf("es menor de edad");
		}else{
			printf("acabo de cumplir 18");
		}
		printf("\n");
	}
	printf("bye.");
}

int main(){
	programa1();
	return 0;
}

