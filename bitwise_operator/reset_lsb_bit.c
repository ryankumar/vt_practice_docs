#include<stdio.h>
int main()
{
	int n=0;
	printf("before reset value : %d\n",n);
	
	n=n & (n-1);
	

	printf("after reset value : %d\n",n);

}
