
#include <stdio.h>
#define cap 100

class Heap{
    private:
        int* a;
        int n;
    public:
        Heap();
        Heap(int* b, int size);

        int top();
        int size();

        void display();
        void put(int e);
        void remove();
};

Heap::Heap(){
    a = new int[cap];
    n = 0;
}

Heap::Heap(int* b, int size){
    int root, rootElement, child, flag;
    delete(a);
    a = b;
    n = size;
    for( root = n/2 ; root >= 1 ; root--){
        rootElement = a[root];
        child = 2 * root;
        flag = 1;
        while(child <= n && flag){
            if(child < n && a[child] < a[child + 1])
                child++;
            if(rootElement >= a[child]){
                flag = 0;
            }else{
                a[child/2] = a[child];
                child *= 2;
            }
        }
        a[child/2] = rootElement;
    }
}

int Heap::top(){
    return a[1];
}

int Heap::size(){
    return n;
}

void Heap::put(int e){
    int p = ++n;
    while(p > 1 && a[p/2] < e){
        a[p] = a[p/2];
        p /= 2;
    }
    a[p] = e;
}

void Heap::remove(){
    int e = a[n--];
    int p = 1, child = 2, flag = 1;
    while(child <= n && flag){
        if(child < n && a[child] < a[child + 1])
            child++;
        if(e >= a[child]){
            flag = 0;
        }else{
            a[p] = a[child];
            p = child;
            child *= 2;
        }
    }
    a[p] = e;
}

void Heap::display(){
    for(int i = 1; i <=
     n; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
}