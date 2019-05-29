#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//  string comparision with case insensitive.
// success :return 0 ,  fail:return 1
int stricmp(char *str1,char *str2)
{
	int flag=0;
	int i=0;
	while(str1[i] || str2[i])
	{
		if((str1[i]-str2[i]==32) || (str2[i]-str1[i])==32 || (str1[i]==str2[i]))
			flag=1;
		else
			return  1;
		i++;
	}
	if(flag)
		return 0;
	else return 1;
}

//  string reverse
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

// replace the reverse word with matching word
void replace(int *fp,char *ptr)
{
	int l=strlen(ptr);
	lseek(*fp,(-l-1),SEEK_CUR);
	write(*fp,ptr,l);
}


int main(int argc,char *argv[])
{

	int fd;
	char store;
	char buffer[30];
	int i=0,ret;
	char *revptr=NULL;
	char *userbuf=NULL;
	//open an existing file
	fd=open(argv[1],O_RDWR);
	if(fd<0)
	{
		perror("error:");
		exit(0);
	}

	userbuf=argv[2];
	while(read(fd,&store,1)>0)
	{
		if(store!=' ')
		{
			buffer[i]=store;
			i++;
		}
		else
		{
			ret=stricmp(userbuf,buffer);
			if(ret==0)
			{
				printf("before  reverse buffer :%s\n",buffer);
				revptr=strrev(buffer);
				printf(" after revers revptr : %s\n",revptr);
				replace(&fd,revptr);
			}
			i=0;
			memset(buffer,'\0',sizeof(buffer));
		}
	}
	return 0;
}




