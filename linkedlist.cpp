//Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
class SLL;
template <class T>
class Node
{
    T data;
    Node<T> * next;
    friend class SLL<T>;
};
template <class T>
class SLL
{
    Node<T> *first;
    public:
        SLL()
        {
            first=NULL;
        }
        void insertatbeg(T x);
        void insertatend(T x);
        void insertatpos(T x,int pos);
        T delfrombeg();
        T delfromend();
        T delfrompos(int pos);
        void display();
        T find(int pos); // Returns the element at pos
        int search (T x);     //Returns the position of an element
        void sort();
        int count();
        void reverse();
        ~SLL();
};
template <class T>
void SLL<T>:: insertatbeg(T x)
{
    Node<T> *nn=new Node<T>;
    nn->data=x;
    nn->next=NULL;
    if(first==NULL)     //Empty list
    {
        first=nn;
    }
    else
    {
        nn->next=first;
        first=nn;
    }
}
template <class T>
void SLL<T>::insertatend(T x)
{
    Node<T> *nn=new Node<T>;
    nn->data=x;
    nn->next=NULL;
    Node<T> *cur=first;
    if(first==NULL)
    {
        first=nn;
    }
    else
    {
        while(nn->next!=NULL)
            cur=cur->next;
        cur->next=nn;
    }
}
template <class T>
void SLL<T>:: insertatpos(T x,int pos)
{
    Node<T> *nn=new Node<T>;
    nn->data=x;
    nn->next=NULL;
    Node<T> *cur=first;
    if(pos==1)  //First node
    {
        nn->next=first;
        first=nn;
    }
    else
    {
        int i;
        for(i=1;i<pos-1 &&cur->next;i++)
            cur=cur->next;
        if(i==pos-1)
        {
            nn->next=cur->next;
            cur->next=nn;
        }
        else
        {
            cout<<"Invalid position,cannot insert"<<endl;
            return;
        }
    }
}
template <class T>
void SLL<T>::display()
{
    if(first==NULL)
    {
        cout<<"empty list"<<endl;
    }
    else
    {
        Node<T> *cur=first;
        while(cur!=NULL)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
}
template <class T>
T SLL<T>:: delfrombeg()
{
    if(first!=NULL)
    {
        Node<T> *cur=first;
        T x=cur->data;
        delete cur;
        return x;
    }
    else
    {
        cout<<"Chain is empty,cannot delete"<<endl;
        return 0;
    }
}
template <class T>
T SLL<T>:: delfromend()
{
    if(first!=NULL)
    {
        Node<T> *prev;
        T x;
        Node<T> *cur=first;
        while(cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        if(first->next=NULL)
        {
            first=NULL;
        }
        else
            prev->next=NULL;
        x=cur->data;
        delete cur; 
        return x;
    }
    else
    {
        cout<<"EMpty list,cannot delete"<<endl;
    	return 0;
    }
}
template <class T>
T SLL<T>:: delfrompos(int pos)
{
    if(first!=NULL)
    {
        Node<T> *cur,*prev;
        T x;
        if(pos==1)
        {
            cur=first;
            x=cur->data;
            delete cur;
            return x;
        }
        else
        {
            int i;
            for(cur=first;i<=pos&&cur!=NULL;cur=cur->next,i++)
            {
                prev=cur;
            }
            if(cur!=NULL)
                prev->next=cur->next;
            else
            {
                cout<<"Invalid position,cannot delete"<<endl;
                return 0;
            }
        }
        x=cur->data;
        delete cur;
        return x;
    }
    else
    {
	cout<<"Empty List"<<endl;
    	return 0;
    }
}
template <class T>
SLL<T>:: ~SLL()
{
	for(Node<T> *cur=first;cur=NULL;cur=cur->next)
	{
		first=first->next;
		delete cur;
		cur=first;
	}
}
template <class T>
void SLL<T>::sort()
{
	int flag=0,i;
	Node<T> *cur;
	Node<T> *prev=NULL;
	if(first==NULL)
	{
		return;
	}
	do
	{
		flag=0;
		cur=first;
		while(cur->next!=prev)
		{
			if(cur->data>cur->next->data)
			{
				T temp=cur->data;
				cur->data=cur->next->data;
				cur->next->data=temp;
				flag=1;
			}
			cur=cur->next;
		}
		prev=cur;
	}while(flag);
}
template <class T>
T SLL<T>:: find(int pos)
{
	T x;
	Node<T> *cur=first;
	if(first!=NULL)
	{
		if(pos==1)
		{
			x=first->data;
			return x;
		}
		else
		{
			int i;
			Node<T> *cur=first;
			for(i=1;i<=pos&&cur!=NULL;cur=cur->next,i++)
			{
				if(i==pos)
				{
					x=cur->data;
					return x;
				}
				else
					continue;
			}
		}
	}
	if(cur==NULL)
	{
		cout<<"Invalid position"<<endl;
	}
	else
	{
		cout<<"Empty list"<<endl;
		return -1;
	}
	return x;
}
template <class T>
int SLL<T>:: search (T x)
{
	int c=0;
	Node<T> *cur=first;
	while(cur!=NULL)
	{
		c++;
		if(cur->data==x)
			return c;
		else
			cur=cur->next;
	}
	cout<<"Element not found"<<endl;
	return 0;
}
template <class T>
int SLL<T>::count()
{
	int c=0;
	if(first==NULL)
		return c;
	else
	{
		Node<T> *cur=first;
		while(cur!=NULL)
		{
			c++;
		}
		return c;
	}
}
template <class T>
void SLL<T>::reverse()
{
	if(first!=NULL)
	{
		Node<T> *prev=NULL,*cur=first;
		while(cur!=NULL)
		{
			Node<T> *p=prev;
			prev=cur;
			cur=cur->next;
			prev->next=p;
		}
		first=prev;
	}
}
int main()
{
	SLL<int> a;
	int c;
	int ele,del,pos;
	cout<<"MENU\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete from beginning\n5.Delete from end\n6.Delete from position\n7.Display\n8.Find an element at a position\n9.Find the position of element\n10.Sorted List\n11.Count the no.of elements in the list\n12.Reverse the linked list\n";
	while(1)
	{
		cout<<"Enter your choice:";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"Enter an element:";
				cin>>ele;
				a.insertatbeg(ele);
				break;
			case 2: cout<<"Enter an element";
				cin>>ele;
				a.insertatend(ele);
				break;
			case 3: cout<<"Enter an element";
				cin>>ele;
				cout<<"Enter the position of element:";
				cin>>pos;
				a.insertatpos(ele,pos);
				break;
			case 4: cout<<"Deleted element is:"<<a.delfrombeg()<<endl;
				break;
			case 5:	cout<<"Deleted element is:"<<a.delfromend()<<endl;
			       	break;
			case 6: cout<<"Enter position of element you want to delete:";
				cin>>pos;
				cout<<"Deleted element is:"<<a.delfrompos(pos)<<endl;
				break;
			case 7: cout<<"Linked List Elements are:"<<endl;
				a.display();
				break;
			case 8: cout<<"Enter the position of the element you want to find:";
				cin>>pos;
				cout<<"Element at position"<<pos<<" is "<<a.find(pos);
				break;
			case 9: cout<<"Enter the element whose position you want to find:";
				cin>>ele;
				cout<<"The position of "<<ele<<" in linked list is:"<<a.search(ele)<<endl;
				break;
			case 10: a.sort();
				 cout<<"Sorted list is:";
				 a.display();
				 break;
			case 11: cout<<"No.of elements in the list:"<<a.count()<<endl;
				 break;
			case 12: a.reverse();
				 cout<<"List in reverse order"<<endl;
				 a.display();
				 break;
			default: exit(1);
		}
		
	}
	return 0;
}
