

#include<iostream>
using namespace std;

class Arr{
     int *A;

    int s;
    int len;

public :
    Arr(int s,){
        this->s=s;
        int len = 0;
        A = new int[this->s];
    }

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

    void display(){
        for( int i=0; i<len; i++ ){
            cout<<A[i];
        }
    }

    int Lenght(){
        return len;
    }

    void Append(int x);
    void Insert(int index, int x);
    int Del(int index);
};

void Arr::Append(int x){

    if(len < s){
        A[len++] = x;
    }
    else{
        cout<<"Sorry, No space :( "<<endl;
    }

}

void Arr::Insert(int index, int x){
    if(index >= 0 && index <= len){
        for(int i=len; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        len++;
    }

}

int Arr::Del(int index){

    int x=0;
    if(index >=0 && index<len){
        x=A[index];
        for(int i=index; i<len-1; i++){
            A[i] = A[i+1];
        }
        len--;
        return x;
    }
    return 0;

}



int main(){
    Arr ar(7);
    ar.inserting(5);

    ar.Append(90);

    ar.display();
   cout<< ar.Del(5);

    ar.Insert(3, 100);



    cout<<endl;
    cout<<"lenght of array is :"<<ar.Lenght()<<endl;

}
