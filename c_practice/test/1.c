#include<stdio.h>
int add(int,int);
int sub(int,int);
int main()
{
	int a=3,b=4;
	int c;
	c=add(a,b);
	printf("add:%d\n",c);
	c=sub(b,a);
	printf("sub:%d\n",c);
	return 0;
}
