//Program to use enum datatype
#include<iostream>
using namespace std;
int main()
{
    enum months{January=1,February,March,April,May,June,July,August,September,October,November,December};
    months month;
    int ch;
    cout<<"Enter month number:";
    cin>>ch;
    switch(ch)
    {
        case January: cout<<"No.of days=31"<<endl;
            break;
        case February: cout<<"No.of days=28"<<endl;
            break;
        case March : cout<<"No.of days=31"<<endl;
            break;
        case April : cout<<"No.of days=30"<<endl;
            break;
        case May: cout<<"No.of days=31"<<endl;
            break;
        case June: cout<<"No.of days=30"<<endl;
            break;
        case July: cout<<"No.of days=31"<<endl;
            break;
        case August: cout<<"No.of days=31"<<endl;
            break;
        case September: cout<<"No.of days=30"<<endl;
            break;
        case October: cout<<"No.of days=31"<<endl;
            break;
        case November: cout<<"No.of days=30"<<endl;
            break;
        case December: cout<<"No.of days=31"<<endl;
            break;
    }
    return 0;
}