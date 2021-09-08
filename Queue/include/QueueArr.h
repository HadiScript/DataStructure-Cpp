#ifndef QUEUEARR_H
#define QUEUEARR_H

#include<iostream>
using namespace std;

class QueueArr
{
    int f,r,s;
    int *q;

public :
    QueueArr();
    QueueArr(int s);
    void enQueue(int x);
    int deQueue();
    void display();
};


#endif // QUEUEARR_H
