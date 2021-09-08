#include "node.h"
#include<iostream>
using namespace std;



void node :: create(int a[], int n)
{

    node *t, *last;

    first = new node;
    first->data = a[0];
    first->next = nullptr;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void node :: display()
{
    node *p = first;

    while(p)
    {
        cout<<"  "<<p->data;
        p=p->next;
    }
}

void node :: recursiveDisplay(node *p)
{


    if(p!=nullptr)
    {
        cout<<p->data<<" ";
        recursiveDisplay(p->next);
    }
}


int node :: countAllNodes()
{
    node *p =first;
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;

}

int node :: sumOfAllNodes()
{
    node *p = first;

    int s = 0;
    while(p)
    {
        s += p->data;
        p=p->next;
    }
    return s;


}

int node :: maxEle()
{
    node *p=first;
    int max = -9;
    while(p)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p=p->next;
    }
    return max;
}

node* node ::Search(int k)
{
    node *p=first;

    while(p)
    {
        if(p->data == k)
        {
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

node* node ::Searching(int key)
{

    node *p=first;
    node *qq=nullptr;

    while(p)
    {
        if(p->data == key)
        {
            // make it as first node
            qq->next = p->next;
            p->next = first;
            first = p;

            return p;

        }
        qq=p;
        p=p->next;
    }
    return nullptr;
}

void node ::insertingNode(int index, int key)
{

    node *t, *p = first;

    if(index < 0 ||  index > countAllNodes())
    {
        return; //  has a invalid index ;
    }

    t=new node;
    t->data = key;

    if(index == 0) // inserting at first position
    {
        t->next= first;
        first = t;
    }
    else
    {
        // put in given index
        for(int i=0; i<index-1; i++)
        {
            p=p->next;
        }
        t->next = p->next;
        p->next=t;

    }

}


void node :: sortedInsert(int key)
{

    node *p = first, *t, *q = nullptr;

    t= new node;
    t->data = key;
    t->next = nullptr;

    if(first == nullptr)
    {
        first = t;
    }
    else
    {
        while(p && p->data < key)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}


int node::DeleteANode(int pos)
{
    node *p = first, *q =nullptr;
    int x=-1;

    if(pos < 1 && pos > countAllNodes())
    {
        return -1;
    }

    if(pos == 1)
    {
        //first node deletions
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for(int i=0; i<pos-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }

}

int node::IsSortedOrNot()
{

    node *p=first;

    int x = -1;

    while(p!=nullptr)
{
    if(p->data < x) return 0;
        x = p->data;
        p=p->next;
    }
    return 1;

}


void node::RemovingDuplication(){
    node *p =first;
     node *q = p->next;

     while(q!=nullptr){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }else{
            p->next = q->next;
            delete q;
            q=p->next;

        }
     }

}

void node::ReverseList(){
    node *p=first;
    node *q = nullptr,*r = nullptr;

    while(p!=nullptr){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;

}
