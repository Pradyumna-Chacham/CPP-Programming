//Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
class CLL;
template <class T>
class Node
{
    T data;
    Node<T> * next;
    friend class CLL<T>;
};
template <class T>
class CLL
{
     Node<T> *header;     
    public:
        CLL()
        {
            header=new Node<T>;
	    header->next=header;
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
        ~CLL();
};
template <class T>
void CLL<T>:: insertatbeg(T x)
{
    Node<T> *nn=new Node<T>;
    nn->data=x;
    nn->next=NULL;
    if(header->next==header)     //Empty list
    {
        nn->next=header;
	header->next=nn;
    }
    else
    {
        nn->next=header->next;
        header->next=nn;
    }
}
template <class T>
void CLL<T>::insertatend(T x)
{
    Node<T> *nn=new Node<T>;
    nn->data=x;
    nn->next=NULL;
    Node<T> *cur=header->next;
    if(header->next==header)
    {
        nn->next=header->next;
	header->next=nn;
    }
    else
    {
        while(cur->next!=header)
            cur=cur->next;
        nn->next=header;
	cur->next=nn;
    }
}
template <class T>
void CLL<T>:: insertatpos(T x,int pos)
{
    Node<T> *nn=new Node<T>;
    nn->data=x;
    nn->next=NULL;
    Node<T> *cur=header->next;
    if(pos==1)  //First node
    {
        nn->next=header->next;
        header->next=nn;
    }
    else
    {
        int i;
        for(i=1;i<pos-1 &&(cur->next!=header);i++)
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
void CLL<T>::display()
{
    if(header->next==header)
    {
        cout<<"empty list"<<endl;
    }
    else
    {
        Node<T> *cur=header->next;
        while(cur!=header)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
}
template <class T>
T CLL<T>:: delfrombeg()
{
    if(header->next!=header)
    {
        Node<T> *cur=header->next;
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
T CLL<T>:: delfromend()
{
    Node<T> *cur=header->next;
    T x;
    if(header->next!=header)
    {
        Node<T> *prev;
        
        while(cur->next!=header)
        {
            prev=cur;
            cur=cur->next;
        }
	prev->next=header;
    }
    else
    {
        cout<<"EMpty list,cannot delete"<<endl;
    	return 0;
    }
    x=cur->data;
    delete cur;
    return x;
}
template <class T>
T CLL<T>:: delfrompos(int pos)
{
    T x;
    if(header->next!=header)
    {
        Node<T> *cur,*prev;
        if(pos==1)
        {
            cur=header->next;
            header->next=cur->next;
	}
        else
        {
            int i=1;
            for(cur=header->next;i<pos&&(cur!=header);cur=cur->next,i++)
            {
                prev=cur;
            }
            if(cur!=header)
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
CLL<T>:: ~CLL()
{
	for(Node<T> *cur=header;cur->next!=header;cur=cur->next)
	{
		header=header->next;
		delete cur;
		cur=header;
	}
}
template <class T>
void CLL<T>::sort()
{
	int flag=0,i;
	Node<T> *cur;
	Node<T> *prev=header;
	if(header->next==header)
	{
		return;
	}
	do
	{
		flag=0;
		cur=header->next;
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
	return;
}
template <class T>
T CLL<T>:: find(int pos)
{
	T x;
	Node<T> *cur=header->next;
	if(cur!=header)
	{
		if(pos==1)
		{
			x=header->next->data;
			return x;
		}
		else
		{
			int i;
			Node<T> *cur=header->next;
			for(i=1;i<=pos&&(cur!=header);cur=cur->next,i++)
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
	if(cur==header)
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
int CLL<T>:: search (T x)
{
	int c=0;
	Node<T> *cur=header->next;
	while(cur!=header)
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
int CLL<T>::count()
{
	int c=0;
	if(header->next!=header)
	{
		for(Node<T> *cur=header->next;cur!=header;cur=cur->next)
			c++;
	}
	return c;
}
template <class T>
void CLL<T>::reverse()
{
	if(header->next!=header)
	{
		Node<T> *prev=header,*cur=header->next;
		while(cur!=header)
		{
			Node<T> *p=prev;
			prev=cur;
			cur=cur->next;
			prev->next=p;
		}
		header->next=prev;
	}
}
int main()
{
	CLL<int> a;
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
