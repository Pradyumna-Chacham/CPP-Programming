//DLL
#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
class DLL;
template <class T>
class Node
{
	T data;
	Node<T> *next,*prev;
	friend class DLL<T>;
	public:
		Node( T x)
		{
			data=x;
			prev=next=NULL;
		}
};
template <class T>
class DLL
{
	int ls;
	Node<T> *first,*last;
	public:
	DLL()
	{
		first=last=NULL;
		ls=0;
	}
	bool isempty()
	{
		if(first==NULL && last==NULL)
			return true;
		else;
			return false;
	}
	int count()
	{
		return ls;
	}
	void insertatbeg(T x);
	void insertatend(T x);
	void insertatpos(T x, int pos);
	void display();
	T delfrombeg();
	T delfromend();
	T delfrompos(int pos);
	int search(T ele);
};
template<class T>
void DLL<T>:: insertatbeg(T x)
{
	Node<T> *nn=new Node<T>(x);
	if(isempty())
	{
		first=last=nn;
	}
	else
	{
		nn->next=first;
		first->prev=nn;
		first=nn;
	}
	ls++;
}
template<class T>
void DLL<T>::insertatend(T x)
{
	Node<T> *nn=new Node<T>(x);
	if(isempty())
	{
		first=last=nn;
	}
	else
	{
		last->next=nn;
		nn->prev=last;
		last=nn;
	}
	ls++;
}
template<class T>
void DLL<T>::insertatpos(T x,int pos)
{
	Node<T> *nn=new Node<T>(x);
	if(pos<1 || pos>ls+1)
	{
		cout<<"Invalid position,can't insert"<<endl;
		return;
	}
	else
	{
		if(pos<=ls/2)	//Element in left half of list
		{
			if(pos==1)	//First element
			{
				nn->next=first;
				first->prev=nn;
				first=nn;
				ls++;
				return;
			}
			Node<T> *cur=first;
			for(int i=1;i<pos-1;i++)
				cur=cur->next;
			//Inserting node
			nn->next=cur->next;
			cur->next->prev=nn;
			cur->next=nn;
			ls++;
			return;
		}
		else		//Element in right half of list
		{
			if(pos==ls+1)	//last element
			{
				last->next=nn;
				nn->prev=last;
				last=nn;
				ls++;
				return;
			}
			Node<T> *cur=last;
			for (int i=ls;i>=pos;i--)
				cur=cur->prev;
			//Inserting node
			nn->next=cur->next;
			cur->next->prev=nn;
			nn->prev=cur;
			cur->next=nn;
			ls++;
			return;
		}
	}
}
template<class T>
void DLL<T>:: display()
{
	Node<T> *cur=first;
	while(cur!=NULL)
	{
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout<<endl;
}
template <class T>
int DLL<T>:: search(T ele)
{
	if(isempty())
	{
		cout<<"Empty list"<<endl;
		return 0;
	}
	Node<T> *cur=first;
	int i=1;
	while(cur!=NULL)
	{
		if(cur->data==ele)
			break;
		cur=cur->next;
		i++;
	}
	if(i>ls)	//if (cur==NUL)
		return -1;
	else
		return i;
}
template <class T>
T DLL<T>::delfrombeg()
{
	if(isempty())
	{
		cout<<"Empty list,can't delete"<<endl;
		return 0;
	}
	Node<T> *cur=first;
	if(first==last)
	{
		first=last=NULL;
	}
	else
	{
		first=first->next;
		first->prev=NULL;
	}
	T x=cur->data;
	delete cur;
	ls--;
	return x;
}
template<class T>
T DLL<T>:: delfromend()
{
	if(isempty())
	{
		cout<<"Empty list"<<endl;
		return 0;
	}
	Node<T> *cur=last;
	if(first==last)	//only one element
		first=last=NULL;
	else
	{
		last=last->prev;
		last->next=NULL;
	}
	T x=cur->data;
	delete cur;
	ls--;
	return x;
}
template<class T>
T DLL<T>::delfrompos(int pos)
{
	if(pos<1 ||pos>ls)
	{
		cout<<"Invalid position"<<endl;
		return 0;
	}
	else
	{
		Node<T> *cur;
		if(pos<=int(ls/2))
		{
			if(pos==1)
			{
				cur=first;
				first=first->next;
				first->prev=NULL;
				if(first==NULL)
					last=NULL;
			}
			else
			{
				Node<T> *p=NULL;
				cur=first;
				for(int i=1;i<pos;i++)
				{
					p=cur;
					cur=cur->next;
				}
				p->next=cur->next;
				cur->next->prev=p;
			}
			T x=cur->data;
			delete cur;
			ls--;
			return x;
		}
		else
		{
			Node<T> *cur,*p;
			if(pos==ls)	//Last element
			{
				cur=last;
				last=last->prev;
				last->next=NULL;
			}
			else
			{
				p=NULL;
				cur=last;
				for(int i=ls;i>pos;i--)
				{
					p=cur;
					cur=cur->prev;
				}
				p->prev=cur->prev;
				cur->prev->next=p;
			}
			T x=cur->data;
			delete cur;
			ls--;
			return x;
		}
	}
}
int main()
{
	DLL<int> a;
	int c,x,p;
	cout<<"MENU\n1.Insert an element at beginning\n2.Insert an element at a position\n3.Insert an element at the end\n4.Delete an element from the beginning\n5.Delete an element from the end\n6. Delete an element from a position\n7.Count the no.of elements in the DLL\n8.Display the elements of the linked list\n9.Find the position of an element in the list\n";
	while(1)
	{
		cout<<"Enter your choice:";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"Enter an element:";
				cin>>x;
				a.insertatbeg(x);
				break;
			case 2: cout<<"Enter an element:";
				cin>>x;
				cout<<"\nEnter the position of the element:";
				cin>>p;
				a.insertatpos(x,p);
				break;
			case 3: cout<<"Enter an element:";
			        cin>>x;
			        a.insertatend(x);
			        break;
			case 4: cout<<"Deleted element is:"<<a.delfrombeg()<<endl;
			        break;
			case 5: cout<<"Deleted element is:"<<a.delfromend()<<endl;
				break;
			case 6: cout<<"Enter a position:";
				cin>>p;
				cout<<"\nDeleted element from position "<<p<<"is:"<<a.delfrompos(p)<<endl;
				break;
			case 7: cout<<"The no.of elements in the list are:"<<a.count()<<endl;
				break;
			case 8: cout<<"The linked list elements are:"<<endl;
				a.display();
				break;
			case 9: cout<<"Enter an element:";
				cin>>x;
				cout<<"The position of the element "<<x<<" in the linked list is: "<<a.search(x)<<endl;
				break;
			default: exit(1);
				 break;
		}
	}
	return 0;
}
