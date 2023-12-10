#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparar(int i,int j){
    return i > j;
}

class ordenador{
    public:
 	bool operator() (int i,int j){
	    return i > j;
	}
} obj;
 
int main(){
    int arreglo[]= {100, 75, 68, 59, 56, 47, 43, 34, 24, 22, 18, 11, 8};
    int n = sizeof(arreglo) / sizeof(int);
    vector<int> vec1(arreglo, arreglo + n);

    cout << "Vector vec1:" << endl;
    for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    //if (binary_search(vec1.begin(), vec1.end(), 14, comparar))
    if(binary_search(vec1.begin(), vec1.end(), 14, obj))  
       cout << "El numero 14 se encuentra en el vector." << endl;
    else
       cout << "El numero 14 no se encuentra en el vector." << endl;
 
    //if (binary_search(vec1.begin(), vec1.end(), 59, comparar))
    if(binary_search(vec1.begin(), vec1.end(), 59, obj))
       cout << "El numero 59 se encuentra en el vector." << endl;
    else
       cout << "El numero59 no se encuentra en el vector." << endl;
 
    return 0;
}
