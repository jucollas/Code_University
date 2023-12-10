#include <stdio.h>
#define size 3

void sumaNumeros(int* num1, int n1, int* num2, int n, int* ans){
	int i;
	//int ans[5];
	int cont = 0;
	for (i = 0; i < n1 ; ++i){
		
		if (num1[i] - cont >= num2[i]){
			ans[i] = num1[i] - num2[i] - cont;
			cont = 0;
		}else{
			ans[i] = 10 + (num1[i] - num2[i] - cont);
			cont = 0;
			++cont;
		}
	}
}


int main(){
	int num1[size] = {6, 3, 2};
	int num2[size] = {7, 3, 1};
	
	int n = size; 
	int i;
	int ans[size]; 
	sumaNumeros(num1, n , num2, n, ans);
	//printf("%d", ans[1]);
	for(i = 0 ; i < size ; ++i){
		printf("%d ", ans[2 - i]);
	}
	printf("\n");

	return 0;
}

