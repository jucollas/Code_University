#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
    int arreglo[]= {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arreglo) / sizeof(int);

    cout << "Arreglo:" << endl;
    for(int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;

    reverse(arreglo, arreglo + n); 

    cout << "Arreglo:" << endl;
    for(int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;
 
    return 0;
}
