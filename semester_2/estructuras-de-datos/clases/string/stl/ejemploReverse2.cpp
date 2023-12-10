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

    reverse(vec1.begin(), vec1.begin() + 7);

    cout << "Vector vec1:" << endl;
    for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
 
    reverse(vec1.begin(), vec1.end());

    cout << "Vector vec1:" << endl;
    for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    return 0;
}
