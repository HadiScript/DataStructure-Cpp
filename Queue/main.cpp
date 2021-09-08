#include<iostream>
#include "QueueLinked.h"

using namespace std;





int main()
{
    QueueLinked v;

    v.enQueue(10);
    v.enQueue(20);
    v.enQueue(30);

    cout<<"this is the deQueue Elements"<<v.deQueue()<<endl;

//cout<<v.deQueue();

    v.display();
}
