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

// convert capital to small letter and viceversa.
void convert(char *str)
{
	int i=0;
	while(str[i])
	{
		if(str[i]>='A' && str[i]<='Z')
			str[i]+=32;
		else if(str[i]>='a' && str[i]<='z')
			str[i]-=32;
		i++;
	}
}

// replace the converted string into file
void replace(int *fp,char *str)
{
	
	int l=strlen(str);
	lseek(*fp,(-l-1),SEEK_CUR);
	write(*fp,str,l);
}

int main(int argc,char *argv[])
{

	int fd;
	char store;
	char buffer[30];
	int i=0,ret;
	int count=0;
	char userbuf[100];

	//open an existing file
	fd=open(argv[1],O_RDWR);
	if(fd<0)
	{
		perror("error:");
		exit(0);
	}
	

	printf("enter the string you want to search :\n ");
	scanf("%[^\n]s",userbuf);

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
				count+=1;
				printf("%d.before case conversion: %s\n",count,buffer);
				convert(buffer);
				replace(&fd,buffer);
				printf("%d.after case conversion : %s\n",count,buffer);
			}
			i=0;
			memset(buffer,'\0',sizeof(buffer));
		}

	}

	printf("there are %d times string is available:\n",count);
	return 0;
}




