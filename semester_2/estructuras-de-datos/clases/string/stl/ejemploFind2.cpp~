#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main(){
    int arreglo[]= {1, 5, 8, 9, 6, 17, 3, 4, 14, 12, 0};
    int n = sizeof(arreglo) / sizeof(int);
    vector<int> vec1(arreglo, arreglo + n);

    cout << "Vector vec1:" << endl;
    for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    vector<int>::iterator pos = find(vec1.begin(), vec1.end(), 14);

    if (pos != vec1.end()) 
       cout << "El numero 14 se encuentra en el vector en la posicion " << pos - vec1.begin() << "." << endl;
    else
       cout << "El numero 14 no se encuentra en el vector." << endl;
 
    pos = find(vec1.begin(), vec1.begin() + 7, 14);

    if (pos != vec1.begin() + 7)
       cout << "El numero 14 se encuentra en las primeras 7 posiciones del vector." << endl;
    else
       cout << "El numero 14 no se encuentra en las primeras 7 posciones del vector." << endl;
 
    return 0;
}
