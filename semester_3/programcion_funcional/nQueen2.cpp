#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;

int absf(int n){
    if(n < 0)
        n *= -1;
    return n;
}

int main(){
    queue<vector<int>> nodes;
    bool flag1, flag2;
    int n, i, j, k, cont;
    while(cin >> n && n != 0){
        vector<int> table(n, 1);
        flag1 = true;
        cont = 0;
        while(table[0] <= n && flag1){
            //cout << "cont: " << cont << endl;
            j = 0;
            flag2 = true;
            while(j < cont && flag2){
                if(table[j] == table[cont] || absf(table[j] - table[cont]) == absf((j+1) - (cont + 1)))
                    flag2 = false;
                ++j;
            }
            if(flag2){
                //cout << "es posible poner " << cont + 1 << ", " << table[cont] << endl;
                ++cont;
                if(cont > n - 1)
                    flag1 = false;
            }else{
                //cout << "no es posible poner " << cont + 1 << ", " << table[cont] << endl;
                if(table[cont] + 1 > n){
                    //table[cont] = 1;
                    --cont;
                    ++table[cont];
                }else
                    ++table[cont];
            }
        }
        
        if(!flag1){
            cout << "It's possible" << endl;
            for(i = 0; i < table.size(); ++i)
                cout << "(" << i + 1 << ", " << table[i] << ") ";
            cout << endl;
        }else{
            cout << "It is not possible" << endl;
        }
        while(!nodes.empty()){
            nodes.pop();
        }
        
    }
    return 0;
}