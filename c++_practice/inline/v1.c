#include<stdio.h>
//#include<iostream>
//using namespace std;
inline int add(int a,int b)
{
	int n=0;
	if(a==0 || b==0)
	return (a>b ?a:b);
	n=n+add(--a,--b);
	return n;
	
}
int main()
{
//	cout<<"inline v1 "<<add(4,5);
	printf("add %d\n",add(4,5));
}
