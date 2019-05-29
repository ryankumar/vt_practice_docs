// Remove duplicate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void duplicate(char *str)
{
	bool arr[52]={0};
	int i=0,j=0;

	while(str[i])
	{
		if(str[i]>='A' && str[i]<='Z') 
		{
			if(arr[str[i]-65]==0)
			{
				str[j]=str[i];
				j++;
				arr[str[i]-65]=1;
			}
		}

		else if(str[i]>='a' && str[i]<='z')
		{
			if(arr[str[i]-71]==0)
			{
				str[j]=str[i];
				j++;
				arr[str[i]-71]=1;
			}
		}

		i++;
	}
	str[j]='\0';
}


int main()
{
	char str[100]={'\0'};
	printf("enter string:\n");
	scanf("%[^\n]s",str);
	duplicate(str);
	printf("after remove :%s\n",str);
	return 0;
}
