// Program to read an array of elemeents and print sorted elements using dynamic memory all
#include<iostream>
using namespace std;
int main ()
{
          int n,i,temp,j;
          cout<<"Enter how many elements you want to store in the array:";
          cin>>n ;
          int *a= new int[n];
          cout<<"Enter "<<n<<" elements : "<<endl;
          // Loop for reading elements
          for (i=0;i<n;i++)
          {
            cin>>( a + i );
          }                    
          // Sorting array using bubble sort
          for (i=0;i<n;i++)
          {
                for (j=0;j<n-i-1;j++)
                {
                    if ( a[j]>a[ j + 1])
                    {
                        temp =* ( a + j );
                        * ( a + j )= * ( a + j + 1 );
                        * ( a + j + 1 )=temp;
                    }
                }
          }
           // Printing sorted array
           cout << " Sorted array elements are:"<<endl;  
            for (i=0;i<n;i++)
            {
                cout << ( a + 1 ) << " " ;
            }
            delete a;
            return 0;
      
