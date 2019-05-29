//write c program to find a peculiar two digit number which is three times the sum of its digits.
/*
 	10x+y=3(x+y)
	7x=2y;
 */
#include<stdio.h>

int main()
{
	int x,y;

	for ( x = 1; x < 10; x++)
	{
		for (y = 1; y < 10; y++)
		{
			
			if( (7 * x ) == (2 * y))
			{
				printf("The two digit number is %d \n", ((10 * x) + y));
			}
		}
	}

	return 0;
}

