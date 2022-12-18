//Program to check whether a number is a mystery number or not
#include<iostream>
int rev(int);
using namespace std;
int main()
{
    int m,i,flag=0,result=0,t;
    cout<<"Enter a number:"<<endl;
    cin>>m;
    for (i=0;i<m;i++)
    {
        t=i+rev(i);
        if (t==m)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
    cout<<m<<" is a mystery number."<<endl;
    else
    cout<<m<<" is not a mystery number."<<endl;
    return 0;
}
//Function definition
int rev(int n)
{
    int sum=0,r;
    while (n!=0)
    {
        r=n%10;
        sum=sum*10+r;
        n=n/10;
    }
    return sum;
}