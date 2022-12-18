//Progrma to find area of circel,rectangle,using inline function
#include<iostream>
using namespace std;
inline float areacircle(float);
inline int areasquare(int);
inline int arearectangle(int,int);
int main()
{
    int s,l,b,square,rectangle;
    float r,circle;
    cout<<"Enter radius of circle:";
    cin>>r;
    circle=areacircle(r);
    cout<<"Area of circle is:"<<circle<<endl;
    cout<<"Enter length of side of square:";
    cin>>s;
    square=areasquare(s);
    cout<<"Area of square is:"<<square<<endl;
    cout<<"Enter length and breadth of rectangle:"<<endl;
    cin>>l>>b;
    rectangle=arearectangle(l,b);
    cout<<"Area of rectangle is:"<<rectangle<<endl;
    return 0;
}
inline float areacircle(float r)
{
    return (3.1415*r*r);
}
inline int areasquare(int s)
{
    return (s*s);
}
inline int arearectangle(int l, int b)
{
    return (l*b);
}