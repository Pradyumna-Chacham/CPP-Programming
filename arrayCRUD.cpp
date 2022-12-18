//Program to insert an element into an array at a position
#include<iostream>
using namespace std;
int main()
{
    int ind,a[10],val,n,i;
    cout<<"Enter how many elements you want to store in the array:";
    cin>>n;
    cout<<"Enter "<<n<<" elements:"<<endl;
    //Loop for scanning elements
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //Loop for printing elements
    cout<<"Array elements are:\n";
    for (i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nEnter value which you want to add to the array:";
    cin>>val;
    cout<<"Enter at which index the element must be added to the array:";
    cin>>ind;
    a[ind]=val;
    //Loop for printing
    for (i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;

}