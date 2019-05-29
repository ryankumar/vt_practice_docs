//: C10:StaticObjectsInFunctions.cpp 
//if we initialize some value in parameterized constructor,then it will work as a defualt constructor also
//ex: X(int ii) - it is only parameterized constructor hence we have to declare another default constructor
//   X(int ii=0) -it acts both defaut constructor as well as parameterized constructor
//
#include <iostream> 
using namespace std; 
class X { 
	int i; 
	public: 
	X(int ii=5 ) : i(ii) {} // Default 
	~X() { cout << "X::~X() with i"<<i << endl; }
       void print()
       {
	cout<<i<<endl;
       }	
}; 
void f() { 
	static X x1(47); 
	 static X x2; // Default constructor required 
	x1.print();
	x2.print();
} 
int main() { 
	f(); 
} ///:~ 
