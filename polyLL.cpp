//Polynomials using linked list
#include<iostream>
#include<cmath>
using namespace std;
class poly;
class Node
{
	double c;
	int e;
	Node *next;
	friend poly;
};
class poly
{
	Node *first;
	public:
	poly()
	{
		first=NULL;
	}
	void append(Node *nn)
	{
		Node *cur;
		if(first==NULL)
			first=nn;
		else
		{
			cur=first;
			while(cur->next!=NULL)
				cur=cur->next;
			cur->next=nn;
		}
	}
	void create()
	{
		Node *nn;
		double coeff;
		int exp;
		cout<<"Enter the coefficient value and exponent value in decreasing order of exponent and enter coeff value 0 to terminate"<<endl;
		cin>>coeff;
		while(coeff!=0)
		{
			cin>>exp;
			nn=new Node;
			nn->c=coeff;
			nn->e=exp;
			nn->next=NULL;
			append(nn);
			cin>>coeff;
		}
	}
	double eval(double x)
	{
		double sum=0;
		Node *cur=first;
		while (cur!=NULL)
		{
			sum+=cur->c*pow(x,cur->e);
			cur=cur->next;
		}
		return sum;
	}
	void add(poly &a,poly &b)
	{
		Node *p1,*p2,*nn;
		double sum;
		p1=a.first;
		p2=b.first;
		while(p1!=NULL && p2!=NULL)
		{
			if(p1->e > p2->e)
			{
				nn=new Node;
				nn->c=p1->c;
				nn->e=p1->e;
				append(nn);
				p1=p1->next;
			}
			else if(p1->e <p2->e)
			{
				nn=new Node;
				nn->c=p2->c;
				nn->e=p2->e;
				append(nn);
				p2=p2->next;
			}
			else
			{
				sum=p1->c+p2->c;
				if(sum!=0)	//move to the nxt term in pols
				{
					nn=new Node;
					nn->c=sum;
					nn->e=p1->e;
					append(nn);
				}
				p1=p1->next;
				p2=p2->next;
			}
		}//end of while
		while(p1!=NULL)
		{
			nn=new Node;
			nn->c=p1->c;
			nn->e=p1->e;
			append(nn);
			p1=p1->next;
		}
		while(p2!=NULL)
		{
			nn=new Node;
			nn->c=p2->c;
			nn->e=p2->e;
			append(nn);
			p2=p2->next;
		}
	}
	void display()
	{
		Node *cur;
		if(first=NULL)
			cout<<"Polynomial is:"<<endl;
		cur=first;
		while(cur!=NULL)
		{
			cout<<cur->c<<"x^"<<cur->e;
			if(cur->next!=NULL)
				cout<<"+";
			cur=cur->next;
		}
		cout<<endl;
	}
	void multiply(poly &a,poly &b)
	{
		Node *p1=a.first;
		Node *p2=b.first;
		Node *nn;
		while(p1!=NULL)
		{
			poly temp,res;
			while(p2!=NULL)
			{
				nn=new Node;
				nn->c=p1->c*p2->c;
				nn->e=p1->e+p2->e;
				nn->next=NULL;
				temp.append(nn);
				p2=p2->next;
			}
			p2=b.first;
			res.add(*this,temp);
			*this=res;
			p1=p1->next;
		}
	}
};
int main()
{
	poly p1,p2,p3,p4;
	int x;
	p1.create();
	p2.create();
	p1.display();
	p2.display();
	p3.add(p1,p2);
	cout<<"Sum of two polynomials is:"<<endl;
	p3.display();
	p4.multiply(p1,p2);
	cout<<"Product of two polynomials:"<<endl;
	p4.display();
	cout<<"Enter x value for polynomial evaluation";
	cin>>x;
	cout<<"Result of first polynomial:"<<p1.eval(x)<<endl;
	cout<<"Result of second polynomial:"<<p2.eval(x)<<endl;
	return 0;
}

