//Program to find simple ineterest using default arguments
#include<iostream>
using namespace std;
float interest (float p, float t, float r=2)
{
    float i;
    i=((p*t*r)/100);
    return i;
}
int main()
{
    float p,t,i,r,a;
    char x;
    cout<<"Enter principal amount:";
    cin>>p;
    cout<<"Enter time period of loan:";
    cin>>t;
    cout<<"Do you want to enter rate of interest?(Y/N):"<<endl;
    cin>>x;
    if (x=='y' || x=='Y')
    {
        cin>>r;
        i=interest(p,t,r);
        cout<<"Interest amount is:"<<i<<endl;
        cout<<"Amount owed is:"<<(p+i)<<endl;
    }
    else if (x=='N' || x=='n')
    {
        i=interest(p,t);
        cout<<"Interest amount is:"<<i<<endl;
        cout<<"Amount owed is:"<<(p+i)<<endl;
    }
    else
    cout<<"Not a calid choice";
    return 0;
}