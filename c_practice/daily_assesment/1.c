#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void strrev(char *str)
{
	char temp;
	int l=strlen(str);
	int i,j;
	printf("in strrev\n");
	for(i=0,j=l-1;i<j;i++,j--)
	{

		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}

int ismatching(char *str,char *sstr)
{
	int i=0,j=0;
	int count=0;
	while(str[i] && sstr[j])
	{
		if(str[i]==sstr[j])
			count++;
		else
			return 0;
		i++;j++;
	}
	printf("in ismatching123\n");
	if(count>=0)
	return 1;
}

char * find_substring(char *str,char *sstr)
{
	char ch;
	int i=0,j=0,k=0;
	int count=0;
	char *temp=str ;
	while(*str)
	{
		if(*str == *sstr)
		{
			if(ismatching(str,sstr))
			{
			count++;
			j=i;
			}	
		}
		str++;
		i++;
		printf("count1 %d %s\n",count,str);
	}

	printf("in find_substring12\n");
	if(count>=1)
	{
		strrev(sstr);
		printf("temp %s sstr %s\n",temp,sstr);
		while(sstr[k])
		{
			temp[j]=sstr[k];
			j++;
			k++;
		}
	}
	return temp;
}
	



int main()
{

	char str[100]={'\0'};
	char sstr[100]={'\0'};
	char *temp=NULL;
	printf("enter the string\n");
	scanf("%s",str);
	printf("enter the substring\n");
	scanf("\n%s",sstr);
	printf("in main\n");
	temp=find_substring(str,sstr);
	printf("after replacing main string %s\n",temp);
	return 0;
}
