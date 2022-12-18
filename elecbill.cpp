//Program to find electricity bill
#include<iostream>
using namespace std;
int main()
{
    int e;
    float p;
    cout <<"Enter number of units consumed:\n";
    cin>>e;
    if (e==0)
    {
        p=50;
    }
    if (e!=0 && e<=100)
    {
        p=60*e;
    }
    if (e>=100 && e<=300)
    {
        p=60*100+80*(e-100);
    }
    if (e>300)
    {
        p+=60*e+80*(e-100)+90*(e-300);
    }
    if (p>3000)
    p+=(15*p)/100;
    cout<< "The electricity bill in rupees is:"<<p<<endl;
    return 0;
}