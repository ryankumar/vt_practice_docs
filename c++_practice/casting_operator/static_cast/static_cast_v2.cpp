// static_cast makes tight type checking. this is normal example of static_cast,
// and type casting is not possible here from char* to int* i.e from lower to higher
//  int* p = static_cast<int*>(&c); here you will get compilation error.

#include<iostream>
using namespace std;
int main()
{ 
	char c ; 
 

	// pass at compile time, may fail at run time 
	int* q = (int *) &c;//Pass at compile time but Fail at run time(that's why it is dangarious)  
       *q=100;	
	int* p = static_cast<int*>(&c);  //so using Static_cast will fail at run time only if type casting is not possible.
	cout<<"*q= "<<*q<<endl; 
	
	return 0; 
}
