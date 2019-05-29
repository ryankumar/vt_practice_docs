#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ispalindrom(char *ptr);
int palindrom(char *str)
{
	int n,i,j,count=0;
	char ptr[100];
	n=strlen(str);
	printf("lenght : %d\n",n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			ptr[j]=str[j+i];
			if(ispalindrom(ptr))
			{	if(count>0)
				printf("%s\n",ptr);
			}
			count++;
		}
		memset(ptr,'\0',sizeof(ptr));
		count=0;
	}

}

int ispalindrom(char *ptr)
{
	int flag=0;
	int i=0,j=(strlen(ptr)-1);
	while(i<j)
	{
		
		if(ptr[i]==ptr[j])
		{
			i++;j--;
			flag=1;
		}
		else 
		{
			flag=0;
			break;
		}

	}
	if(flag==1)
	return 1;
	return 0;
}

int main()
{
	char str[100];
	printf("enter the string :\n");
	scanf("%[^\n]s",str);
	palindrom(str);
	return 0;
}
