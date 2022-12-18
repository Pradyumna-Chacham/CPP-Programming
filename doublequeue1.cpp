//Double queue
#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
class deque
{
	T *dq;
	int front,rear,capacity;
	public:
	deque(int max)
	{
		capacity=max;
		if (capacity<1)
		{
			cout<<"Capacity must be<=1"<<endl;
			exit(0);
		}
		dq=new T[capacity];
		front=rear=-1;
	}
	bool isEmpty();
	bool isFull();
	void enqueuefromfront(T x);
	void enqueuefromrear(T x);
	T dequeuefromfront();
	T dequeuefromrear();
	T frontele();
	T rearele();
	void display();
	void enhance();
};
template<class T>
bool deque<T>:: isEmpty()
{
	if (front==-1 && rear==-1)
		return true;
	else
		return false;
}
template <class T>
bool deque<T>:: isFull()
{
	if (front==0 && rear=capacity-1)
		return true;
	else 
		return false;
}
template <class T>
void deque<T>:: enqueuefromfront(T x)
{
	if(isFull())
		cout<<"Deque is full"<<endl;
	if (front==-1)
	{
		front=rear=0;
		dq[front]=x;
		return;
	}
	if (rear!=capacity-1)
	{
		for (int i=rear;i>=front;i--)
			dq[i+1]=dq[i];
		dq[front]=x;
		rear++;
	}
	else
	{
		rear--
		dq[front]=x;
	}
}
template <class T>
T deque<T>:: dequeuefromfront()
{
       if (front==-1)
       {
	       cout<<"Deque is empty"<<endl;
       }
       T x=dq[front];
       if(front==rear)
	       front=rear=-1;
       else
	       front++;
       return x;
}
template <class T>
T deque<T>:: dequeuefromrear()
{
       if (isEmpty())
                cout<<"Deque is empty"<<endl;        
       T x=dq[rear];
       rear--;
       if(rear ==-1)
	       front=-1;
       return x;
}
template <class T>
void deque<T>:: enqueuefromrear(T x)
{
        if(isFull())
                cout<<"Deque is full"<<endl;
	if (front==-1)
	{
		front=rear=0;
		dq[rear]=x;
		return;
	}
	if(rear==capacity-1)
	{
		for(int i=front;i<=rear;i++)
			dq[i-1]=dq[i];
		front--;
		dq[rear]=x;

	}
	else
	{
		rear++;
		dq[rear]=x;
	}
}
template<class T>
void deque<T>:: enhance()
{
	T *temp;
	temp=new T[2*capacity];
	for (int i=1;front!=rear;i++)
	{
		front=(front+1)%capacity;
		temp[i]=dq[front];
	}
	delete []dq;
	dq=temp;
	front=0;
	rear=capacity-1;
	capacity=2*capacity;
}
template<class T>
void deque<T>:: display()
{
	if(isEmpty())
		cout<<"Circular Queue is Empty\n";
	else
	{
			cout<<"Elements in double queue are:"<<endl;
			for(int i=front;i<=rear;i++)
				cout<<dq[i]<<" ";
			cout<<endl;
	}
}
template<class T>
T deque<T>:: frontele()
{
	if (isEmpty())
		cout<<"Queue is Empty"<<endl;
	else
		return dq[front];
}
template<class T>
T deque<T>:: rearele()
{
	if (isEmpty())
		cout<<"Queue is empty"<<endl;
	else
		return dq[rear];
}
int main()
{
	deque<int> c1(3);
	int c,d,x;
	cout<<"\nDOUBLE QUEUE\n==========\nMENU\n1.Enqueue from front\n2.Enqueue from Rear\n2.Dequeue\n3.Display\n4.Front element\n5.Rear element\n"<<endl;
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

