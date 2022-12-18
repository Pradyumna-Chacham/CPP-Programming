//Polynomial ADT
#include<iostream>
#include<cmath>
using namespace std;
class polynomial;
class Term
{
	private:
		int exp;
		float coeff;
	public:
		friend class polynomial;
};
class polynomial
{
	private:
		Term *T;
		int nt;
	public:
		polynomial(int);
		polynomial add(polynomial );
		void read();
		void display();
		void eval( double);
};
polynomial:: polynomial(int n)
{
	nt=n;
	T=new Term[nt];
}
void polynomial:: read()
{
	int i;
	cout<<"Enter polynomial terms in decreasing order of degree:"<<endl;
	for(int i=0;i<nt;i++)
	{
		cin>>T[i].coeff>>T[i].exp;
	}
}
void polynomial:: display()
{
	if(nt!=0)
	{
		cout<<T[0].coeff<<"x^"<<T[0].exp;
		for(int i=1;i<nt;i++)
		{
			cout<<"+"<<T[i].coeff<<"x^"<<T[i].exp;
		}
		cout<<endl;
	}
	else
		cout<<"Polynomial is empty"<<endl;
}
void polynomial:: eval(double x)
{
	double res=0;
	cout<<"Value of the polynomial when x="<<x<<endl;
	for(int i=0;i<nt;i++)
	{
		res=res+T[i].coeff*pow(x,T[i].exp);
	}
	cout<<res<<endl;
}
polynomial polynomial:: add(polynomial P2)
{
	polynomial P3(nt+P2.nt);
	int pos1=0,pos2=0,i=0;
	while ((pos1<nt)&&(pos2<P2.nt))
	{
		if(T[pos1].exp==P2.T[pos2].exp)
		{
			float r=T[pos1].coeff+P2.T[pos2].coeff;
			if(r)
			{
				P3.T[i].coeff=r;
				P3.T[i].exp=T[pos1].exp;
			}
			i++;
			pos1++;
			pos2++;
		}
		else if (T[pos1].exp<P2.T[pos2].exp)
		{
			P3.T[i].coeff=P2.T[pos2].coeff;
			P3.T[i].exp=P2.T[pos2].exp;
			i++;
			pos2++;
		}
		else
		{
			P3.T[i].coeff=T[pos1].coeff;
			P3.T[i].exp=T[pos1].exp;
			i++;
			pos1++;
		}
	}
	while (pos1<nt)
	{
		P3.T[i].coeff=T[pos1].coeff;
		P3.T[i].exp=T[pos1].exp;
		i++;
		pos1++;
	}
	while (pos2<P2.nt)
	{
		P3.T[i].coeff=P2.T[i].coeff;
		P3.T[i].exp=P2.T[i].exp;
		i++;
		pos2++;
	}
	P3.nt=i;
	return P3;
};
int main()
{
	polynomial a(3),b(3),c(3),d(3),e(3);
	a.read();
	b.read();
	c=a.add(b);
	d=b.add(c);
	a.display();
	b.display();
	c.display();
	c.eval(2.0);
	d.display();
	d.eval(3.0);
	return 0;
}


