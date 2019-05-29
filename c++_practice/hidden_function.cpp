#include<iostream>
using namespace std;
 class base
{
	public:
		virtual void fun(int i)
		{
			cout<<"base"<<endl;
		}
};

class derived: public base
{
	public:
		using base::fun;
		void fun(int i,int j)
		{
			cout<<"derived"<<endl;
		}
};

int main()
{
	base b;
	derived d;//=new derived();
//	base *c=&d;
//	c->fun(2);
	d.fun(1);
	d.fun(2,3);
	
}
