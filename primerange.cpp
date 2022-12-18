// Program to print prime numbers in a range
#include<iostream>
using namespace std ;
int main ()
{
    int n , i , j , count ;
    cout << " Enter a number : " ;
    cin >> n ;
    cout << " Prime numbers upto " << n << " are :\n";
    for (i=2;i<=n;i++)
         {
                 count = 0 ;
                 for ( j=1;j<=i;j++)
                 {
                          if (i%j==0)
                          {
                            count++;
                          }
                 }
                 if (count==2)
                 cout << i << endl;
         }
         return 0 ;
}