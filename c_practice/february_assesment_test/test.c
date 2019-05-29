#include<stdio.h>
void find_pairs(int,int,int);
int size;
int buff[100][100];
int arr[100];
int main()
{
	int sum=0;
	int i,j,total=0;
	int count=0;
	unsigned int hash[123456]={0};

	printf("enter the size of array: ");
	scanf("%d",&size);
	printf("\nenter the elements for given array: ");

	for(int i=0;i<size;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			buff[i][j]=arr[i]+arr[j];
			if(hash[buff[i][j]]==0)
				hash[buff[i][j]]=1;

			else
				hash[buff[i][j]]+=1;
		}
	}




	//find pairs
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			sum=buff[i][j];

			if(hash[buff[i][j]]!=0){
				total=hash[buff[i][j]]/2;
				if(total>0)
				{

					find_pairs(sum,i,j);
					count++;

				}
			}
			hash[buff[i][j]]=0;
			total=0;

		}
	}

	if(count==0)
	printf("no pairs found\n");	



}


void find_pairs(int sum,int a,int b)
{
	int count=0;
	int i,j;
	for(i=a;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(buff[i][j]==sum)
			{
				if(count>1 && count%2==0)
				{
					sum=buff[i][j];
					a=i;b=j;
				}
				count+=1;
				if(count%2==0)
					printf("pairs are (%d,%d) and (%d,%d) for sum=%d\n ",arr[a],arr[b],arr[i],arr[j],sum);

			}
		}
	}
	
}
