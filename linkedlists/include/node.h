#ifndef NODE_H
#define NODE_H


class node
{

public :
    int data;
    node *next;
    node *first;
    node ()
    {
        first = nullptr;
    }
    void create(int a[], int n);
    void display();
    void recursiveDisplay(node *p);
    int countAllNodes();
    int sumOfAllNodes();
    int maxEle();
    node * Search(int k);
    void insertingNode(int index, int key);
    void sortedInsert(int key);
    int DeleteANode(int pos);
    int IsSortedOrNot();
    void RemovingDuplication();
    void ReverseList();

    //if keys found make it first node also
    node * Searching(int key);
};


#endif // NODE_H
