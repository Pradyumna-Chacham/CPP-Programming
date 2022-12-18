//Program to demonstrate abstract class
#include<iostream>
using namespace std;
class base
{
	protected:
		int a,b;
	public:
		virtual void set_values()=0;
		virtual void get_values()=0;
};
class derived: public base
{
	public:
		void set_values()
		{
			cout<<"Enter values:"<<endl;
			cin>>a>>b;
		}
		void get_values()
		{
			cout<<"Values: "<<endl;
			cout<<"a:"<<a<<endl;
			cout<<"b:"<<b<<endl;
		}
};//End derived class
int main()
{
	base *b;
	derived d;
	b=&d;
	b->set_values();
	b->get_values();
	return 0;
}



