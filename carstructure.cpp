//Program to demonstrate on car structure
#include<iostream>
using namespace std;
typedef struct car
{
    char brand[10];
    float mileage;
    long int price;
}car;
int main()
{
    int i,n;
    cout<<"Enter how many car details you want to store:";
    cin>>n;
    car c[n];
    //Loop for entering details
    for (i=0;i<n;i++)
    {
        cout<<"Enter car "<<i+1<<" details:"<<endl;
        cout<<"Enter car brand:";
        cin>>c[i].brand;
        cout<<"Enter car mileage:"<<endl;
        cin>>c[i].mileage;
        cout<<"Enter car price:";
        cin>>c[i].price;
        cout<<"=========="<<endl;
    }
    //Loop for printing details
    for (i=0;i<n;i++)
    {
        cout<<"Car"<<i+1<<" details:"<<endl;
        cout<<"Car brand name:"<<c[i].brand<<endl;
        cout<<"Car mileage:"<<c[i].mileage<<endl;
        cout<<"Car price:"<<c[i].price<<endl;
        cout<<"=========="<<endl;
    }
    return 0;
}