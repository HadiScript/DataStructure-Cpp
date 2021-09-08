#include<iostream>
using namespace std;


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
            f=r=t;
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

int node :: isEmpty()
{
    return f==nullptr;
}


void BFS(int G[][7], int start,int n)
{
    int i=start;
    node q;
    int visited[7] = {0}; // init as zero

    cout<<i;
    visited[i] = 1;
    q.enqueue(i);

    while(!q.isEmpty())
    {
        i=q.dequeue();
        for(int j=1; j<=n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                cout<<j;
                visited[j]=  1;
                q.enqueue(j);
            }
        }

    }


}

int main()
{
    int G[7][7] = {{0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    BFS(G,4,7);

    return 0;

}
