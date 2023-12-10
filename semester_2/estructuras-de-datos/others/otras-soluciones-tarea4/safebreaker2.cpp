#include <stdio.h>

int main(){
	int nCases, nGuesses;
	int axl[4][10];
	int guesses[10][4];
	int guessesCont[10][10], cont[10];
	int posAndDig[10];
	int onlyDig[10];
	int ans[4];
	int max[4], min[4];
	int i, j, k, p, q;
	int flag1, flag2, flag3;
	int ax1;

	scanf("%d", &nCases);
	for(i = 0; i < nCases; ++i){
		scanf("%d", &nGuesses);
		for(j = 0; j < 4; ++j){
			for(k = 0; k < 10; ++k){
				axl[j][k] = 1;
			}
		}

		for(j = 0; j < nGuesses; ++j){
			scanf("%d %d/%d", &ax1, &posAndDig[j], &onlyDig[j]);

			for(k = 0; k < 10; ++k){
				guessesCont[j][k] = 0;
			}
			//printf("%d\n", onlyDig[j]);
			for(k = 3; k >= 0; --k){
				guesses[j][k] = ax1 % 10;
				guessesCont[j][guesses[j][k]] += 1;
				ax1 /= 10;
			}

			if(posAndDig[j] == 0 && onlyDig[j] == 0){

				for(k = 0; k < 4; ++k){
					for(p = 0; p < 4; ++p){
						axl[p][guesses[j][k]] = 0;
					}
				}

			}else if(posAndDig[j] == 0){

				for(k = 0; k < 4; ++k){
					axl[k][guesses[j][k]] = 0;
				}

			}

			/*for(k = 0; k < 4; ++k){
				for(p = 0; p < 10; ++p){
					printf("%d ", axl[k][p]);
				}
				printf("\n");
			}*/
		}
		/*for(j = 0; j < nGuesses; ++j){
			for(k = 0; k < 10; ++k){
				printf("%d", guessesCont[j][k]);
			}
			printf("\n");
		}*/

		

		for(j = 0; j < 4; ++j){
			min[j] = -1;
			for(k = 0; k < 10; ++k){
				if(min[j] == -1 && axl[j][k]){
					min[j] = k;
					ans[j] = k;
				}
				if(axl[j][k]){
					max[j] = k;
				}
			}
		}


		/*for(j =0; j <4;++j ){
			printf("%d", max[j]);
		}
		printf("\n");
		for(j =0; j <4;++j ){
			printf("%d", min[j]);
		}
		printf("\n");*/

		flag1 = 1;
		
		while(flag1){
			flag2 = 1;
			flag3 = 1;
			j = 0;
			for(k = 0; k < 10; ++k){
				cont[k] = 0;
			}
			for(k = 0; k < 4; ++k){
				cont[ans[k]] += 1;
			}

			while(j < nGuesses && flag3){

				if(posAndDig[j] != 0){
					p = 0;
					for(k = 0; k < 3; ++k){
						if(guesses[j][k] == ans[k]){
							++p;
						}
					}
					if(p != posAndDig[j]){
						flag3 = 0;
					}
				}

				if(onlyDig[j] != 0 && flag3){
					p = 0;

					for(k = 0; k < 10; ++k){
						if(cont[k] == guessesCont[j][k]){
							p += cont[k];
						}
					}

					if(p != onlyDig[j]){
						flag3 = 0;

					}
				}
				j++;
			}

			if(flag3){
				for(j =0; j <4;++j ){
				printf("%d", ans[j]);
				}
				printf("\n");
			}
			

			j = 3;
			while(flag2){
				if(ans[j] == max[j]){
					ans[j] = min[j];

				}else{
					k = ans[j];
					while(flag2){
						++k;
						if(axl[j][k]){
							ans[j] = k;
							flag2 = 0;
						}
					}
				}
				--j;
			}
			

			if(ans[0] == max[0] && ans[1] == max[1] && ans[2] == max[2] && ans[3] == max[3]){
				flag1 = 0;
			}
		}
	}
}