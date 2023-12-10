#include "linkedlist.h"
#include <stdio.h>

int main(){
    List l;
    //l.append(1);
    /*for(int i = 0; i < 10; ++i){
        l.push_back(i);
    }
    l.printList();*/
    l.push_sort(5);
    l.push_sort(8);
    l.push_sort(3);
    l.push_sort(2);
    l.push_sort(1);
    l.push_sort(10);
    l.push_sort(4);
    for(int i = 1; i <= l.len(); ++i){
        printf("%d ", l[i]);
    }
    printf("\n");
    printf("%d\n", l.len());

    l.printList();


    return 0;
}