#include<stdio.h>

struct A
{
	long double d;
	char c;
	int l;
};

int main()
{
	struct A a;
	long double k;
	printf("%lu\n",sizeof(a));
	printf("%lu\n",sizeof(k));
}
