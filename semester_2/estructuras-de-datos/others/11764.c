#include <stdio.h>

int main(){
	int cases, walls, i, j, ax, ax2, altos, bajos;
	scanf("%d", &cases);
	for (i = 0; i < cases; ++i)
	{	altos = 0, bajos = 0;
		scanf("%d", &walls);
		for (j = 0; j < walls; ++j){
			if (j == 0){
				scanf("%d", &ax);
			}else{
				scanf("%d", &ax2);
				if (ax < ax2)
				{
					altos++;
				}else if (ax > ax2){
					bajos++;
				}
				ax = ax2;
			}
		}
		printf("Case %d: %d %d\n", i + 1, altos, bajos);
	}
	return 0;
}