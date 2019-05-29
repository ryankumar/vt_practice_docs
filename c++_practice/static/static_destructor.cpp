//: C10:StaticDestructors.cpp 
//// Static object destructors 
// output will be stored at "statdest.out" file
// if "static object" is used then destructor will call when main() will exit and the call of destructor in stack sequence i.e; last in first out manner

// if object is non-static,then destructor will call just immediatly after object destroy.

#include <fstream> 
#include <iostream> 
using namespace std; 
ofstream out("statdest.out"); // Trace file 
class Obj { 
	char c; // Identifier 
	public: 
	Obj(char cc) : c(cc) { 
		out << "Obj::Obj() for " << c << endl; 
	} 
	~Obj() { 
		out << "Obj::~Obj() for " << c << endl; 
	} 
}; 
Obj a('a'); // Global (static storage) 
	    // Constructor & destructor always called 
void f() { 
	static Obj b('b'); 
}

void g() { 
	  static Obj c('c'); 
} 
int main() { 
	out << "inside main()" << endl; 
	f(); // Calls static constructor for b 
	 g(); //not called 
	out << "leaving main()" << endl; 
}  
