#include <iostream>
using namespace std;

class A
{
	public:
		void display()
		{
			cout<<"Base class content.";
		}
};

class B : public A
{
	public:
	void display()
	{
		cout<<"derive class";
	}
};

class C : public B
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
	obj.display();
//	obj.displa();
		    return 0;
}
