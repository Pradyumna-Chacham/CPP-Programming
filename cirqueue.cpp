//Circular queue
#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
class cirq
{
	T *cq;
	int front,rear,capacity;
	public:
	cirq(int max)
	{
		capacity=max;
		if (capacity<1)
		{
			cout<<"Capacity must be<=1"<<endl;
			exit(0);
		}
		cq=new T[capacity];
		front=rear=0;
	}
	bool isEmpty();
	bool isFull();
	void enqueue(T x);
	T dequeue();
	T frontele();
	T rearele();
	void display();
	void enhance();
};
template<class T>
bool cirq<T>:: isEmpty()
{
	if (front==rear)
		return true;
	else
		return false;
}
template <class T>
bool cirq<T>:: isFull()
{
	if (front==(rear+1)%capacity)
		return true;
	else 
		return false;
}
template <class T>
void cirq<T>:: enqueue(T x)
{
	if(isFull())
		enhance();
	rear=(rear+1)%capacity;
	cq[rear]=x;
}
template<class T>
T cirq<T>:: dequeue()
{
	if (isEmpty())
		return 0;
	front=(front+1)%capacity;
	T x=cq[front];

	if (front==rear)
		front=rear=0;
	return x;
}
template<class T>
void cirq<T>:: enhance()
{
	T *temp;
	temp=new T[2*capacity];
	for (int i=1;front!=rear;i++)
	{
		front=(front+1)%capacity;
		temp[i]=cq[front];
	}
	delete []cq;
	cq=temp;
	front=0;
	rear=capacity-1;
	capacity=2*capacity;
}
template<class T>
void cirq<T>:: display()
{
	if(isEmpty())
		cout<<"Circular Queue is Empty\n";
	else
	{
			cout<<"Circular Queue elements are:"<<endl;
			for(int i=(front+1)%capacity;i!=(rear+1)%capacity;i=(i+1)%capacity)
				cout<<cq[i]<<" ";
			cout<<endl;
	}
}
template<class T>
T cirq<T>:: frontele()
{
	if (isEmpty())
		cout<<"Queue is Empty"<<endl;
	else
		return cq[front+1];
}
template<class T>
T cirq<T>:: rearele()
{
	if (isEmpty())
		cout<<"Queue is empty"<<endl;
	else
		return cq[rear];
}
int main()
{
	cirq<int> c1(3);
	int c,d,x;
	cout<<"\nCIRCULAR QUEUE\n==========\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Front element\n5.Rear element\n"<<endl;
	while(1)
	{
		cout<<"Enter your choice:";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"Enter an element:";
				cin>>d;
				c1.enqueue(d);
				break;
			case 2: cout<<"Deleted element is:"<<c1.dequeue()<<endl;
				break;
			case 3: c1.display();
				break;
			case 4: cout<<"The front element of circular queue is:"<<c1.frontele()<<endl;
				break;
			case 5: cout<<"The rear element of circular queue is:"<<c1.rearele()<<endl;
				break;
			default: exit(1);
		}
	}
	return 0;
}

