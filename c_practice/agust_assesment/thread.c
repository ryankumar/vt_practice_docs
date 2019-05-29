#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
void *T1_func(void *arg);
void *T2_func(void *arg);
void *T3_func(void *arg);
void *T4_func(void *arg);

sem_t s1,s2,s3,s4;


#define WORK_SIZE 1024
//char work_area[WORK_SIZE];

int main() 
{
	int res;
	pthread_t T1,T2,T3,T4;
	void *thread_result;

	
	res = sem_init(&s1, 0, 1);
	if (res != 0) {
		perror("Semaphore1 initialization failed");
		exit(EXIT_FAILURE);
	}
	
	res = sem_init(&s2, 0, 0);
	if (res != 0) {                                     
	
		perror("Semaphore2 initialization failed");             
		exit(EXIT_FAILURE);                      
	}

       res = sem_init(&s3, 0, 0);
        if (res != 0) {                                     
		perror("Semaphore3 initialization failed");             
		exit(EXIT_FAILURE);                      
	}

        res = sem_init(&s4, 0, 0);
        if (res != 0) {                                     
	              
		perror("Semaphore4 initialization failed");             
                exit(EXIT_FAILURE);                      
	}

	res = pthread_create(&T1, NULL, T1_func, NULL);
	if (res != 0) {
		perror("Thread1 creation failed");
		exit(EXIT_FAILURE);
	}			

	res = pthread_create(&T2, NULL, T2_func, NULL);
	if (res != 0) {                                             

		perror("Thread2 creation failed");                              
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&T3, NULL, T3_func, NULL);
	if (res != 0) {                                             

		perror("Thread3 creation failed");                              
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&T4, NULL, T4_func, NULL);
        if (res != 0) {                                             

		perror("Thread4 creation failed");                              
		exit(EXIT_FAILURE);
	}
	
	printf("\nWaiting for thread to finish...\n");
   
	res = pthread_join(T1, &thread_result);
    	if (res != 0) {
	        perror("Thread1 join failed");
	            exit(EXIT_FAILURE);
        }

	res = pthread_join(T2, &thread_result);
	if (res != 0) {

		perror("Thread2 join failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_join(T3, &thread_result);
	if (res != 0) {

		perror("Thread3 join failed");
		exit(EXIT_FAILURE);
	}

    	printf("Thread joined\n");
    	sem_destroy(&s1);
	sem_destroy(&s2);
	sem_destroy(&s3);
	sem_destroy(&s4);

    	exit(EXIT_SUCCESS);
}

void *T1_func(void *arg) 
{
	while(1)
	{
		sem_wait(&s1);
		printf("1\t");
		sem_post(&s2);
	}
	pthread_exit(NULL);
}

void *T2_func(void *arg)        
{
	while(1)
	{
		sem_wait(&s2);
		printf("2\t");
		sem_post(&s3);
		
	}
	pthread_exit(NULL);
}

void *T3_func(void *arg)        
{
	
	while(1)
	{	
	
		sem_wait(&s3);
		printf("3\t");
		sem_post(&s4);

	}
	pthread_exit(NULL);
}

void *T4_func(void *arg)        
{
	
	while(1)
	{
		
		sem_wait(&s4);
		printf("4\n");
		sleep(1);
		sem_post(&s1);
	
	}
	pthread_exit(NULL);
}



