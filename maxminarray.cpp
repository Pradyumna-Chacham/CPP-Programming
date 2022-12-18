//Program to find the maximum nad minimum of an array
#include<iostream>
using namespace std;
int main()
{
    int a[20],n,i,max,min;
    cout<<"Enter how many elements you want to store in the array:";
    cin>>n;
    cout<<"\nEnter "<<n<<" elements:\n";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Array elements are:\n";
    for (i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    max=min=a[0];
    for (i=0;i<n;i++)
    {
        if (a[i]>max)
        max=a[i];
        if (a[i]<min)
        min=a[i];
    }
    cout<<"\nMaximum of array elements:"<<max<<endl;
    cout<<"Minimum of array elements:"<<min<<endl;
    return 0;
}
