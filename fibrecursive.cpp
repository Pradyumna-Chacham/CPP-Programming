//Program to implement fibonacci series using recursion
#include<iostream>
using namespace std;
int fib(int);
int main()
{
    int n,i,x;
    cout<<"Enter upto which umber you have to print Fibonacci series:";
    cin>>n;
    cout<<"Fibonacci series upto "<<n<<" :"<<endl;
    for(i=0;i<n;i++)
    {
        x=fib(i);
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
int fib (int n)
{
    if (n==1)
    return 0;
    if (n==2)
    return 1;
    else
    return (fib(n-1)+fib(n-2));
}