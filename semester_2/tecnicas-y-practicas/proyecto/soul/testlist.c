#include <stdio.h>
#include "arraylist.h"

int main(){
    List ax = createList( );
    ax.add( &ax, 0, 1);
    ax.add( &ax, 1, 2);
    ax.add( &ax, 2, 3);
    ax.display(&ax);
    ax.add( &ax, 0, 7);
    ax.display(&ax);
    ax.delete(&ax, 2);
    ax.display(&ax);
    printf("2: %d", ax.get(&ax, 4));
    return 0;
}