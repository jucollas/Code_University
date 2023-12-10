int algoritmo4(int* valores, int n){
    int suma = 0, contador = 0;            // 2
    int i, j, h, flag;                     // 4
    for(i = 0; i < n; i++){                // n + 1
        j = i + 1;                         // n
        flag = 0;                          // n 
        while(j < n && flag == 0){         // ((n(n-1))/2) + 1   
            if(valores[i] < valores[j]){   // ((n(n-1))/2)
                for(h = j; h < n; h++){    // (1/6)(n)(n^2 - 1) + 1
                    suma += valores[i];    // (1/6)(n)(n^2 - 1)
                }
            }
            else{
                contador++;             
                flag = 1;
            }
            ++j;                           // ((n(n-1))/2)
        }
    }
    return contador;                       // 1
}