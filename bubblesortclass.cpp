//Program to create a class and implement bubble sort
#include<iostream>
using namespace std;
class bubble
{
    int n;
    int b[20];
    public:
    void size(int s)
    {
        n=s;
    }
    void read(int r[20])
    {
       int i;
       for (i=0;i<n;i++)
       {
            b[i]=r[i];
       }
    }
    void sort()
    {
        // Sorting array using bubble sort
        int i,j,temp;
        for (i=0;i<n-1;i++)
        {
            for (j=0;j<n-i-1;j++)
            {
                if ( b[j]>b[j + 1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        }

    }
    void display()
    {
        cout<<"Sorted array elements are:"<<endl;
        int i;
        for (i=0;i<n;i++)
        {
            cout<<b[i]<<"\t";
        }
        cout<<"\n";
    }
};
int main()
{
    bubble s;
    int n,a[20],i;
    cout<<"Enter size of array:";
    cin>>n;
    s.size(n);
    cout<<"Enter "<<n<<" elements:"<<endl;
    //Loop for reading elements
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //Passing the rray to sort function
    s.read(a);
    //Sorting the array
    s.sort();
    //Printing the array
    s.display();
    return 0;
}
