#include<stdio.h> 
#include<signal.h> 
#include<wait.h> 
#include<stdlib.h>
#include<unistd.h>
int val = 10; 
void handler(int sig) 
{ 
    val += 5; 
} 
int main() 
{ 
    pid_t pid; 
	int stat;
    signal(SIGCHLD, handler); 
    if ((pid = fork())==0) 
    { 
        val -= 3; 
        exit(0); 
    } 
    waitpid(pid, &stat, 0); 
    printf("val = %d  stat= %d\n", val,stat); 
    exit(0); 
} 
