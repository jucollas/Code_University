#include <stdio.h>
#define COL 3
#define ROW 3

int main(){
	int mat[ROW][COL] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			printf("%d", mat[i][j]);
		}

	}
	return 0;
}