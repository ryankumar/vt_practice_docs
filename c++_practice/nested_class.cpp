#include<iostream>
using namespace std;
class B;
class A
{
	public:
		void fun() { cout<<"hi A"<<endl;}
		A() {}
		class B
		{
			public:
			B() {
			A a;
			a.fun();
			}
			void add() 
			{
				cout<<"its internal"<<endl;
			}
		};
		
		A(int z) {

		B c;
	       c.add();
		}	       
};

int main()
{
	A::B b;
	A a(1);
	
}

