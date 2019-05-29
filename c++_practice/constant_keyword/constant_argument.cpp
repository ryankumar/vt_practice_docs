//1. 1st programme will give a compilation error bcz of function overloading with constant variable passing or without constant variable passing as argument.
/*
#include<iostream> 
using namespace std; 

void fun(const int i) 
{ 
cout << "fun(const int) called "; 
} 
void fun(int i) 
{ 
cout << "fun(int ) called " ; 
} 
int main() 
{ 
const int i = 10; 
fun(i); 
return 0; 
} 
*/

// 2. this one also same as above but here we are passing address of that variable which is not constant and we will get proper output .
// we will get output according to pasing argument is const/without const respectively .

#include<iostream>
using namespace std;

void fun(const int *i)
{
	cout << "fun(const int*) called "<<*i<<endl;
}
void fun(int *i)
{
	cout << "fun(int *) called "<<*i<<endl ;

}
int main()
{
	const int i = 10;   
	fun(&i);
	return 0;
}


//3 . this is the other way we can represent by using copy operator(&).
/*
#include<iostream> 
using namespace std; 
  
void fun(const int &i) 
{ 
	    cout << "fun(const int &) called "; 
} 
void fun(int &i) 
{ 
	    cout << "fun(int &) called " ; 
} 
int main() 
{ 
	     const int i = 10; 
	        fun(i); 
		    return 0; 
} 
*/
