/* The keyword mutable is mainly used to allow a particular data member of const object to be modified . when we declare a function as const, the this pointer passed to function becomes passed const . adding mutable to a variable able allows a const pointer to change members.
 * */
#include <iostream> 
#include <string.h> 
using std::cout; 
using std::endl; 

class Customer 
{ 
	char name[25]; 
	mutable char placedorder[50]; 
	mutable int tableno; 
	 mutable int bill; 
	public: 
	Customer(char* s, char* m, int a, int p) 
	{ 
		strcpy(name, s); 
		strcpy(placedorder, m); 
		tableno = a; 
		bill = p; 
	} 
	void changePlacedOrder(char* p) const
	{ 
		strcpy(placedorder, p); 
	} 
	void changeBill(int s,int t) const
	{ 

		bill = s; 
		tableno =t;
	} 
	void display() const
	{ 
		cout << "Customer name is: " << name << endl; 
		cout << "Food ordered by customer is: " << placedorder << endl; 
		cout << "table no is: " << tableno << endl; 
		cout << "Total payable amount: " << bill << endl; 
	} 
}; 

int main() 
{ 
	const Customer c1("Pravasi Meet", "Ice Cream", 3, 100); 
	c1.display(); 
	c1.changePlacedOrder("GulabJammuns"); 
	c1.changeBill(150,5); 
	c1.display(); 
	return 0; 
}

