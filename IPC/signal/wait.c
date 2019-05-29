#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t	pid;
	int	status;
	printf("Forking child process...\n");
	if ((pid = fork()) < 0)
	{
		printf("fork failed!\n");
		exit(1);
	}
	else if (pid == 0)	
	{   /* child process */ 
		sleep(5);
		printf("Child process is shutting down\n");
		exit(7);
	}
	else	 
	{     /* parent process */
		if (wait (&status) != pid)   	
		{
			printf("Wait returned invalid pid\n");
			exit(1);
		}
		else
			printf("wait(status):%d\n",wait(&status));
		if (WIFEXITED(status))
			printf("Normal Termination. Exit value %2d\n wait(status):%d\n",WEXITSTATUS(status),wait(&status));

		else   
		{
			printf("Abnormal termination!!!\n");
			exit(1);
		}
		printf("Parent shutting down...\n");
		exit(0);
	}
}
