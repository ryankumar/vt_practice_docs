#include<iostream>
using namespace std;
class A{

	public:
		A() {cout<<"constructor A\n";}
		virtual ~A() {cout<<"destructor A\n";}

};

class B :public A
{
	public:
		
		B() {cout<<"constructor B\n";}
		~B() {cout<<"destructor B\n";}
	
};

class C :public A
{
	public:
		C() {cout<<"constructor C\n";}
		~C() {cout<<"destructor C\n";}

};

class D:public B,C
{
	public:
		
		D() {cout<<"constructor D\n";}
		~D() {cout<<"destructor D\n";}
};
int main()
{
	D obj;



}
