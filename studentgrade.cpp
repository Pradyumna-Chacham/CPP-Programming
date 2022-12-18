// Program to find class division of a student based on percentage
#include<iostream>
using namespace std ;
int main ()
{
    int a , i , sum;
    float avg;
    cout << "Enter marks of student:\n";
    sum = 0;
    for ( i=0 ;i<=5 ;i++)
    {
        cin>>a;
        sum+=a;
    }
    cout << "Total marks of student:"<<sum<<endl ;
    avg=sum/6;
    if (avg<40)
    {   cout<<"Student Grade:F"<<endl;  }
    if (avg>=40 && avg<50)
    {   cout<<"Student Grade:E"<<endl;  }
    if (avg>=50 && avg<60)
    {   cout<<"Student Grade:D"<<endl;  }
    if (avg>=60 && avg<70)
    {   cout<<"Student Grade:C"<<endl;  }
    if (avg>=70 && avg<80)
    {   cout<<"Student Grade:B"<<endl;  }
    if (avg>=80 && avg<90)
    {   cout<<"Student Grade:A"<<endl;  }
    if (avg>=90 && avg<=100)
    {   cout<<"Student Grade:S"<<endl;  }
    return 0;
}