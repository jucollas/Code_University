#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main(){
    int arreglo[]= {1, 5, 8, 9, 6, 17, 3, 4, 14, 12, 0};
    int n = sizeof(arreglo) / sizeof(int);
    vector<int> vec1(arreglo, arreglo + n);
 
    // se ordena el vector con sort
    sort(vec1.begin(), vec1.end());

    cout << "Vector vec1:" << endl;
    for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    if (binary_search(vec1.begin(), vec1.end(), 14)) 
       cout << "El numero 14 se encuentra en el vector." << endl;
    else
       cout << "El numero 14 no se encuentra en el vector." << endl;
 
    if (binary_search(vec1.begin(), vec1.begin() + 7, 14))
       cout << "El numero 14 se encuentra en las primeras 7 posiciones del vector." << endl;
    else
       cout << "El numero 14 no se encuentra en las primeras 7 posciones del vector." << endl;
 
    return 0;
}
