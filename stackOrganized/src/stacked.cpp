#include "stacked.h"

stacked::stacked()
{
    top =nullptr;
}

void stacked ::push(char x)
{
    node *t = new node;
    if(t==nullptr)
    {
        cout<<"stack is full"<<endl; // becouse of heap
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char stacked::pop()
{
    char x;
    if(top == nullptr)
    {
        cout<<"stack is empty :( "<<endl;
    }
    else
    {
        x=top->data;
        node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void stacked::display()
{
    node *p =top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
};

int stacked::matched(string s)
{

    for( int i=0; s[i]!='\0'; i++ )
    {
        if(s[i]=='(')
        {
            push('(');
        }
        else if(s[i] == ')')
        {
            if(top == nullptr)
            {
                return 0;
            }
            pop();
        }
    }
    if(top == nullptr)
        return 1;
    else
    {
        return 0;
    }
}

int stacked::precedence(char x)
{
    if( x=='+' || x=='-' )
        return 1;
    if(x=='/' || x=='*');
    return 2;
    return 0;
}

int stacked :: isOperand(char x)
{

    if(x == '+' || x=='-'  || x=='/' || x=='*' )
    {
        return 0;
    }
    else return 1;

}


string * stacked:: InToPost(string In)
{

    int i,j;
    string *postFix;

    while(In[i]!='\0')
    {
        if(isOperand(In[i]))
        {
            postFix[j++] = In[i++];
        }
        else
        {
            if(precedence(In[i] > precedence(top->data)))
            {
                push(In[i++]);
            }
            else
            {
                postFix[j++] = pop();
            }
        }
    }
    while(top != nullptr)
    {
        postFix[j++] = pop();
    }
    postFix[j] = '\0';
    return postFix;
}

int eveluation(char x)
{

    int r,x1,x2;

    for(int i=0; x!='\0'; i++)
    {
        if(isOperand())
        {
            push(x[i] - '0')
        }
        else
        {
            x1 = pop();
            x2 = pop();

            switch(x[i])
            {
            case '+':
                r = x1+x2;
                push(r);
                break;
            case '-':
                r = x1-x2;
                push(r);
                break;
            case '+':
                r = x1*x2;
                push(r);
                break;
            }

        }
    }
    return pop();

}
