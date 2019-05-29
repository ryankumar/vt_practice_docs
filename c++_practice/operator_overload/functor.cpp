#include<iostream>
using namespace std;
class A
{
	int i;
	public:
//	A(){}
//	A(int x) : i(x){}

	int operator () (int x)
	{
		i=x;
		return i;
	}
	
};

int main()
{
	A a;
	cout<<a(3)<<endl;
	cout<<a(5)<<endl;
}


