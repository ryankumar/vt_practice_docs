#include<iostream>
//#include<stdio.h>
using namespace std;
class A
{
	public: 
		int a;
		static int x;
//		void show()
//		{
//			cout<<"a= "<<a<<endl;
//			cout<<"x= "<<x<<endl;
//		}
};

int A::x=1;
int main()
{
	int i=10,j=20;
	int &r=i;
	int *ptr=&i;
	cout<<"r= "<<r;
	cout<<"\n&r= "<<&r;
       cout<<"\n&i= "<<&i;	
       cout<<"\nptr= "<<ptr;
       cout<<"\n&ptr= "<<&ptr;
       r++;
       (*ptr)++;
       cout<<"\nr++= "<<r;
       cout<<"\n*ptr= "<<*ptr;
       cout<<"\ni= "<<i;
	
       r=j;
	cout<<"\n&r++= "<<r;
	cout<<"\n*ptr= "<<*ptr;
	cout<<"\ni= "<<i;
//	printf("j=%d\n",j);
}

