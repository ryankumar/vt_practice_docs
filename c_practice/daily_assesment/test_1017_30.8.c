#include<stdio.h>

int main()
{
	int arr[50]={43, 65, 51, 27, 79, 11, 56, 61, 82, 9, 25, 
			36, 7, 49, 55, 63, 74, 81, 49, 37, 40, 49, 16, 75, 87, 91, 33, 24, 58, 78, 65,
			56, 76, 67, 45, 54, 36, 63, 12, 21, 73, 49, 51, 19, 39, 49, 68, 93, 85, 59};
	int rem,res;
	for(int i=0;i<50;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	for(int i=0;i<50;i++)
	{
		if(arr[i]<=80 && arr[i]>=37)
		{
		  rem=arr[i]%5;
		  if(rem!=0)
			  arr[i]=arr[i]+(5-rem);
		}

		if(arr[i]<37)
		{
		
			res=37-arr[i];
			if(res>5)
			{
				rem=arr[i]%5;
				if(rem!=0)
				arr[i]=arr[i]+(5-rem);
			}
		}
	}

   	for(int i=0;i<50;i++)
   	{
		printf("%d ",arr[i]);
   	}
	printf("\n");
}	
