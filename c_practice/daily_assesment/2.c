#include<stdio.h>
#include<stdlib.h>

int scount , lcount;


int find_small(int size ,int *arr)
{
	int i=0;
	int small=arr[0];
	for(i=1;i<size;i++)
	{
		if(arr[i]<small)
		{
			small=arr[i];
		}


	}
	for(i=0;i<size;i++)
	{
		if(arr[i]==small)
			scount++;
	}
	return small;
}


int find_large(int size ,int *arr)
{
	int i=0;
	int large=arr[0];
	for(i=1;i<size;i++)
	{
		if(arr[i]>large)
		{
			large=arr[i];
		}

	}
	for(i=0;i<size;i++)
	{
		if(arr[i]==large)
			lcount++;
	}
	return large;

}


void find_sum_max_min(int size,int *arr)
{
	int small,large,equal;
	long int msum=0,lsum=0;
	int i=0,j=0;
	small=find_small(size,arr);
	large=find_large(size,arr);
//	printf("small %d  large %d , lcount %d , scount %d\n",small,large,lcount,scount);
	for(i=0;i<size;i++)
	{
		if(arr[i]<large)
		{
			msum=msum+arr[i];
		}

		if(arr[i]>small)
		{
			lsum=lsum+arr[i];
		}
		
	}
	for(i=0;i<lcount-1;i++)
		msum=msum+large;
	for(i=0;i<scount-1;i++)
		lsum=lsum+small;

	printf("min sum %ld\n max sum %ld\n",msum,lsum);
	printf("total value %ld  %ld\n",msum,lsum);



}

int main()
{
	int arr[5];
	int i;
	printf("enter the array elements\n");
	for(i=0;i<5;i++)
		scanf("%d",&arr[i]);
	find_sum_max_min(5,arr);
	return 0;
}
