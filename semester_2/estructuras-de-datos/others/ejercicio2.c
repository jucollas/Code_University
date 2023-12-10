#include <stdio.h>

int algoritmo2(int n){
    int res = 1, i, j;                 // 3
    for(i = 1; i <= 2 * n; i += 4)     // (n/2) + 1 
        for(j = 1; j * j <= n; j++)    // ((n/2) * raiz2(n)) + 1
            res += 2;                  // (n/2) * raiz2(n)          
    return res;                        // 1
}

int main(){
    int i = algoritmo2(10);
    printf("%d", i);
    return 0;
}