#include "node.h"

#include<iostream>
using namespace std;


node ::node()
{
    head = nullptr;
}

void node::create(int a[], int n)
{
    node *t, *last;

    head = new node;
    head->data = a[0];
    head->next = head;
    last = head;

    for(int i=1; i<n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = last ->next;
        last->next = t;
        last = t;
    }

}

void node::dislpay()
{
    node *h = head;

    /*do
    {
        cout<<h->data<<",";
        h=h->next;
    }while(h!=head); */

    while(h->next != head)
    {
        cout<<h->data<<",";
        h=h->next;
    }

    cout<<endl;
}

void node::Rdisplay(node *h)
{
    static int f = 0;

    if(h!=head || f==0)
    {
        f =1;
        cout<<h->data;
        Rdisplay(h->next);
    }
    f = 0;

}

int node :: lenght()
{
    int l = 0;

    node *h = head;
    while (h->next != head)
    {
        l++;
        h=h->next;
    }
    return l;

}

void node ::inserting(int index,int x)
{
    node *h = head;
    node *t;

    if(index < 0 || index > lenght())
    {
        return;
    }

    if(index == 0 )
    {
        t = new node;
        t->data = x;
        if(head == nullptr)
        {
            // it going to be a first node
            head = t;
            head->next = head;
        }
        else
        {
            while(h->next != head)
            {
                h=h->next;
            }
            h->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for( int i=0; i<index-1; i++) h = h->next;
        t = new node;
        t->data = x;
        t->next = h->next;
        h->next = t;
    }

}

int node ::deleting( int index )
{
    node *p = head;
    node *q;
    int x =-1;

    if(index < 0 || index > lenght()){
        return -1;
    }

    if(index == 1){
        while(p->next != head){
            p=p->next;
        }

        x = head->data;
        if(head == p){
            delete head;
            head = nullptr;
        }
        else{
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else{
        for(int i=0; i<index-2; i++){
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        x=q->data;
        delete q;
    }
}
