#include "QueueArr.h"



QueueArr::QueueArr ()
{
    f=r= 0;
    s=10;
    q = new int[s];
};

QueueArr::QueueArr (int s)
{
    f=r= 0;
    this->s=s;
    q = new int[this->s];
};


void QueueArr::enQueue(int x)
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

int QueueArr::deQueue()
{
    int x=-1;
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

void QueueArr::display()
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
