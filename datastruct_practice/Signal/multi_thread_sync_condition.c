// C program to implement cond(), signal()
// and wait() functions
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;

// declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

char msg[20];
char msg1[20];
void print(int i)
{
	printf("function call from thread %d\n",i);
	sleep(1);
}

// Thread function
void* foo()
{

	while(1){
		pthread_mutex_lock(&lock);
		printf("thread1\n");
		print(1);
		pthread_cond_signal(&cond2);
		pthread_cond_wait(&cond1, &lock);
		pthread_mutex_unlock(&lock);
	}
	printf("Returning thread\n");

	return NULL;
}

void* foo1()
{

	while(1){
		pthread_mutex_lock(&lock);
		printf("thread2\n");
		print(2);
		pthread_cond_signal(&cond3);
		pthread_cond_wait(&cond2, &lock);
		pthread_mutex_unlock(&lock);
	}
	printf("Returning thread\n");
	return NULL;
}


void * foo2()
{
	while(1){
		pthread_mutex_lock(&lock);
		printf("thread3\n");
		print(3);
		pthread_cond_signal(&cond1);
		pthread_cond_wait(&cond3, &lock);
		pthread_mutex_unlock(&lock);
	}

	printf("Returning thread\n");

	return NULL;
}

// Driver code
int main()
{
	pthread_t tid1, tid2, tid3;

	// Create thread 1
	pthread_create(&tid1, NULL, foo, NULL);
	pthread_create(&tid2, NULL, foo1, NULL);
	pthread_create(&tid3, NULL, foo2, NULL);

	// wait for the completion of thread 2
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	return 0;
}
