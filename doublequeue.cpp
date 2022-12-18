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
		front=rear=0;
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
	if(front==-1)	//Queue is empty
		dq[++front]=x;
	else if(isFull())	//Queue is full
	{
		enhance();
		for (int i=front;i<=rear;i++)
			dq[i]=dq[i-1];
		dq[front]=x;
	}
	else	//Queue has space
	{
		for (int i=front;i<=rear;i++)
                        dq[i]=dq[i-1];
                dq[front]=x;
	}
}
template <class T>
T deque<T>:: dequeuefromfront()
{
       if (isEmpty())
                return 0;
       if (isFull())
        return x;
}
template <class T>
T deque<T>:: dequeuefromrear()
{
       if (isEmpty())
                return 0;
        front=(front+1)%capacity;
        T x=dq[front];

        if (front==rear)
                front=rear=0;
        return x;
}
template <class T>
void deque<T>:: enqueuefromrear(T x)
{
        if(isFull())
                enhance();
        for (int i=front;i<=rear;i++)
                dq[i]=dq[i-1];

        cq[rear]=x;
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
			cout<<"Circular Queue elements are:"<<endl;
			for(int i=(front+1)%capacity;i!=(rear+1)%capacity;i=(i+1)%capacity)
				cout<<cq[i]<<" ";
			cout<<endl;
	}
}
template<class T>
T deque<T>:: frontele()
{
	if (isEmpty())
		cout<<"Queue is Empty"<<endl;
	else
		return cq[front+1];
}
template<class T>
T deque<T>:: rearele()
{
	if (isEmpty())
		cout<<"Queue is empty"<<endl;
	else
		return cq[rear];
}
int main()
{
	deque<int> c1(3);
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

