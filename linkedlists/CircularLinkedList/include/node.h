#ifndef NODE_H
#define NODE_H


class node
{
    int data;
    node *next;
public :

    node *head;
    node();
    void create(int a[], int n);
    void dislpay();
    int lenght();
    void Rdisplay(node *h);

    void inserting(int index,int x);
    int deleting(int index);

};

#endif // NODE_H
