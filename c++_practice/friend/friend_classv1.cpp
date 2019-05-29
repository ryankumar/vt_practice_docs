#include<iostream>
using namespace std;

class A
{
	int a,b;
	public:
	A(int i,int j) {a=i;b=j;}
	int c;
	friend class B;
};

class B
{
	public: int min(A x);
};

int B::min(A x)
{
	x.c=30;
	cout<<x.c<<endl;
	return x.a < x.b ? x.a : x.b ;

}

int main()
{
	A a(3,4);
	B b;
	cout<<b.min(a)<<endl;
}

