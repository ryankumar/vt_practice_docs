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
FILE *main_fp=NULL;
pthread_t thread1,thread2,main_thread;
char buffer[2][100]={"\0"};

int count=0;
sigset_t set;
int sig;
int set_thrd1=0,set_thrd2=0;
char *cmnd_linebuf=NULL;
char space[]=" ";
int num=0;
void write_into_newfile(void)
{
	for(int i=0;i<2;i++)
	{
		if(buffer[i])
		{
			fputs(buffer[i],main_fp);
			if(feof(fd)==0)
			fputs(space,main_fp);
		}

	}
	printf("main %d\n",num++);
	memset(buffer,0,sizeof(buffer));

}

void creat_threads(void)
{
	int ret;
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

}




// Main function
int main(int argc,char *argv[])
{
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);
//	sigaddset(&set,SIGUSR2);
	pthread_sigmask(SIG_BLOCK, &set, NULL);	

	int i=0,ret;
	void * t_result;
	int s;
	

	//source file buffer;
	if(argc==2)
		cmnd_linebuf=argv[1];
	else
	{
		printf("please enter source file name in command line argument\n");
		return 0;
	}
	
	// open a new file for write operation
	main_fp=fopen("NEW_FILE.txt","w+");
	if(main_fp<=0)
	{
		printf("file open is failed ,so check it out\n");
		return 0;
	}
	
	main_thread=pthread_self();
	creat_threads();

	// block the main thread untill two threads ready
	while(set_thrd1==0 || set_thrd2==0)
	{
	}
	
	// send signal to thread1 and wait for write operation	
	pthread_kill(thread1,SIGUSR1);
	sigwait(&set,&sig);

	while(feof(fd)==0)
	{
		write_into_newfile();
		pthread_kill(thread1,SIGUSR1);
		sigwait(&set,&sig);
	}

	pthread_join(thread1,&t_result);
	printf("thread1 Joined\n");
	pthread_join(thread2,&t_result);
	printf("thread2 joined\n");

	fclose(main_fp);
	fclose(fd);
	pthread_exit("EXITSTATUS");
}

// entry point to thread1
void *THREAD1(void *arg)
{	

	set_thrd1=1;
	sigwait(&set,&sig);
	
	//open the source file
	fd=fopen(cmnd_linebuf,"r");
	if(fd<=0)
	{
		printf("file open is failed ,so check it out\n");
		return 0;
	}

	while(fscanf(fd,"%s",buffer[0])!=EOF)
	{	printf("thread1 %d\n",num++);
		pthread_kill(thread2,SIGUSR1);
		sigwait(&set,&sig);

	}

	printf("thread1 ready for exit\n");
	pthread_kill(thread2,SIGUSR1);
	pthread_kill(main_thread,SIGUSR1);
	pthread_exit(NULL);
}

// entry point to thread2
void *THREAD2(void *arg)
{
	int ret;
	set_thrd2=1;

	sigwait(&set,&sig);
	while(!feof(fd))
	{
		printf("thread2 %d\n",num++);
		fscanf(fd,"%s",buffer[1]);
		pthread_kill(main_thread,SIGUSR1);
		sigwait(&set,&sig);		 
	}

	printf("thread2 ready for exit\n");
	pthread_exit(NULL);

}



