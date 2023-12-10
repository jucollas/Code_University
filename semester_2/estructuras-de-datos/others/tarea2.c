#include <stdio.h>
//########################################################################################################
// 1)
void algoritmo1(int n){ // O(log2(n))
	int i, j = 1;                      // 2
	for(i = n * n; i > 0; i = i / 2){  // log2(n^2) + 1
		int suma = i + j;			   // log2(n^2)
		printf("%d\n",i);     // log2(n^2)
		++j;                           // log2(n^2)
	}
}
// 8*log2(n) + 3

//###############################################################################################
// 2)
int algoritmo2(int n){ //O(n)
	int res = 1, i, j, contador = 1;                // 3                
	for(i = 1; i <= 2 * n; i += 4) {  // (n/2) + 1
		                     
		for(j = 1; j * j <= n; j++) { // ((n/2) * raiz2(n)) + 1
			printf("%d\n", contador);
			contador++;
			res += 2;                 // (n/2) * raiz2(n)
		}
	}
	return res;                       // 1
}
// n*raiz2(n) + n/2 + 6

//########################################################################################################
// 3)
void algoritmo3(int n){ // O(n^3)
	int i, j, k, r = 1;                    // 3
	for(i = n; i > 1; i--)                 // n
		for(j = 1; j <= n; j++)            // (n)(n - 1) + 1
			for(k = 1; k <= i; k++) 	   // n(n - 1 + (((n-1)*n)/2)) + 1
				printf("Vida cruel!!\n");  // n(n - 1 + (((n-1)*n)/2))
}
// 2n(n - 1 + (((n-1)*n)/2))+ n(n - 1)+ n + 5
// 2n^2 - 2n + n^3 - n^2 + n^2 - n + n + 5
// n^3 + 2n^2 - 2n + 5

//###############################################################################################################
// 4)
int algoritmo4(int* valores,int n){ //O(n^3)
	int suma = 0, contador = 0;              // 2
	int i, j, h, flag;                       // 4

	for(i = 0; i < n; i++){                  // n + 1
		j = i + 1;							 // n 
		flag = 0;                            // n
		
		while(j < n && flag == 0){           // ((n(n-1))/2) + 1
			
			if(valores[i] < valores[j]){     // ((n(n-1))/2)
				for(h = j; h < n; h++){      // (1/6)(n)(n^2 - 1) + 1
					suma += valores[i];      // (1/6)(n)(n^2 - 1)
				}
			}

			else{
				contador++;                   
				flag = 1;
			}
	
			++j;                             // ((n(n-1))/2)
		}
	}
	return contador;
}

void algoritmo5(int n){ // O(1)
	int i = 0;                // 1
	while(i <= n){            // 7  
		printf("%d\n", i);    // 6
		i += n / 5;			  // 6	
	}
}
// 20

int main(){
	algoritmo2(100);
	return 0;
}