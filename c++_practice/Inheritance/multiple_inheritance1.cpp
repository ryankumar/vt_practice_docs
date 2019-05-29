#include <iostream>
using namespace std;

class A
{
	public:
		void display( )
		{
			cout<<"Base class A content.";
		}
};

class B
{
	public:
	void display()
	{
		cout<<"Base class B";
	}
};

class C :public A, public B
{
	public:
       void display()
       {
		cout<<"deriv c class";
       }	
       
};

int main()
{
	C obj;
//	B obj1;
	obj.display();
//	obj.B::display();
//	obj.A::display();
		    return 0;
}
