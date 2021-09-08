#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

#include "node.h"


class Queue
{
    int f,r,s;
    int **q;

public :
    QueueArr();
    QueueArr(int s);
    void enQueue(node *x);
    node* deQueue();
    void display();
    int isEmpty();
};

#endif // QUEUE_H
