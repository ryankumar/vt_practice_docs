#include<iostream>
using namespace std;
//char c;
int main()
{
	char c,d;
	int *ptr=(int *)&d;
	*ptr=1;
	cout<<"*ptr= "<<*ptr<<endl;
}
