//Stack using Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
class stack;
template <class T>
class Node
{
	T data;
	Node<T> *next;
	friend class stack<T>;
	public:
	Node( T x)
	{
		data=x;
		next=NULL;
	}
};
template<class T>
class stack
{
	Node<T> *top;
	public:
	stack()
	{
		top=NULL;
	}
	void push(T x);
	T pop();
	void display();
	T topmost();
};
template<class T>
void stack<T>:: push(T x)
{
	Node<T> *nn=new Node<T>(x);
	if(top!=NULL)
		nn->next=top;
	top=nn;
	
}
template<class T>
T stack<T>::pop()
{
	if(top!=NULL)
	{
		Node<T> *tmp=top;
		top=top->next;
		T x=tmp->data;
		delete tmp;
		return x;
	}
	return 0;
}
template <class T>
void stack<T>::display()
{
	if(top!=NULL)
	{
		Node<T> *cur=top;
		while(cur!=NULL)
		{
			cout<<cur->data<<endl;
			cur=cur->next;
		}
		return;
	}
	else
	{
		cout<<"Stack underflow"<<endl;
		return;
	}
}
template<class T>
T stack<T>::topmost()
{
	if(top!=NULL)
		return top->data;
	else
		return 0;

}
int main()
{
	stack<int> s;
	int c,d,x;
	cout<<"MENU\n1.Push\n2.Pop\n3.Display\n4.Top most element\n";
	while(1)
	{
		cout<<"Enter your choice:";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"Enter an element:";
				cin>>x;
				s.push(x);
				break;
			case 2: cout<<"The deleted element is:"<<s.pop()<<endl;
				break;
			case 3: cout<<"The elements in the stack are:"<<endl;
				s.display();
				break;
			case 4: cout<<" The topmost element of the stack is: "<<s.topmost()<<endl;
				break;
			default: exit(1);
		}
	}
	return 0;
}

	


