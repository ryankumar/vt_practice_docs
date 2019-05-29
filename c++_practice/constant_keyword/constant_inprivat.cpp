// constant variable can be intialized  by using constructer only.
#include <iostream> 
using namespace std; 
class Fred { 
	  const int size; // or const int size=4; 
	public: 
	    Fred(int sz); 
	 const int p=3;
	      void print(); 
};

Fred::Fred(int sz) : size(sz) {} 
void Fred::print() { cout << size << endl; } 

int main() { 
	  Fred a(1), b(2), c(3); 
//	Fred a,b,c;
	    a.print(), b.print(), c.print(); 
	    
}

