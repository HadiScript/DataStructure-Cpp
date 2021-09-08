#include "node.h";

#include<iostream>
using namespace std;


int main()
{
   int a[] = {1,2,5,5};
    node *has, *hasf;
    int c,s, isSorted;
    node l;
   l.create(a, 4);
    // l.display();
    // l.recursiveDisplay(l.first);

    c = l.countAllNodes();
    s=l.sumOfAllNodes();

    // here we can also create an linked list by insertingNode function
   // l.insertingNode(0,100);
    //l.insertingNode(1,22);
   // l.sortedInsert(200);
    //l.sortedInsert(3);
    //l.sortedInsert(9);
    //l.sortedInsert(300);

    l.RemovingDuplication();

    l.display();

    l.ReverseList();
    cout<<endl<<"After Reversing a list";
    l.display();

 // cout<<endl<<"deleting node"<<l.DeleteANode(1);


    cout<<endl<<"total nodes of this linked list :"<<c;
    cout<<endl<<"sum of all the elements :"<<s;
    cout<<endl<<"max elements :"<<l.maxEle();

    has = l.Search(92);
    if(!has)
    {
        cout<<endl<<"not found :( ";
    }
    else
    {
        cout<<endl<<"oh yeah it found :) "<<has->data;
    }

    cout<<endl;

    // found & make it as first; improving linear search
    /*  hasf = l.Searching(17);
      if(!hasf)
      {
          cout<<"not found :( ";
      }
      cout<<"oh yeah it found :) "<<hasf->data;
      l.display();
      */


     isSorted =  l.IsSortedOrNot();
     if(isSorted == 0)
     {
         cout<<endl<<"list is not sorted :(";
     }else if(isSorted == 1) {
             cout<<endl<<"list is sorted :)";
     }




}
