#include<stdio.h>
extern int x;
int fun()
{
	printf("inside the using_extern file x=%d \n",x);
	x=x+1;
}

