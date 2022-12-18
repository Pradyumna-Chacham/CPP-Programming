//Program to demonstrate order of constructor inheritance
#include<iostream>
using namespace std;
class Base
{
	int x;
	public:
		Base()
		{
			cout<<"Base class constructor"<<endl;
		}
		~Base()
		{
			cout<<"Base class destructor"<<endl;
		}
};
class Derived: public Base
{
	int y;
	public:
		Derived()
		{
			cout<<"Derived class constructor"<<endl;
		}
		~Derived()
		{
			cout<<"Derived class destructor"<<endl;
		}
};
int main()
{
	Base b;
	Derived d;
	return 0;
}
