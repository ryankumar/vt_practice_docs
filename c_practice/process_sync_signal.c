#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h> // for wait
#include <sys/wait.h>  // for wait

int count=0;
void action(int dummy)
{
	sleep(1);
	printf("Switching\n");
	if(dummy==SIGINT)
		count=1;
}

int main(int argc, char *argv[])
{
	int m = 3;
	if (argc == 2)
		m = atoi(argv[1]);

	pid_t pid1 = fork();         // create the child process
	pid_t pid2 = fork();         // create the child process
	pid_t pid3 = fork();         // create the child process

	signal(SIGUSR1, action);    // set up the signal handler for both parent and child

/*	if ( pid > 0 )              // the parent
	{
		for ( int i = 0; i < m; i++ )
		{
			sleep(1);
			printf("hello %d\n", i);
		}
		kill( pid, SIGUSR1 );   // signal the child
		pause();                // wait for the child to signal back
		printf("All done\n");
	}
	else                        // the child
	{
		pause();                // wait for the signal from the parent
		for ( int i = 0; i < m; i++ )
		{
			sleep(1);
			printf("hi %d\n", i);
		}
		printf("in child pid %d\n",pid);
		printf("getppid() %d\n",getppid());
		kill(getppid(), SIGUSR1);   // signal the parent
	}
	*/
	while(1){
	if(pid1==0)
	{
		printf("1\n");
		kill(pid2,SIGUSR1);
		pause();
	}
	
	if(pid2==0)
	{
		printf("2\n");
		kill(pid3,SIGUSR1);
		pause();
	}
	
	if(pid3==0)
	{
		printf("3\n");
		kill(getppid(),SIGUSR1);
		pause();
	}
	if(count==1)
		break;
	}

	while(1)
	{
		if(count==1)
			break;
		pause();
		printf("4\n");
		kill(pid1,SIGUSR1);
	}

			
	return 0;


}
