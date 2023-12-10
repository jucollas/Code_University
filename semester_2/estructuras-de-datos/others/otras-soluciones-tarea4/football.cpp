/*
Juan Diego Collazos Mejia // ID: 8977837 // March 22st 2023
complejidad O(n*log(n)) siendo n la cantidad de equipos ingresados. 
*/
#include <stdio.h>
#include <cstring>
#include <ctype.h>

int contrast(char name1[16], char name2[16]){
	int ans = 0, i = 0, l;
	int ax1, ax2;
	int flag = 0;
	if(strlen(name1) <= strlen(name2)){
		l = strlen(name1); 
	}else{
		l = strlen(name2);
	}

	while(i < l && !flag){
		if(name1[i] != name2[i]){
			flag = 1;
			if(tolower(name1[i]) < tolower(name2[i])){
				ans = 1;
			}
		}
		++i;
	}

	if(!flag && strlen(name1) < strlen(name2)){
		ans = 1;
	}
	return ans;
}

int condition(int team1, int team2, int* nPoints, int* nScoreG, int* nSufferedG, char nameteams[99][16]){
	int ans = 0;
	if(nPoints[team1] == nPoints[team2]){
		if((nScoreG[team1] - nSufferedG[team1]) == (nScoreG[team2] - nSufferedG[team2])){
			if(nScoreG[team1] == nScoreG[team2]){
				if(contrast(nameteams[team1], nameteams[team2])){
					ans = 1;
				}
			}else if(nScoreG[team1] > nScoreG[team2]){
				ans = 1;
			}

		}else if((nScoreG[team1] - nSufferedG[team1]) > (nScoreG[team2] - nSufferedG[team2])){
			ans = 1;
		}
		
	}else if(nPoints[team1] > nPoints[team2]){
		ans = 1;
	}
	return ans;
}

void merge(int *arr, int low, int half, int high, int* nPoints, int* nScoreG, int* nSufferedG, char nameteams[99][16]){
	int i, j, k;
	int len1 = half - low + 1;
	int len2 = high - half;
	int ax1[50], ax2[50];

	for(i = 0; i < len1; i++){
		ax1[i] = arr[low + i];
	}
	for(i = 0; i < len2; i++){
		ax2[i] = arr[half + 1 + i];
	}
	i = 0;
	j = 0;
	k = low;
	while(i < len1 && j < len2){
		if(condition(ax1[i], ax2[j], nPoints, nScoreG, nSufferedG, nameteams)){
			arr[k] = ax1[i];
			++i;
		}else{
			arr[k] = ax2[j];
			++j;
		}
		++k;
	}

	for(;i < len1; ++i){
		arr[k] = ax1[i];
		++k;
	}
	for(;j < len2; ++j){
		arr[k] = ax2[j];
		++k;
	}
}


void sortMerge(int* arr, int low, int high,  int* nPoints, int* nScoreG, int* nSufferedG, char nameteams[99][16]){
	if(low < high){
		int half = (low + high)/2;
		sortMerge(arr, low, half, nPoints, nScoreG, nSufferedG, nameteams);
		sortMerge(arr, half + 1, high, nPoints, nScoreG, nSufferedG, nameteams);
		merge(arr, low, half, high, nPoints, nScoreG, nSufferedG, nameteams);
	}

}

int position(char* team, char nameteams[99][16]){
	int i = 0, flag = 1, ans;
	while(flag){
		if(strcmp(team, nameteams[i]) == 0){
			flag = 0;
		}
		++i;
	}
	ans = i - 1;
	return ans;
}

void printNumber(int num){
	if(num > 99){
		printf(" ");
	}else if(num > 9){
		printf("  ");
	}else if(num >= 0){
		printf("   ");
	}else if(num >= -9){
		printf("  ");
	}else{
		printf(" ");
	}
	printf("%d", num);
}

int main(){
	char nameteams[99][16];
	char team1[16], team2[16];
	int nPoints[99], nPlayed[99], nScoreG[99], nSufferedG[99], ans[99];
	int nteams, ngames;
	int goals1, goals2, ax1, ax2;
	float prom;
	int flag = 1, flag2, flag3 = 0;
	int i, j;
	while(flag){
		
		scanf("%d %d", &nteams, &ngames);
		if(nteams == 0 && ngames == 0){
			flag = 0;
		}else{
			if(flag3){
				printf("\n");
			}
			flag3 = 1;

			for(i = 0; i < nteams; ++i){
				scanf("%s", &nameteams[i]);
				nPlayed[i] = 0;
				nPoints[i] = 0;
				nScoreG[i] = 0;
				nSufferedG[i] = 0;
				ans[i] = i;
			}
			for(i = 0; i < ngames; ++i){
				scanf("%s %d - %d %s", &team1, &goals1, &goals2, &team2);
				ax1 = position(team1, nameteams);
				ax2 = position(team2, nameteams);
				nPlayed[ax1] += 1;
				nPlayed[ax2] += 1;
				nScoreG[ax1] += goals1;
				nScoreG[ax2] += goals2;
				nSufferedG[ax1] += goals2;
				nSufferedG[ax2] += goals1;
				if(goals1 > goals2){
					nPoints[ax1] += 3;
					nPoints[ax2] += 0;
				}else if(goals1 < goals2){
					nPoints[ax2] += 3;
					nPoints[ax1] += 0;
				}else{
					nPoints[ax1] += 1;
					nPoints[ax2] += 1;
				}
			}

			sortMerge(ans, 0, nteams - 1, nPoints, nScoreG, nSufferedG, nameteams);

			for(i = 0; i < nteams; ++i){

				flag2 = 0;

				if(i != 0){
					if(nPoints[ans[i]] == nPoints[ans[i - 1]] && (nScoreG[ans[i]] - nSufferedG[ans[i]]) == (nScoreG[ans[i - 1]] - nSufferedG[ans[i - 1]]) && nScoreG[ans[i]] == nScoreG[ans[i - 1]]){
						flag2 = 1;
					}
				}

				if(flag2){
					printf("   ");
				}else{
					if(i < 9){
						printf(" ");
					}
					printf("%d.", i+1);
				}

				for(j = 0; j < 16 - strlen(nameteams[ans[i]]); ++j){
					printf(" ");
				}
				printf("%s", nameteams[ans[i]]);
				printNumber(nPoints[ans[i]]);
				printNumber(nPlayed[ans[i]]);
				printNumber(nScoreG[ans[i]]);
				printNumber(nSufferedG[ans[i]]);
				printNumber(nScoreG[ans[i]] - nSufferedG[ans[i]]);

				if(nPlayed[ans[i]] != 0){
					prom = (float(nPoints[ans[i]]) / (nPlayed[ans[i]]*3))*100;
					if(prom < 10){
						printf(" ");
					}if(prom < 100){
						printf("  ");

					}else{
						printf(" ");
					}
					printf("%.2f", prom);

				}else{
					printf("    N/A");
				}
				printf("\n");
			}	
		}
	}
}