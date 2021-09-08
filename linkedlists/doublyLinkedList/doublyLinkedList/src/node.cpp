#include "node.h"
#include <iostream>
using namespace std;

node::node(){first = nullptr;}
void node::create(int a[], int n){
    node *t, *last;

    first = new node;
    first->data = a[0];
    first->prev = first->next = nullptr;

    last = first;

    for(int i=1; i<n; n++){
        t = new node;
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void node::display(){
    node *p = first;
    while(p){
        cout<<p->data<<",";
        p=p->next;
    }
}
