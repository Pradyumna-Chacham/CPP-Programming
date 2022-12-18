//Program to create a calculaator using switch case
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    char x;
    cout<<"Enter two numbers:"<<endl;
    cin>>a>>b;
    cout<<"Enter operator:";
    cin>>x;
    switch(x)
    {
        case '+': 
            c=a+b;
            cout<<"The sum of "<<a<<" and "<<b<<" is: "<<c<<endl;
            break;
        case '-': 
            c=a-b;
            cout<<"The difference of "<<a<<" and "<<b<<" is: "<<c<<endl;
            break;
        case '*':
            c=a*b;
            cout<<"The product of "<<a<<" and "<<b<<" is: "<<c<<endl;
            break;
        case '/':
            c=a/b;
            cout<<"The quotient when "<<a<<" is divided by "<<b<<" is :"<<c<<endl;
            break;
        case '%':
            c=a%b;
            cout<<"The remainder when "<<a<<" is divided by "<<b<<" is:"<<c<<endl;
            break;
        default:
        cout<<"Not a valid operator.";
    }
    return 0;
}
