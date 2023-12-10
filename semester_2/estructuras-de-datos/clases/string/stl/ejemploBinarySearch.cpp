#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
    int arreglo[]= {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arreglo) / sizeof(int);
 
    // se ordena el arreglo con sort
    sort(arreglo, arreglo + 10);

    cout << "Arreglo ordenado:" << endl;
    for(int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;

    if (binary_search(arreglo, arreglo + 10, 2)) 
       cout << "El numero 2 se encuentra en el arreglo." << endl;
    else
       cout << "El numero 2 no se encuentra en el arreglo." << endl;
 
    if (binary_search(arreglo, arreglo + 10, 11))
       cout << "El numero 11 se encuentra en el arreglo." << endl;
    else
       cout << "El numero 11 no se encuentra en el arreglo." << endl;
 
    return 0;
}
