//Nested member functions
#include<iostream>
using namespace std;
class number
{
    int n;
    int square (int n)
    {
        return (n*n);
    }
    int cube (int n)
    {
        return (n*n*n);
    }
    public:
    void getdata(int a)
    {
        n=a;
    }
    void display();
};
void number:: display()
{
    cout<<"The number is:"<<n<<endl;
    cout<<"The square of the number is:"<<square(n)<<endl;
    cout<<"The cube of the number is:"<<cube(n)<<endl;
}
int main()
{
    number n;
    int b;
    cout<<"Enter a number:";
    cin>>b;
    n.getdata(b);
    n.display();
    return 0;
}