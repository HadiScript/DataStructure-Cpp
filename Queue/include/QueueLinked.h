#ifndef QUEUELINKED_H
#define QUEUELINKED_H

#include<iostream>
using namespace std;


class QueueLinked
{
    private:
        int data;
        QueueLinked *next;
    public:
        QueueLinked *f,*r;
        QueueLinked();
        void enQueue(int x);

        int deQueue();
        void display();




};

#endif // QUEUELINKED_H
