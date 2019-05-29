#include<stdio.h>
int main()
{
	int n,p;
	int i=0,j=0;
	printf("enter row and column size\n");
	scanf("%d%d",&n,&p);
	int arr[n][p];
	printf("enter elements\n");

	for(j=0;j<p;j++)
	{
		if(j==p-1)
		{
			j=0;
			i++;
		}
		
		if(i==n)
			break;
		scanf("%d",&arr[i][j]);

	}


	for(j=0;j<p;j++)
	{
		if(i==n
				+)
			break;
		printf("%d\n",arr[i][j]);
		if(j==(p-1))
		{
			j=-1;
			i++;
		}
	}
}
