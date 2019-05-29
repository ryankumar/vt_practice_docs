// CPP program without virtual destructor 
// causing undefined behavior
/*
 #include<iostream>
using namespace std;
   
class base {

   	public:
         base()     
   	 { cout<<"Constructing base \n"; }
  	 ~base()
  	 { cout<<"Destructing base \n"; }     
  };
                      
 class derived: public base {
 	 public:
		 derived()     
		 { cout<<"Constructing derived \n"; }
		 ~derived()
		 { cout<<"Destructing derived \n"; }
 };                                         

int main(void)
{
//	derived d;
	base *b = new derived();
	delete b; // before destrctor called pointer b is released;hence ~base() is not called;
	return 0;
}
*/

/**************************************************************************************************
                     WITH VIRTUAL DESTRUCTOR
***************************************************************************************************/

// A program with virtual destructor

#include<iostream>
using namespace std;
class base {

 	public:
 	base()     
 	{ cout<<"Constructing base \n"; }
 
       virtual ~base()  //virtual destructor
 	{ cout<<"Destructing base \n"; }     
};

class derived: public base {
	public:
		derived()     
		{ cout<<"Constructing derived \n"; }
		~derived()
		{ cout<<"Destructing derived \n"; }
};

int main(void)
{
	base *b= new derived();  
	delete b;
	return 0;
}


/*As a guideline, any time you have a virtual function in a class, you should immediately add a virtual destructor (even if it does nothing). This way, you ensure against any surprises later.
 */
