#include<stdio.h>
#include <array_rotation.h>
void left_rotation(int *arr,int size,int rotation)
{
	int temp;
	int i,j;
	int total_rotation=(rotation % size);
	for(i=0;i<total_rotation;i++)
	{
		temp=arr[0];
		for(j=0;j<size-1;j++)
			arr[j]=arr[j+1];
		arr[j]=temp;
	}
}

