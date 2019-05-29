#include <iostream>
using namespace std;
template <typename T1, typename T2>
T1 addition(T1 num1, T2 num2)
{
	return num1 + num2;
}


int main ()
{
	cout<<"Addition of Integer Numbers : "<<addition(10,20)<<endl;
	cout<<"Addition of Float Numbers : "<<addition(10.5,15)<<endl;
	cout<<"Addition of Characters : "<<addition('C',5)<<endl;
	return 0;
}
