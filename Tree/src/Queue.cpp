#include "Queue.h"

#include<iostream>
using namespace std;


Queue::Queue ()
{
    f=r= 0;
    s=10;
    q = new node[s];
};

Queue::Queue (int s)
{
    f=r= 0;
    this->s=s;
    q = new node[this->s];
};


void Queue::enQueue(node * x)
{
    if((r+1)%s == s-1)
    {
        cout<<"Queue is full:"<<endl;
    }
    else
    {
        r = (r+1) % s ;
        q[r] = x;
    }
}

node* node::deQueue()
{
    node x= null;
    if(r==f)
    {
        cout<<"Queue is Empty:"<<endl;
    }
    else
    {
        f = (f+1)%s;
        x=q[f+1];
    }
    return x;
}

void Queue::display()
{
    int i = f+1;
    do
    {
        cout<<q[i];
        i=(i+1)%s;
    }
    while(i!=(r+1)%s);
    cout<<endl;
}


int Queue :: isEmpty(){
    return f == r;
}
