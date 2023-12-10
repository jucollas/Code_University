void algoritmo3(int n){
    int i, j, k;                           // 3
    for(i = n; i > 1; i--)                 // n
        for(j = 1; j <= n; j++)            // n(n - 1) + 1
            for(k = 1; k <= i; k++)        // n(n - 1 + (((n-1)*n)/2)) + 1
                printf("Vida cruel!!\n");  // n(n - 1 + (((n-1)*n)/2))
}