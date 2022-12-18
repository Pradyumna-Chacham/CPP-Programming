//Queue Implementatio using linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class qLL;
template<class T>
class Node
{
	T data;
	Node<T> *next;
	public:
	Node( T x)
	{
		data=x;
		next=NULL;
	}
	friend class qLL<T>;
};
template<class T>
class qLL
{
	Node<T> *front,*rear;
	public:
	qLL()
	{
		front=rear=NULL;
	}
	bool isempty()
	{
		if(front==NULL && rear==NULL)
			return true;
		else
			return false;
	}
	void push(T x);
	T pop();
	void display();
	T frontele();
	T rearele();
};
template<class T>
void qLL<T>::push(T x)
{
	Node<T> *nn=new Node<T>(x);
	if(isempty())
		front=rear=nn;
	else
	{
		rear->next=nn;
		rear=nn;
	}
}
template<class T>
T qLL<T>::pop()
{
	if(isempty())
		return 0;
	else
	{
		Node<T> *cur=front;
		T x=cur->data;
		front=front->next;
		if(front==NULL)
			rear=NULL;
		delete cur;
		return x;
	}
}
template<class T>
void qLL<T>:: display()
{
	if(isempty())
	{
		cout<<"Empty Queue"<<endl;
		return;
	}
	else
	{
		cout<<"The elements of the Queue are:";
		for(Node<T> *cur=front;cur;cur=cur->next)
			cout<<cur->data<<" ";
		cout<<endl;
	}
}
template<class T>
T qLL<T>::frontele()
{
	if(isempty())
		return 0;
	else
		return front->data;
}
template<class T>
T qLL<T>::rearele()
{
	if(isempty())
		return 0;
	else
		return rear->data;
}
int main()
{
	qLL<int> q;
	int c,x;
	cout<<"MENU\n1.Insert an element into queue\n2.Delete an element from a queue\n3.Display the elements of the queue\n4.Display front element of the queue\n5.Display back element of the queue\n";
	while(1)
	{
		cout<<"Enter your choice:";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"Enter an element:";
				cin>>x;
				q.push(x);
				break;
			case 2: cout<<"Deleted element from the queue is:"<<q.pop()<<endl;
				break;
			case 3: q.display();
				break;
			case 4: cout<<"The front element of the queue is:"<<q.frontele()<<endl;
				break;
			case 5: cout<<"The rear element of the queue is:"<<q.rearele()<<endl;
				break;
			default: exit(1);
		}
	}
	return 0;
}
