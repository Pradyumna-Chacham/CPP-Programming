//Program to demonstrate function overload
#include<iostream>
using namespace std;
float area(float ); //Circle
float area(int); //square
float area (int,int); //rectangle
float perimeter (float); //Circumstance
float perimeter(int);
float perimeter(int,int); //rectangle
int main()
{
    int s,l,b;
    float r;
    cout<<"Enter radius of circle:";
    cin>>r;
    cout<<"Area of circle is:"<<area(r)<<endl;
    cout<<"Circumference of circle is:"<<perimeter(r)<<endl;
    cout<<"Enter length of side of square:";
    cin>>s;
    cout<<"Area of square is:"<<area(s)<<endl;
    cout<<"Perimeter of square is:"<<perimeter(s)<<endl;
    cout<<"Enter length and breadth of rectangle:"<<endl;
    cin>>l>>b;
    cout<<"Area of rectangle:"<<area(l,b)<<endl;
    cout<<"Perimeter of rectangle:"<<perimeter(l,b)<<endl;
    return 0;
}
float area (float r) //Circle
{
    return (3.1415*r*r);
}
float area (int x)
{
    return (x*x);
}
float area (int a, int b)
{
    return (a*b);
}
float perimeter (float r)
{
    return (2*3.1415*r);
}
float perimeter (int x)
{
    return (4*x);
}
float perimeter (int a, int b)
{
    return (2*(a+b));
}