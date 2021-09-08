
#include<iostream>
using namespace std;

class node
{
    node *prev;
    node *next;
    int data;

public :
    node *first;
    node()
    {
        first = nullptr;
    }
    void inserting(int index, int x )
    {
        node *t;
        node *p =first;
        if(index == 0)
        {
            t = new node;
            t->data = x;
            t->prev = nullptr;
            t->next = first;
            first->prev = t;
            first = t;
        }
        else
        {
            for(int i=0; i<index-1; i++)
            {
                p=p->next;
            }
            t=new node;
            t->prev = p;
                      t->next =p->next;
            if(p->next)
            {
                p->next->prev = t;
            }
            p->next=t;

        }

    }

    int deleting(int index )
    {
        int x = -1;
        node *p =first;
        node *q;
        if(index == 0)
        {
            first = first->next;
            if(first)
            {
                first->prev=nullptr;
            }
            x = p->data;
            delete p;
        }
        else
        {
            for(int i=0; i<index-1; i++)
            {
                p=p->next;
            }
            p->prev->next=p->next;
            if(p->next)
            {
                p->next->prev = p->prev;
            }
            x = p->data;
            delete p;

        }
        return x;

    }


};



int main()
{


}
