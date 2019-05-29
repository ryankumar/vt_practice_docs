//1. you will get compile time error bcz return type will not effect to function i.e by changing return type function will not change . 
/*
#include<iostream> 
int foo() {  
	    return 10;  
} 
  
char foo() {  // compiler error; new declaration of foo() 
	    return 'a';  
} 
  
int main() 
{ 
	    int x = foo();

	   printf("x=%d\n",x); 
//	        getchar(); 
		    return 0; 
} 
*/

//2.Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration. For example, following program fails in compilation

/*
#include<iostream> 
class Test { 
	   static void fun(int i) {} 
	      void fun(int i) {}    
}; 
  
int main() 
{ 
	   Test t; 
	   
	         return 0; 
} 
*/
// 3.int *ptr == int ptr[];hence function overloading happened . 
#include<iostream>
class Test {
	int fun(int *ptr); 
	int fun(int ptr[]);
};

int main()
{
	Test t;
	return 0;
}
