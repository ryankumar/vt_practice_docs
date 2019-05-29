/* type casting object to and from a class */
//here derived class is public base, hence type casting can be possible
/*
#include <iostream> 
using namespace std; 
class Base { 
}; 
class Derived : public Base { 
}; 
int main() 
{ 
	    Derived d1; 
	        Base* b1 = (Base*)(&d1); // allowed 
		    Base* b2 = static_cast<Base*>(&d1); 
		      
		        return 0; 
}
*/

// The below code will not compile even if you inherit as protected. So to use     static_cast, inherit it as public. 
// [Error] 'Base' is an inaccessible base of 'Derived'
#include <iostream> 
using namespace std; 
class Base { 
}; 
class Derived : private Base { 
}; 
int main() 
{ 
	    Derived d1; 
	    Base* b1 = (Base*)(&d1); // allowed 
	    Base* b2 = static_cast<Base*>(&d1); 
	    return 0; 

} 

