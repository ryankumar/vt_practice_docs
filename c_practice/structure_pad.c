#include<stdio.h>
struct name
{
	short int a;
//       char c;
//       char d;
	int b;
}var[3];

int main()
{
	printf("size of structure :%lu\n",sizeof(var));
}
