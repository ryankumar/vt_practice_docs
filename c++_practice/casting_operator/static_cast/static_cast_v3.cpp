/*
 *   When "obj" is created then constructor is called which in our case is also a      Conversion Constructor(For C++14 rules are bit changed).
 *  When you create "str" out of "obj", compiler will not thrown an error as we     have defined the Conversion operator.
 *  When you make "obj=20", you are actually calling the conversion constructor.
 *  When you make "str2 out of static_cast", it is quite similar to "string str=    obj;", but with a tight type checking.
 * When you write "obj=static_cast<Int>(30)", you are converting "30" into "Int"   using "static_cast".
 *
 *
 */
#include <iostream> 
#include <string> 
using namespace std; 
class Int { 
	int x; 

	public: 
	 Int(int x_in = 0) 
		: x{ x_in } 
	{ 
		cout << "Conversion Ctor called" << endl; 
	} 
	operator string() 
	{ 
		cout << "Conversion Operator" << endl; 
		return to_string(x); 
	} 
	void display()
	{
		cout<<"obj= "<<x<<endl;
	}
}; 
int main() 
{ 
	Int obj(3); 
	string str = obj;
       cout<<"str= "<<str<<endl;	
	obj = 20; 
	string str2 = static_cast<string>(obj); 
	cout<<"str2= "<<str2<<endl;
	obj = static_cast<Int>(30); 
	obj.display();
	return 0; 
} 

