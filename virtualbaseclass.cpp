//Program to demonstrate virtual base class
#include<iostream>
using namespace std;
class Gparent
{
	int a;
	public:
		Gparent()
		{
			cout<<"Grandparent class constructor"<<endl;
			cout<<"Enter a:";
			cin>>a;
		}
		void put_a()
		{
			cout<<"Grandparent class member function:"<<endl;
			cout<<"a= "<<a<<endl;
		}
};
class Parent1: virtual public Gparent
{
	int b;
	public:
		Parent1()
		{
			cout<<"Parent 1 class constructor"<<endl;
			cout<<"Enter b:";
			cin>>b;
		}
		void put_b()
		{
			cout<<"Parent class member function:"<<endl;
			cout<<"b= "<<b<<endl;
		}
};
class Parent2 :public virtual Gparent
{
	int c;
	public:
		Parent2()
		{
			cout<<"Parent 2 class constructor:"<<endl;
			cout<<"Enter c:";
			cin>>c;
		}
		void put_c()
		{
			cout<<"Parent 2 class member function:"<<endl;
			cout<<"c= "<<c<<endl;
		}
};
class Gchild : public Parent1, public Parent2
{
	int d;
	public:
		Gchild()
		{
			cout<<"GrandChild class constructor"<<endl;
			cout<<"Enter d: "<<endl;
			cin>>d;
		}
		void display()
		{
			put_a();
			put_b();
			put_c();
			cout<<"GrandChild class member function:"<<endl;
			cout<<"d:"<<d<<endl;
		}
};
int main()
{
	Gchild c1;
	cout<<"Calling super class functions from base class:"<<endl;
	c1.display();
	return 0;
}

