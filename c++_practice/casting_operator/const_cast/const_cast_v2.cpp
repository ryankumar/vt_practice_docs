#include<iostream>
using namespace std;
/* 1. by using constant variable
   int main()
   {
   const int a=30; //a=30
   const int *b=&a; //*b=30
   int *c= const_cast<int*>(b); // *c=30 ; removes constant	

 *c=15;
 cout<<"*c= "<<*c<<endl; // *c=15;
 cout<<"a= "<<a<<endl; //a=30;
 cout<<"*b= "<<*b<<endl;// *b=15;
 }
 */

//2.without constant variable
  int main()
  {
  int a=30; //a=30
  const int *b=&a; //*b=30
  int *c= const_cast<int*>(b); // *c=30 ; removes constant        

 *c=15;
 cout<<"*c= "<<*c<<endl; // *c=15;
 cout<<"a= "<<a<<endl; //a=15;
 cout<<"*b= "<<*b<<endl;// *b=15;
 }
 

