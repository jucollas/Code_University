/* 
Author: Juan Diego Collazos 
date: 2sd april 2023
*/

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>

using namespace std;

class Node{
    public:
        int date;
        Node* next;
};

class List{
    private:
        int size; 
        Node* firts;
    public:
        List();
        void insert(int num, int index);
        void push_back(int num);
        void push_sort(int num);
        void append(int num);
        int operator[](int index);
        int len();
        void printList();
};

#endif