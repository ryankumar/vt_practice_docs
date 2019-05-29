
#include<iostream> 
using namespace std; 

class Test 
{ 
	protected: 
		int x; 
	public: 
		Test (int i):x(i) { } 
		void fun() const
		{ 
			cout << "fun() const called " << endl; 
		} 
		void fun() 
		{ 
			cout << "fun() called " << endl; 
		} 

		void display()
		{
			cout <<" x="<<x <<endl;
		}

		void display() const
		{
			cout << "const x="<<x<<endl;
		}
}; 

int main() 
{ 
	Test t1 (10); 
	const Test t2 (20); 
	t1.fun(); 
	t2.fun(); 
	t2.display();
	t1.display();
	return 0; 
} 

