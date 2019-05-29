#include<iostream>

using namespace std;

class A{
	int i;
	public:
	A(int x) : i(x) { }
	A() {}
	friend A operator++ (A a);
	friend A operator++ (A a,int);
	friend A operator+ (A p,A q);
	friend void display (A a);	
};

A operator++ (A a)
{
	cout<< "pre-increament ++a"<<a.i<<endl;
	A temp;
	++a.i;
	return *this;
}

A operator++ (A a,int)
{
	cout<< "post-increament"<<a.i<<endl;
	A b(a.i);
	a.i++;
	return b;
}

A operator+ (A p ,A q)
{
	return A(q.i+p.i);
}

void display( A a)
{
	cout<<a.i<<endl;
}


int main()
{
	A a(5),b(10),c;
	//	++a;
	//	a.display();
	//	b++;
	//	b.display();
	c=a++ + ++b;
	display(c);
}

