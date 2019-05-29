#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	char ch[]="hello this is new world";
	int len,count=0,i=0,j=0,flag=0;
	char c;
	while(ch[i])
	{
		if(ch[i]==' ' && ch[i+1]!=' ')
			count++;
		else if((count % 2!=0) && (ch[i-1]==' '))
			ch[i]=ch[i]-32;
		else if(count % 2==0)
			ch[i]=ch[i]-32;
		i++;
	}
	printf("after change %s\n",ch);
	printf("enter the character to delete from string\n");
	scanf("%c",&c);
	j = 0;			
	while(ch[j])
	{
		if(c==ch[j])
		{
			i=j;
			while(ch[i])
			{
				ch[i]=ch[i+1];
				i++;
			}
			flag=1;
		}
		else
		    j++;
	}
	if(flag==0)
		printf("entered character is not matched\n");
	else
		printf("after delete char %s\n",ch);
	return 0;
}
