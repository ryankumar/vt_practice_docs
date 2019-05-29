#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int r,c,tr,tc,Rr=0,Rc=0,total;
	int i,j,k,l,m,n,sum=0,sum1=0;
	int rem1,rem2,rem3,rem4;
	
	FILE *ret =freopen("/home/mahannee/empid-1017/c_practice/agust_assesment/test.txt", "r" ,stdin);
	if(ret==NULL)
	{
		printf("freopn() is failed \n");
		exit(1);
	}
	
	// entering number of rows and column
	scanf("%d%d",&m,&n);
	r=m;
	c=n;
	tr= r%3;
	tc= c%3;
	
	if(tr!=0)
	{
		Rr=(3-tr);
		r +=Rr;
	}

	if(tc!=0)
	{
		Rc=3-tc;
		c +=Rc;
	}	

	int **ptr=(int **) malloc(r * sizeof(int *));
	for(i=0;i<r;i++)
		ptr[i]=(int *) malloc(c * sizeof(int));
	
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			ptr[i][j]=1;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		 	scanf("%d",&ptr[i][j]);
		}
	}	
	
	printf("\n******************* ENTERED MATRIX ***************************\n");
		
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%4d",ptr[i][j]);
		}
		printf("\n");
	}

	printf("\n************ matrices in 3*3 format *****************\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t", ptr[i][j]);
			
			if((j+1)%3==0 && (j+1)<c)
				printf("\t\t");
		}
		
		if((i+1)%3==0)
		{
			printf("\n\n");
		}
		else
			printf("\n");
	}
	
	
	printf("\n************* sum of diagonal is M * N matrix is ***************\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j || (j==c-(i+1)))
				sum=sum+ptr[i][j];
			 
		}
	}
	printf("sum :%d\n",sum);
	
	printf("\n****************** sum of 3*3 matrices *******************\n");
	for(i=0;i<r; )
	{
		for(j=0;j<c; )
		{
			for(k=i;k<(3+i);k++)
			{
				for(l=j;l<(3+j);l++)
				{
					sum1=sum1+ptr[k][l];
				}
			}
			printf("sum of 3 * 3 matrix is :%d\n ",sum1);
			sum1=0;
			j=j+3;
		}
	       i=i+3;
	}

	for(i=0;i<r;i++)
	free(ptr[i]);
	free(ptr);
		
	return 0;


}


