#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include<signal.h>

void * THREAD1(void * arg);
void * THREAD2(void * arg);
FILE *fd=NULL;
pthread_t thread1,thread2;
char *revptr=NULL;
char *userbuf=NULL;
char buffer[100];
int count=0;
sigset_t set;
int sig;
int set_thrd1=0,set_thrd2=0;

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
void replace_infile(char *ptr)
{
	int l=strlen(ptr);
	fseek(fd,-l,SEEK_CUR);
	fputs(ptr,fd);
}


// Main function
int main(int argc,char *argv[])
{
	int i=0,ret;
	void * t_result;
	int s;

	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);
	sigaddset(&set,SIGUSR2);

	if(argc==3)
	{
		fd=fopen(argv[1],"r+");
		if(fd<=0)
		{
			perror("error:");
			exit(0);
		}

		//input string given by user
		userbuf=argv[2];
	}
	else
	{
		printf("it requires 3 arguments including executiong file\n");
		return 0;
	}

	//Block all signals	
	pthread_sigmask(SIG_BLOCK, &set, NULL);

	ret=pthread_create(&thread1,NULL,THREAD1,NULL);
	if(ret!=0)
	{
		perror("Error:");
		exit(0);
	}
	ret=pthread_create(&thread2,NULL,THREAD2,NULL);
	if(ret!=0)
	{
		perror("ERror:");
		exit(0);
	}

	pthread_join(thread1,&t_result);
	printf("thread1 Joined\n");
	pthread_join(thread2,&t_result);
	printf("thread2 joined\n");

	fclose(fd);
	pthread_exit("EXITSTATUS");
}

// entry point to thread1
void *THREAD1(void *arg)
{

	set_thrd1=1;
	while(fscanf(fd,"%s",buffer)!=EOF)
	{
		if(set_thrd2){
			pthread_kill(thread2,SIGUSR2);
			sigwait(&set,&sig);
		}
	}
	printf("thread1 ready for exit\n");
	pthread_kill(thread2,SIGUSR2);
	pthread_exit(NULL);
}

// entry point to thread2
void *THREAD2(void *arg)
{
	int ret;
	set_thrd2=1;
	while(feof(fd)==0)
	{
		ret=stricmp(userbuf,buffer);
		if(ret==0)
		{
			printf("before  reverse buffer :%s\n",buffer);
			revptr=strrev(buffer);
			printf(" after revers revptr : %s\n",revptr);
			replace_infile(revptr);
		}
		memset(buffer,'\0',sizeof(buffer));
		if(set_thrd1){
			pthread_kill(thread1,SIGUSR1);
			sigwait(&set,&sig);	
		}
	}
	printf("thread2 ready for exit\n");
	pthread_exit(NULL);

}



