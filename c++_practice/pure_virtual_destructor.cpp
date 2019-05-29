
#include <iostream> 
using namespace std;
class Base 
{ 
	public: 
		virtual ~Base()=0; // Pure virtual destructor 
		virtual void Area()=0;

}; 

Base:: ~Base()
{
	cout<<"\npure virtual destructor\n";
}

class circle : public Base 
{ 
	public: 
		void Area() 
		{ 
			std::cout << "Area() is executed"; 
		} 
		
		~circle()
		{
			cout<<"Destroctr cirlce\n";
		}

		
}; 

int main() 
{ 
	Base *b=new circle(); 
	b->Area();
	delete b; 
	return 0; 
}

