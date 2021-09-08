#include "QueueLinked.h"

QueueLinked::QueueLinked()
{
    f = nullptr;
    r = nullptr;
}


void QueueLinked ::enQueue(int x)
{

    QueueLinked *t;
    t = new QueueLinked;

    if(t == nullptr)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        t->data = x;
        t->next = nullptr;

        if(f == nullptr)
        {
            f = r = t;
        }
        else
        {
          r->next = t;
          r=t;

        }

    }

}
int QueueLinked ::deQueue(){
    int x=-1;
    QueueLinked *t;
    if(f==nullptr){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        x = f->data;
        t=f;
        f=f->next;
        delete t;
    }
return x;
}

void QueueLinked :: display(){
    QueueLinked *p = f;

    while(p){
        cout<<p->data<<",";
        p=p->next;
    }
    cout<<endl;
}
