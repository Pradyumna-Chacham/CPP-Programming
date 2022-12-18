//Program to demonstrate on scope resolution operator
#include<iostream>
using namespace std;
int m=10;
int main()
{
    int m;
    m=20;
    cout<<"Value of m in local:"<<m<<endl;
    cout<<"Value of m in global:"<<::m<<endl;
    return 0;
}