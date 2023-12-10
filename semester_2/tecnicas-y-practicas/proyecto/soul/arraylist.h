#ifndef ARRAYLIST
#define ARRAYLIST

#include <stdio.h>
#include <stdlib.h>
#define CAP 100

typedef struct List List;

List createList();
void add (List * x, int index, int e);
void display(List * x);
void delete(List * x, int index);
int get(List * x,int index);

struct List{
    int a[ CAP ], n;
    void (*add) (List *, int, int);
    void (*display) (List *);
    void (*delete) (List *, int);
    int (*get) (List *, int);
};

List createList(){
    List l;
    l.n = 0;
    l.add = &add;
    l.display = &display;
    l.delete = &delete;
    l.get = &get;
    return l;
}

void add (List * x, int index, int e){
    int i;

    if(index < 0 || index > x -> n){
        fprintf(stderr, "Error : inavlid Index\n");
        return;
    }
    if(x->n == CAP){
        fprintf( stderr, "Error : list is full\n");
        return;
    }
    for(i = x->n-1; i >= index; i--)
        x->a[ i + 1 ] = x->a[i];
    x->a[index] = e;
    x->n++;
    return;
}

void display(List * x){
    int i;
    printf("[");
    for(i = 0 ; i < x -> n - 1 ; i++)
        printf("%d, ", x->a[i]);
    printf("%d]\n", x->a[x->n - 1]);
    return;    
}

void delete(List * x, int index){
    int i;
    if(index < 0 || index > x -> n){
        fprintf(stderr, "Error : inavlid Index\n");
        return;
    }
    for(i = index + 1; i < x->n; i++)
        x->a[i-1] = x->a[i];
    x->n--;
}

int get(List * x, int index){
    if(index < 0 || index >= x -> n){
        fprintf(stderr, "Error : inavlid Index\n");
        return -1;
    }
    return x->a[index];
}

#endif
