#include<stdio.h>
void add(int a,int b);
void sub(int a,int b);
int main()
{
	int a=7,b=3;
	printf("call to add\n");
	add(a,b);
	printf("call to sub\n");
	sub(a,b);
}
