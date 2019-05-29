#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include<signal.h>

char read_buffer[100]={'\0'};
 FILE *fp1,*fp2;

// success :return 1 ,  fail:return 0
int stricmp(char *str1,char *str2)
{
	int flag=0;
	int i=0;
	while(str1[i] || str2[i])
	{
		if((str1[i]-str2[i]==32) || (str2[i]-str1[i])==32 || (str1[i]==str2[i]))
			flag=1;
		else
			return  0;
		i++;
	}
	if(flag)
		return 1;
	else return 0;
}

void read_from_file1(void)
{

	fscanf(fp1,"%s",read_buffer);

}

void write_into_file2(void)
{
	char write_buffer[100]={'\0'};
	int count=0;
	while(fscanf(fp2,"%s",write_buffer)!=EOF)
	{
		if(stricmp(read_buffer,write_buffer))
		{
			count++;
			break;
		}
		write_buffer[0]='\0';

	}
	if(count==0)
	{
		fputs(read_buffer,fp2);
		fputs(" ",fp2);
	}
}

int main(int argc,char *argv[])
{
	

	if(argc==3)
	{	
		// input file
		fp1=fopen(argv[1],"r+");
		if(fp1<=0)
		{
			perror("error:");
			exit(0);
		}
	
		//output file
		fp2=fopen(argv[2],"w+");
		if(fp2<=0)
		{
			perror("error:");
			exit(0);
		}
	}
	else
	{
		printf("it requires 3 arguments including executiong file\n");
		return 0;
	}

	while(feof(fp1)==0)
	{
		read_from_file1();
		write_into_file2();
		read_buffer[0]='\0';
		fseek(fp2,0,SEEK_SET);

	}

	return 0;
}
