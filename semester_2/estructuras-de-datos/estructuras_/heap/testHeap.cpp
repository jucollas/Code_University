
#include "heap.h"

int main(){
    int arr[] = {0, 14, 74, 52, 84, 96, 41, 41};
    Heap f;
    f.put(14);
    f.put(74);
    f.put(52);
    f.put(84);
    f.put(96);
    f.put(41);
    f.put(41);
    f.display();
    int len = f.size(); 
    for(int i = 0; i < len; ++i){
        printf("%d ", f.top());
        f.remove();   
        //f.display(); 
    }
    printf("\n");

    return 0;
}