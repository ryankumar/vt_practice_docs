// reverse the string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * strrev(char *str)
{
	int i=0,j,l;
	char temp;
	l=strlen(str);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
	return str;
}

char *duplicate(const char *str)
{
	int i=0,j,k;
	char *ptr=(char *)malloc(sizeof(char) * strlen(str));
	if(ptr)
	{
		memset(ptr,'\0',sizeof(char)*strlen(ptr));
		memcpy(ptr,str,strlen(str));

		for(i=0;ptr[i];i++)
		{
			for(j=i+1;ptr[j];j++)
			{
				while(ptr[i]==ptr[j])
				{
					k=j;
					while(ptr[k])
					{
						if(ptr[k]!=ptr[k+1])
						ptr[k]=ptr[k+1];
						k++;
						
					}
				}
			}

		}
		return ptr;
	}
	else 
		printf("memory is not allocated in duplicate fun\n");



}

int main()
{
	char str[100];
	char *ptr=NULL;
	printf("enter string:\n");
	scanf("%[^\n]s",str);
	ptr=duplicate(str);
	printf("after removing:%s\n",ptr);
	ptr=strrev(ptr);
	printf("after reverse :%s\n",ptr);
	free(ptr);
	return 0;
}
