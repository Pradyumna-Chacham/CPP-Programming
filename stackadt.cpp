//Stack ADT
#include<iostream>
using namespace std;
template<class T>
class stack
{
	T *s;
	int top;
	int cap;
	public:
		stack();
		void display();
		void push(T ele);
		T pop();
		T topele();
		void enhance();
		bool isEmpty();
		bool isFull();
};
template<class T>
stack<T>:: stack()
{
	cout<<"Enter size of array:";
	cin>>cap;
	s=new T[cap];
	top=-1;
}
template<class T>
void stack<T>:: display()
{
	if (top==-1)
		cout<<"Stack is empty"<<endl;
	else
	{	
		cout<<"Stack elements are:"<<endl;
		for(int i=top;i>=0;i--)
		{
			cout<<s[i]<<endl;
		}
	}
}
template<class T>
void stack<T>:: push(T ele)
{
	if (isEmpty())
		enhance();
	top++;
	s[top]=ele;
	cout<<"Element inserted successfully"<<endl;
}
template<class T>
T stack<T>:: pop()
{
	if (isEmpty())
		return -1;
	else
	{
		T temp;
		temp=s[top];
		top--;	
		return temp;
	}
}
template<class T>
T stack<T>::topele()
{
	return s[top];
}
template<class T>
void stack<T>:: enhance()
{
	T *temp;
	temp=new T[2*cap];
	for (int i=0;i<top;i++)
	{
		temp[i]=s[i];
	}
	delete []s;
	cap=2*cap;
	s=temp;
}
template<class T>
bool stack<T>:: isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}
template<class T>
bool stack<T>:: isFull()
{
	if (top==cap=-1)
		return true;
	else
		return false;
}
int main()
{
	stack<int> s1;
	int elt,x,top;
	int d;
	cout<<"\nMENU:\n1.Push\n2.Pop\n3.Display Topmost element of the stack\n4. Display stack elements"<<endl;
	while(1)
	{
		cout<<"Enter your choice:";
		cin>>x;
		switch(x)
		{
			case 1: cout<<"Enter an element:";
				cin>>elt;
				s1.push(elt);
				break;
			case 2: d=s1.pop();
				cout<<"Deleted element:"<<d<<endl;
				break;
			case 3: top=s1.topele();
				cout<<"Top element of stack:"<<top<<endl;
				break;
			case 4: s1.display();
				break;
			default: exit(1);
		}
	}
	return 0;
}
