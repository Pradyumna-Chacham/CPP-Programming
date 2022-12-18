//Stack ADT
#include<iostream>
#include<string.h>
#include<cctype>
#include<math.h>
using namespace std;
template<class T>
class stack
{
	T *s;
	int top;
	int cap;
	public:
		stack(int size);
		void display();
		void push(T ele);
		T pop();
		T topele();
		void enhance();
		bool isEmpty();
		bool isFull();
};
template<class T>
stack<T>:: stack(int size)
{
	cap=size;
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
	if (isFull())
		enhance();
	top++;
	s[top]=ele;

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
	if (top==cap-1)
		return true;
	else
		return false;
}
//converting infix to postfix
int priority(char s)
{
	if (s=='^')
		return 3;
	else if (s=='/' || s=='%' || s=='*')
		return 2;
	else if (s=='+' || s=='-')
		return 1;
	else
		return -1;
}
char* convert(char * a)
{
	int x,j=0;
	stack<char> st(20);
	int len=strlen(a);
	char *b=new char[len];
	for(int i=0;i<len;i++)
	{
		char ch=a[i];
		if ( isalnum(ch) )
		{
	              b[j++]=ch;	
		}
		else if (ch==')')	//Sending opening brackets to stack
		{
			st.push(ch);
		}
		else if (ch=='(')	//Closing brackets and sending all previous operators to output
		{
			while(st.topele()!=')')
			{
				b[j++]=st.pop();
			}
			st.pop();
		}
		else	//Checking for operator precedence
		{
			while(priority(ch)<priority(st.topele()))
			{
				b[j++]=st.pop();
			}	
			st.push(ch);
		}
	}
	//Send all remaining elements to output
	while(st.isEmpty()==false)
	{
		b[j++]=st.pop();
	}
	b[j]='\0';
	return b;
}
char* reverse( char*p)
{
	int len=strlen(p);
	char t;
	for (int i=0;i<len/2;i++)
	{
		t=p[i];
		p[i]=p[len-i-1];
		p[len-i-1]=t;
	}
	return p;
}		
int main()
{
	char s[20],prefix[20];
	cout<<"Enter an infix expression:"<<endl;
	cin>>s;
	//Reversing infix expression
	strcpy(s,reverse(s));
	strcpy(prefix,convert(s));// converting infix to postfix
	strcpy(prefix,reverse(prefix)); //assigning to prefix
	cout<<prefix<<endl;
	return 0;
}
