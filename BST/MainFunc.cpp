#include<iostream>
using namespace std;

class node
{
public :
    node *lchild, *rchild;
    int data;
};

class tree
{
public :
    node *root;

    tree()
    {
        root = nullptr;
    };

    void Insert(int k);
    void inorder(node *t);
    node* searching(int k);
    node* InPre(node *p);
    node* InSucc(node *p);
    int Height(node *p);
    node* Delete(node *p, int key);
};


void tree ::Insert(int k)
{
    node *t=root;
    node *r,*p;

    if(root == nullptr)
    {
        p = new node;
        p->data = k;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }
    while (t!=nullptr)
    {
        r=t;
        if(k<t->data)
        {
            t = t->lchild;
        }
        else if(k>t->data)
        {
            t=t->rchild;
        }
        else
        {
            return ;
        }
    }

    p = new node;
    p->data = k;
    p->lchild = p->rchild = nullptr;

    if(k < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }

};

void tree :: inorder(node *t)
{

    if(t)
    {
        inorder(t->lchild);
        cout<<t->data<<" ";
        inorder(t->rchild);
    }
}

node * tree::searching(int k)
{
    node *t = root;
    while(t)
    {
        if(k == t->data)
        {
            cout<<t;
        }
        else if(k < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    return nullptr;
}

int tree:: Height( node *p)
{
    int x,y;
    if(p==nullptr)return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
node* tree :: InPre( node *p)
{
    while(p && p->rchild!=nullptr)
        p=p->rchild;

    return p;
}
node* tree:: InSucc( node *p)
{
    while(p && p->lchild!=nullptr)
        p=p->lchild;

    return p;
}
node* tree :: Delete( node *p,int key)
{
    node *q;

    if(p==nullptr)
        return nullptr;
    if(p->lchild==nullptr && p->rchild==nullptr)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;

    }

    if(key < p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }


    }
    return p;
}

int main()
{
    tree t;
    t.Insert(10);
    t.Insert(30);
    t.Insert(40);
    t.inorder(t.root);

    node *temp;

    temp = t.searching(20);
    if(temp != nullptr)
    {
        cout<<endl<<"element fond";
    }
    else
    {
        cout<<endl<<"not fond"<<endl;
    }

    t.Delete(t.root, 30);

}
