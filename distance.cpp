// Program to find the distance between two points
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int x1 , y1 , x2 , y2 ;
    float d ;
    cout <<"Enter coordinates of first point:\n";
    cin >>x1>>y1;
    cout <<"Enter coordinates of second point:\n";
    cin >>x2>>y2;
    d=sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    cout << "Distance between two points:"<<d<<endl ;
    return 0 ;
}
                                                