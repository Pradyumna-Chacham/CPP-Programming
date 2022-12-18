//Outside and inside class functions
#include<iostream>
using namespace std;
class box
{
    float length;
    float breadth;
    float height;
    public:
    void getdata (float l, float b, float h);
    void volume()
    {
        float vol;
        vol=length*breadth*height;
        cout<<"Volume of the box is:"<<vol<<endl;
    }
};
void box:: getdata(float l, float b, float h)
{
    length=l;
    breadth=b;
    height=h;
}
int main()
{
    box b1,b2,b3;
    b1.getdata(10,20,30);
    b1.volume();
    b2.getdata(20,30,40);
    b2.volume();
    b3.getdata(30,40,50);
    b3.volume();
    return 0;
}