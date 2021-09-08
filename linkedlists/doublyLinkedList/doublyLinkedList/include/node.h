#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class node
{
    node *prev;
    int data;
    node *next;

    public:
        node *first;
        node();
        void create(int a[], int n);
        void display();
        int length();




};

#endif // NODE_H
