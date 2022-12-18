//Program to demonstrate function overriding
#include<iostream>
using namespace std;
class Base
{
	protected:
		int x;
	public:
		Base()
		{
			cout<<"Enter x:";
			cin>>x;
		}
		void show()
		{
			cout<<"x="<<x<<endl;
			cout<<"Base class show"<<endl;
		}
};
class Derived: public Base
{
	int y;
	public:
		Derived()
		{
			cout<<"Enter y:";
			cin>>y;
		}
		void show()
		{
			cout<<"y="<<y<<endl;
			cout<<"Derived class show"<<endl;
		}
};
int main()
{
	Base b;
	Base *bptr;
	Derived d;
	b.show();
	d.show();
	cout<<"accessing base class using derived class pointer:"<<endl;
	d.Base::show();
	return 0;
}

