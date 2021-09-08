

#include<iostream>
#include<algorithm>
using namespace std;

class Arr
{
    //  int *A;
    int A[20];
    int s;
    int len;

public :
    Arr(int init[],int s, int l)
    {


        this->s=s;
        len = l;
        for(int i=0; i<len; i++)
        {
            A[i] = init[i];
        }


        //  A = new int[this->s];
    }

    /*
      ~Arr(){
          delete A;
      };
    void inserting(int n){

          cout<<"enter the all elements: "<<endl;
             for(int i=0; i<n; i++){
                  len++;
             cin>>A[i];
             }
      }
      */

    void display()
    {
        for( int i=0; i<len; i++ )
        {
            cout<<A[i];
        }
    }

    int Lenght()
    {
        return len;
    }

    void Append(int x);
    void Insert(int index, int x);
    int Del(int index);
    int linearSearch(int k);
    int TranspositionProd(int k);
    int binarySearch(int key);
    //int RecbinarySearch(int key);
    int Max();
    int SumOfAll();
    void Reverse();
    void Reverse2();
    void sortedInsert(int x);
    int isSorted();
    void SignShifting();
};

void Arr::Append(int x)
{

    if(len < s)
    {
        A[len++] = x;
    }
    else
    {
        cout<<"Sorry, No space :( "<<endl;
    }

}

void Arr::Insert(int index, int x)
{
    if(index >= 0 && index <= len)
    {
        for(int i=len; i>index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = x;
        len++;
    }
}




int Arr::Del(int index)
{

    int x=0;
    if(index >=0 && index<len)
    {
        x=A[index];
        for(int i=index; i<len-1; i++)
        {
            A[i] = A[i+1];
        }
        len--;
        return x;
    }
    return 0;

}


int Arr::linearSearch(int k)
{
    for(int i=0; i<len; i++)
    {
        if(k==A[i])
        {
            return i;
        }
    }
    return -1;

}

int Arr::TranspositionProd(int k)
{
    for(int i=0; i<len; i++)
    {
        if(k==A[i])
        {
            swap(A[i], A[i-1]);
            return i;
        }
    }
    return -1;
}

int Arr::binarySearch(int key)
{

    int l,h,mid;
    l=0;
    h = len-1;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
        {
            h = mid-1;
        }
        else
        {
            h=mid+1;
        }

    }
    return -1;

}


/*
int Arr::RecbinarySearch(int a[], int l, int h, int key){
int l,h,mid;
    l=0;
    h = len-1;

    if(l<=h){
        mid = (l+h)/2;
        if(key == A[mid]){
            return mid;
        }
        else if(key < A[mid]) {
            return RecbinarySearch(a, l,mid-1)
        }
        else{
            return RecbinarySearch(a, l, mid+1)
        }

    }

}

*/

int Arr::Max()
{
    int m = A[0];
    for(int i=1; i<len; i++ )
    {
        if(A[i]>m)
        {
            m = A[i];
        }
    }
    return m;

}

int Arr::SumOfAll()
{
    int t=0;
    for(int i=0; i<len; i++)
    {
        t = t+A[i];
    }
    return t;
}

//With Auxilary
void Arr::Reverse()
{

    // auxilary array
    int *B;
    B = new int[len];
    for(int i = len-1, j = 0; i>=0; i--, j++)
    {
        B[j] = A[i];
    }
    for(int i=0; i<len; i++)
    {
        A[i] = B[i];
    }

}


void Arr::Reverse2()
{

    int i,j;
    for(i=0, j=len-1; i<j; i++,j--)
    {
        swap(A[i], A[j]);
    }

}


void Arr::sortedInsert(int x)
{

    int i = len-1;
    while(A[i] > x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
}


int Arr::isSorted()
{


    for(int i=0; i<len-1; i++)
    {
        if(A[i] > A[i+1])
        {
            return -1;
        }
    }
    return 1;


}

// negative number on left of array and positive on right side [-1,-2,4,5]
void Arr::SignShifting()
{
    int i=0;
    int j=len-1;

    while(j>i)
    {

        while(A[i] < 0)
        {
            i++;
        };
        while(A[j] >= 0)
        {
            j--;
        };

        if(i>j)
        {
            swap(A[i], A[j]);
        }
    }

} //order of n


int main()
{
 int init[] = {1,20,3,40,5};


    Arr ar(init, 10, 5);


    // ar.inserting(5);
    // ar.Insert(3, 100);
    //ar.Append(90);
    // cout<< ar.Del(5);



    //cout<<endl<<ar.linearSearch(9);

    //  cout<<ar.TranspositionProd(4);

    // cout<<ar.binarySearch(5);

    //ar.Reverse();
    //ar.Reverse2();

   // ar.sortedInsert(33);

 //  ar.SignShifting();

    cout<<endl;
    ar.display();

    cout<<endl;
    cout<<"lenght of array is :"<<ar.Lenght()<<endl;
    cout<<ar.isSorted();




}
