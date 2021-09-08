#ifndef STACKED_H
#define STACKED_H

#include<cstring>

#include<iostream>
using namespace std;

#include "node.h"


class stacked
{
    node *top;

public :

    stacked();
    void push(char x);
    char pop();
    void display();
    int matched(string s);
    int isOperand(char x);
    int eveluation(char x);
    string * InToPost(string In);
    int precedence(char x);

};

#endif // STACKED_H
