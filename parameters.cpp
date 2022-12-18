//Program on different parameter passing techniques
#include<iostream>
using namespace std;
void swap1(int , int); //call by value
void swap2(int *,int *); //call by reference
void swap3(int & ,int &) ; //call by address
void swap1(int a,int b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
void swap2(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void swap3(int &x,int &y)
{
    int t;
    t=x;
    x=y;
    y=t;
}
int main()
{
    int a,b;
    cout <<"Enter two numbers:";
    cin>>a>>b;
    swap1(a,b);
    cout<<"Value after swapping:";
    cout<<a<<"\t"<<b<<endl;
    swap2(&a,&b);
    cout<<"Value after swapping";
    cout<<a<<"\t"<<b<<endl;
    swap3(a,b);
    cout<<"Value after swapping:";
    cout<<a<<"\t"<<b<<endl;
    return 0;
}