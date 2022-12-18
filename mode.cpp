//Program to find mode of given data
#include<iostream>
using namespace std;
int main()
{
    int i,j,n,max=0,count=0,maxcount=0;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements:"<<endl;
    //Loop for scanning elements
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //Loop for printing elements
    cout<<"Array elements are:"<<endl;
    for (i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    //Mode
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            if(a[i]=a[j])
            {
                count++;
            }
        }
        if (count>maxcount)
        {
            maxcount=count;
            max=a[i];
        }
    }
    cout<<"The mode of the given data is:"<<max<<endl;
    cout<<max<<" occurs "<<count<<" times in the data:";
    return 0;
}