#include <iostream>
using namespace std;

class Car // Base class for C++ virtual function example
{
	public:
		virtual void Create()=0; // virtual function for C++ virtual function example
	/*	{
			cout << "Parent class: Car\n";
		}
		*/
};

class Sedan: public Car {
	public:
		void Create() {
			cout << "Derived class: Sedan - Overridden C++ virtual function";
		}
};

int main() {
	Car *x, *y;

	x = new Car();
	x->Create();

	y = new Sedan();
	y->Create();

}
