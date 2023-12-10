#include <stdio.h>

int main(){
	int col = 3;
	int fila = 3;
	int i, j;
	int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	for( i = 0; i < fila; ++i){
		for(j = 0; j < col; ++j){
			printf("%d ", matriz[fila - i - 1][col - 1 - j]);
		}
		printf("\n");
	}
	return 0;
}