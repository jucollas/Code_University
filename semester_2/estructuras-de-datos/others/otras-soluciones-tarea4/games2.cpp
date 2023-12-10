/*
Juan Diego Collazos Mejia // ID: 8977837 // March 26st 2023
complejidad O(n*log(n)) siendo en la cantidad de nombres ingresados
*/
#include <stdio.h>
#include <cstring>

void merge(int *arr, int low, int half, int high, char names[1000][35]){
	int i, j, k;
	int len1 = half - low + 1;
	int len2 = high - half;
	int ax1[500], ax2[500];

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
		if(strcmp(names[ax1[i]], names[ax2[j]]) < 0){
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


void sortMerge(int* arr, int low, int high, char names[1000][35]){
	if(low < high){
		int half = (low + high)/2;
		sortMerge(arr, low, half, names);
		sortMerge(arr, half + 1, high, names);
		merge(arr, low, half, high, names);
	}

}

int main(){
	char names[1000][35];
	char ans[35];
	int ax[1000];
	int nGuests;
	int i;
	int pos1, pos2, len;
	int flag1 = 1, flag2, flag3;
	while(flag1){
		scanf("%d", &nGuests);
		if(nGuests == 0){
			flag1 = 0;
		}else{
			for(i = 0; i < nGuests; ++i){
				scanf("%s", &names[i]);
				ax[i] = i;
			}

			sortMerge(ax, 0, nGuests - 1, names);
			
			pos1 = (nGuests/2) - 1;
			pos2 = (nGuests/2);
			flag2 = 1;
			flag3 = 0;
			i = 0;

			if(strlen(names[ax[pos1]]) <= strlen(names[ax[pos2]])){
				len = strlen(names[ax[pos1]]);
			}else{
				len = strlen(names[ax[pos2]]);
			}

			while(i < len && flag2){
				if(names[ax[pos1]][i] == names[ax[pos2]][i]){
					ans[i] = names[ax[pos1]][i];
				}else{
					if((names[ax[pos1]][i] + 1  != names[ax[pos2]][i] && ( (strlen(names[ax[pos2]]) - i - 1 != 0 && strlen(names[ax[pos1]]) - i - 1 != 0) || strlen(names[ax[pos1]]) - i - 1 != 0 ))  || ((strlen(names[ax[pos2]]) - i - 1 != 0 && strlen(names[ax[pos1]]) - i - 1 != 0) && names[ax[pos1]][i] + 1  == names[ax[pos2]][i])){
						ans[i] = names[ax[pos1]][i] + 1;
					}else{
						ans[i] = names[ax[pos1]][i];
						flag3 = 1;
					}
					flag2 = 0;
				}
				++i;
			}

			if(flag3 && strlen(names[ax[pos1]]) > strlen(names[ax[pos2]])){
				if(strlen(names[ax[pos1]]) - i == 1){
					ans[i] = names[ax[pos1]][i];
					ans[i+1] = '\0';
				}else{

					if(names[ax[pos1]][i] == 'Z'){

						while(names[ax[pos1]][i] == 'Z'){
							ans[i] = names[ax[pos1]][i];
							++i;
						}

						if(strlen(names[ax[pos1]]) - i != 0){
							if(strlen(names[ax[pos1]]) - i == 1){
								ans[i] = names[ax[pos1]][i];
							}else{
								ans[i] = names[ax[pos1]][i] + 1;
							}
							ans[i+1] = '\0';
						}else{
							ans[i] = '\0';
						}

					}else{
                        ans[i] = names[ax[pos1]][i] + 1;
                        ans[i+1] = '\0';
					}	
				}
				
			}else{
				ans[i] = '\0';	
			}
			
			printf("%s\n", ans);
		}
	}
}