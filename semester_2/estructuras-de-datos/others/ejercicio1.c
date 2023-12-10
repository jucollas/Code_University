#include <stdio.h>

void algoritmo1(int n){
    int i, j = 1;                         // 2
    for(i = n * n; i > 0; i = i / 2){     // (Log2(n^2)) + 1
        int suma = i + j;                 // (Log2(n^2))
        printf("Suma %d\n", suma);        // (Log2(n^2))
        ++j;                              // (Log2(n^2)) 
    }
}

int main(){
    algoritmo1(8);
    return 0;
}

