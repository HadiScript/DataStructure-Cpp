#include "node.h"

#include<iostream>
using namespace std;

int main()
{
    node l;

    int A[] = {2,3,4,5,6};

   l.create(A,5);

 //   l.inserting(0,1);
 //  cout<<"deleted nodes data"<< l.deleting(1)<<endl;


    l.dislpay();

}
