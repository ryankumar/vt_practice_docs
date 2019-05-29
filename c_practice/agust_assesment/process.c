#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
//void *T1_func(void *arg);
//void *T2_func(void *arg);
//void *T3_func(void *arg);
//void *T4_func(void *arg);
void parent();
void child1();
void child2();
void child3();
sem_t s1,s2,s3,s4;


#define WORK_SIZE 1024
//char work_area[WORK_SIZE];

int main() 
{
	int res;
//	pthread_t T1,T2,T3,T4;
//	void *thread_result;
	int pid1,pid2,pid3;
	
	res = sem_init(&s1, 1, 1);
	if (res != 0) {
		perror("Semaphore1 initialization failed");
		exit(EXIT_FAILURE);
	}
	
	res = sem_init(&s2, 1, 0);
	if (res != 0) {                                     
	
		perror("Semaphore2 initialization failed");             
		exit(EXIT_FAILURE);                      
	}

       res = sem_init(&s3, 1, 0);
        if (res != 0) {                                     
		perror("Semaphore3 initialization failed");             
		exit(EXIT_FAILURE);                      
	}

        res = sem_init(&s4, 1, 0);
        if (res != 0) {                                     
	              
		perror("Semaphore4 initialization failed");             
                exit(EXIT_FAILURE);                      
	}

	pid1=fork();
	if(pid1!=-1)
		pid2=fork();
	if(pid2!=-1 || pid1!=-1)
		pid3=fork();
	if(pid1==-1 || pid2==-1 || pid3==-1)
	{
		printf("fork creation faild\n");
		return -1;
	}

	if(pid1>0 || pid2>0 || pid3>0)
	{
		parent();
	}
				
	if(pid1==0)
	{
		child1();
	}
	if(pid2==0)
	{
		child2();
	}
	if(pid3==0)
	{
		child3();
	}

	sem_destroy(&s1);
	sem_destroy(&s2);
	sem_destroy(&s3);
	sem_destroy(&s4);

    	exit(EXIT_SUCCESS);
}

void parent()
{
	while(1)
	{
		sem_wait(&s1);
		printf("1 ");
		sem_post(&s2);
	}
}

void child1()
{
	while(1)
	{
		sem_wait(&s2);
		printf("2 ");
		sem_post(&s3);
	}
}

void child2()
{
	while(1)
	{
		sem_wait(&s3);
			printf("3 ");
		sem_post(&s4);
	}
}

void child3()
{
	while(1)
	{
		sem_wait(&s4);
		printf("4 ");
		sem_post(&s1);
	}
}

