// static_cast makes tight type checking. this is normal example of static_cast
#include<iostream>
using namespace std;
int main()
{
	float f=3.34;
	int a=f;
	int b=static_cast<int> (f);
	cout<<"a= "<<a<<endl;
	cout<<"b= "<<b<<endl;
}
