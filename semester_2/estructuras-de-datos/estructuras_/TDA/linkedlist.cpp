
#include "linkedlist.h"

List::List(){
    size = 0;
    firts = NULL;
}

Node* create_Node(int num){
    Node* unused = new Node;
    unused->date = num;
    unused->next = NULL;
    return unused;
}

int List::len(){
    return size;
}

void List::append(int num){
    Node* unused = create_Node(num);
    if(firts != NULL){
        unused->next = firts;
    }
    firts = unused;
    ++size;
}

void List::push_sort(int num){
    Node* unused = create_Node(num);
    Node* ax = firts;
    if(firts != NULL){
        if(ax->date >= num){
            unused->next = firts;
            firts = unused;
        }else{
            while(ax->next != NULL && ax->next->date < num){
                ax = ax->next;
            }
            unused->next = ax->next;
            ax->next = unused;
        }
    }else{
        firts = unused;
    }
    ++size;
}

void List::push_back(int num){
    Node* unused = create_Node(num);
    Node* ax = firts;
    if(firts != NULL){
        int i;
        for(i = 0; i < size - 1; ++i){
            ax = ax->next;
        }
        unused->next = ax->next;
        ax->next = unused;
    }else{
        firts = unused;
    }
    ++size;
}

void List::insert(int num, int index){
    if(index <= size){
        if(index == 1){
            append(num);
        }else{
            Node* unused = create_Node(num);
            Node* ax = firts;
            int i;
            for(i = 0; i < index - 2; ++i){
                ax = ax->next;
            }
            unused->next = ax->next;
            ax->next = unused;
        }
        ++size;
    }
}

int List::operator[](int index){
    Node* ax = firts;
    for(int i = 0; i < index - 1; ++i){
        ax = ax->next;
    }
    return ax->date;
}

void List::printList(){
    if(firts != NULL){
        Node* ax = firts;
        printf("[");
        while(ax->next != NULL){
        printf("%d, ", ax->date);
        ax = ax->next;
        }
        printf("%d]\n", ax->date);
    }
}