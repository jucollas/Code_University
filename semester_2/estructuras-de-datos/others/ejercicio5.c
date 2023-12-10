void algoritmo5(int n){
    int i = 0;                // 1
    while(i <= n){            // n + 2
        printf("%d\n", i);    // n + 1
        i += n / 5;           // n + 1
    }
}