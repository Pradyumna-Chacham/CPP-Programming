//Program to demonstrate class member functions
#include<iostream>
using namespace std;
class box
{
    float length;
    float breadth;
    float height;
    public:
    void getdata(float l, float b, float h);
    void volume();
};
void box:: getdata(float l, float b, float h)
{
    length=l;
    breadth=b;
    height=h;
}
void box:: volume()
{
    float vol;
    vol=length*breadth*height;
    cout<<"Volume of the box is:"<<vol<<endl;
}
int main()
{
    box b[4];
    float p,q,r;
    int n,i;
    cout<<"Enter how many boxes' details you want to calculate:";
    cin>>n;
    cout<<"Enter "<<n<<" box details:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" box details:"<<endl;
        cout<<"Enter length of box:";
        cin>>p;
        cout<<"Enter breadth of box:";
        cin>>q;
        cout<<"Enter height of box:";
        cin>>r;
        b[i].getdata(p,q,r);
        cout<<"=========="<<endl;
    }
    //Loop for printing box volume
    for(i=0;i<n;i++)
    {
        cout<<"Box "<<i+1<<endl;
        b[i].volume();
        cout<<"=========="<<endl;
    }
    return 0;
}