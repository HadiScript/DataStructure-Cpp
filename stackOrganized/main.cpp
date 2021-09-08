#include<iostream>
#include"node.h"
#include "stacked.h"

using namespace std;

int main()
{
    stacked s;
    //string exp = "((a+b)))*(a-d))";
    string infix = "a+b*c";
    s.push('#');

    string *postFix = s.InToPost(infix) ;
    cout<<postFix;

    //cout<< s.matched(exp);

}
