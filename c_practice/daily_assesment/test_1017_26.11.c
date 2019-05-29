// reverse the string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * strrev(const char *str)
{
	int i=0,j;
	char *ptr=(char *)malloc(sizeof(char) * strlen(str));
	memset(ptr,'\0',sizeof(char) * strlen(str));
	for(i=0,j=strlen(str)-1;j>=0;i++,j--)
		ptr[i]=str[j];
	return ptr;
}

int main()
{
	char *str=(char *)malloc(sizeof(str));
	char *ptr=NULL;
	printf("enter string:\n");
	scanf("%[^\n]s",str);
	ptr=strrev(str);
	printf("after reverse ptr:%s\n",ptr);
	free(ptr);
	return 0;
}
