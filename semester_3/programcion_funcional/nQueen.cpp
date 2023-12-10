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
    vector<int> axu;
    bool flag1, flag2;
    int n, i, j;
    while(cin >> n && n != 0){
        flag1 = true;
        for(i = 1; i <= n; ++i){
            nodes.push({ i });
        }
        while(!nodes.empty() && flag1){
            axu = nodes.front();
            nodes.pop();
            if(axu.size() == n)
                flag1 = false;
            i = 1;
            while(i <= n && flag1){
                flag2 = true;
                j = 0;
                while(j < axu.size() && flag2){
                    if(axu[j] == i || absf(axu[j] - i) == absf((j+1) - (axu.size() + 1)))
                        flag2 = false;
                    ++j;
                }
                if(flag2){
                    axu.push_back(i);
                    nodes.push(axu);
                    if(axu.size() == n)
                        flag1 = false;
                    else
                        axu.pop_back();
                }
                ++i;
            }
        }
        if(!flag1){
            cout << "It's possible" << endl;
            for(i = 0; i < axu.size(); ++i)
                cout << "(" << i + 1 << ", " << axu[i] << ") ";
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