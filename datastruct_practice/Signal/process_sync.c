// C program to implement sighup(), sigint() 
// and sigquit() signal functions 
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
  
// function declaration 
void sighup(); 
void sigint(); 
void sigquit(); 
void sigusr1();
  
// driver code 
void main() 
{ 
    pid_t pid; 
  	signal(SIGINT,sigint);
    /* get child process */
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { /* child */
	
        signal(SIGHUP, sighup);
        signal(SIGUSR1, sigusr1); 
        signal(SIGQUIT, sigquit); 
	while(1);

    } 
  
    else /* parent */
    { /* pid hold id of child */
	while(1){
        printf("\nPARENT: sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGUSR1\n\n"); 
        kill(pid, SIGUSR1); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3);
	} 
    } 
}
  
// sighup() function definition 
void sighup() 
{ 
    printf("CHILD: I have received a SIGHUP\n"); 
} 
  
// sigint() function definition 
void sigint() 
{ 
    printf("CHILD: I have received a SIGINT\n");
   exit(0); 
} 
  
// sigquit() function definition 
void sigquit() 
{ 
    printf("My DADDY has Killed me!!!\n"); 

} 

void sigusr1()
{
	printf("CHILD : I have recieved a SIGUSR1\n");
}