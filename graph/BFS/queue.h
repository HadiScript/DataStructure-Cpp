#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class node
{
    int data;
    node *next;

public :
    node *f, *r;
    node()
    {
        f=nullptr;
        r=nullptr;
    };
    void enqueue(int x);

    int dequeue();
    int isEmpty();

};

void node :: enqueue(int x)
{
    node *t;
    t=new node;
    if(t==nullptr)
    {
        cout<<"queue is full"<<endl;
    }
    else
    {
        t->data = x;
        t->next=nullptr;
        if(f==nullptr)
        {
            f=r=nullptr;
        }
        else
        {
            r->next=t;
            r=t;
        }
    }

}

int node :: dequeue()
{
    int x=-1;
    node *t;

    if(f==nullptr)
    {
        cout<<"queue is empty now"<<endl;
    }
    else
    {
        x=f->data;
        t=f;
        f=f->next;
        delete t;
    }
    return x;
}

int isEmpty()
{
    return f==nullptr;
}



#endif // QUEUE_H_INCLUDED
