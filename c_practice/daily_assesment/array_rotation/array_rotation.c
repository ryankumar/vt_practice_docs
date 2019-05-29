#include<stdio.h>
#include<stdlib.h>
#include <array_rotation.h>
//void print_array(int *arr,int size);
//void left_rotation(int *arr,int size,int rotation);

int main()
{
	int size,norotation;
	printf("enter the size of array\n");
	scanf("%d",&size);
	if(size>0)
	{
	int arr[size];
	printf("enter the %d elements for the array of given size :\n",size);
	for(int i=0;i<size;i++)
		scanf("%d",&arr[i]);

	printf("enter the number of rotation\n");
	scanf("%d",&norotation);

	printf("before rotation of array is\n");
	print_array(arr,size);

	left_rotation(arr,size,norotation);
	printf("after rotaion array is \n");
	print_array(arr,size);
	}
	else
		printf("array size must be greater than zero\n");
	
	return 0;
}

/*
void print_array(int *arr,int size)
{
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}


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

*/
