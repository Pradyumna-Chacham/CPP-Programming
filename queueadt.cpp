//Queue ADT
#include<iostream>
#include<stdlib.h>
#include<climits>
using namespace std;
template <class T>
class queue
{
    T  *q;
    int front,rear,capacity;
    public:
    queue(int size);
    bool isEmpty();
    bool isFull();
    void enqueue(T x);
    T dequeue();
    T frontele();
    T backele();
    void display();
    void enhance();
};
template <class T>
queue<T>:: queue(int size)
{
        capacity=size;
        if (capacity<1)
        {
            cout<<"Capacity should be greater than 1"<<endl;
            exit(0);
        }
        q=new T[capacity];
        front=rear=-1;
}
template <class T>
bool queue<T>:: isEmpty()
{
    if (front==-1 && rear==-1)
        return true;
    else
        return false;
}
template<class T>
bool queue<T>::isFull()
{
    if (front==0 && rear==capacity-1)
        return true;
    else 
        return false;
}
template <class T>
void queue<T>:: enqueue(T x)
{
    if (isFull())
        enhance();
    q[++rear]=x;
    if (front==-1)
        front=0;
}
template<class T>
T queue<T>:: dequeue()
{
    if (isEmpty())
        cout<<"Queue is Empty"<<endl;
    T y=q[front];
    q[front]= INT_MIN;
    for (int i=front+1;i<=rear;i++)
        q[i-1]=q[i];
    rear--;
    return y;
}
template <class T>
void queue<T>:: enhance()
{
    T * temp;
    temp= new T[2*capacity];
    for (int i=front;i<=rear;i++)
        temp[i]=q[i];
    delete []q;
    q=temp;
    capacity=2*capacity;
}
template <class T>
T queue<T>:: frontele()
{
    if (isEmpty())
        cout<<"Array is Empty"<<endl;
    else 
        return q[front];
}
template <class T>
T queue<T>:: backele()
{
    if (isEmpty())
        cout<<"Queue is empty"<<endl;
    else
        return q[rear];
}
template <class T>
void queue<T>:: display()
{
    cout<<"Queue Underflow:"<<endl;
    for (int i=front;i<=rear;i++)
        cout<<q[i]<<" ";
    cout<<endl;
}
int main()
{
    queue<int> c1(2);
    int c,d,del;
    cout<<"MENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Front element\n5.Back element\n";
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
            case 2: del=c1.dequeue();
                    cout<<"Deleted element is:"<<del<<endl;
                    break;
            case 3: c1.display();
                    break;
            case 4: cout<<"Front element of queue is: "<<c1.frontele()<<endl;
                    break;
            case 5: cout<<"Rear element of queue is: "<<c1.backele()<<endl;
                    break;
            default: exit(1);
        }
    }
    return 0;
}
