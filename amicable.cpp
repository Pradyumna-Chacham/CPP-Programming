//Program to check whether two numbers are amicable
#include<iostream>
using namespace std;
int main()
{
    int x,y,i,sum1=0,sum2=0;
    cout<<"Enter two numbers:"<<endl;
    cin>>x>>y;
    for (i=1;i<x;i++)
    {
        if (x%i==0)
        sum1+=i;
    }
    for (i=1;i<y;i++)
    {
        if (y%i==0)
        sum2+=i;
    }
    if (sum1==y && sum2==x)
    cout<<x<<" and "<<y<<" are amicable numbers."<<endl;
    else
    cout<<x<<" and "<<y<<" are not amicable numbers."<<endl;
    return 0;    
}