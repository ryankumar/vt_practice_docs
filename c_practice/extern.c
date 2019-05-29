#include<stdio.h>
int x=10;
void fun();
int main()
{
	x=x+1;
	printf("x in main %d \n",x);
	fun();
	printf("x in main %d \n",x);
}
/*
void fun()
{
	x=x+1;
	printf("x in fun %d \n",x);
}
*/
