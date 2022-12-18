//Program to find cumulative sum of numbers
#include<iostream>
using namespace std;
int main()
{
    int n,i,j,sum=0,sum1=0;
    cout<<"Enter number upto which you want to compute the cumulative sum:";
    cin>>n;
    for (i=0;i<=n;i++)
    {
        sum=0;
        for (j=0;j<=i;j++)
        {
            sum+=j;
        }
        sum1+=sum;
    }
    cout<<"Cumulative sum upto "<<n<<" is: "<<sum1<<endl;
}