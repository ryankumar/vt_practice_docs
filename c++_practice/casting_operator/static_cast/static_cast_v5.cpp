//use for all upcasts,but never use for confused downcast

#include<iostream>
using namespace std;
class base {};
class derived1:public base{};
class derived2:public base{};

int main()
{
	derived1 d1;
	derived2 d2;
	base *bp1=static_cast<base*>(&d2); // can be use for upcast
	base *bp2=static_cast<base*>(&d2); // can be use for upcast

	derived1 *d1p=static_cast<derived1*>(bp2); // don't use for down_cast
	derived2 *d2p=static_cast<derived2*>(bp1); // don't use for down_cast
	return 0;
}
