#include<iostream>

using namespace std;

class A{
	int i;
	public:
	A(int x) : i(x) { }
	A() {}
	
	A operator++ ()
	{
		cout<< "pre-increament ++a"<<i<<endl;
	  i++;
	  return *this;
	}

	A operator++ (int)
	{
		cout<< "post-increament"<<i<<endl;
		A b(i);
		i++;
		return b;
	}

	A operator+ (A p)
	{
		A temp;
		temp.i=i+p.i;
		return temp;
	}

	void display( )
	{
		cout<<i<<endl;
	}
};

int main()
{
	 A a(5),b(10),c;
//	++a;
//	a.display();
//	b++;
//	b.display();
	c=a++ + ++b;
	c.display();
}

