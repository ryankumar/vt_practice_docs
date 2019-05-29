// C program to implement cond(), signal()
// and wait() functions
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

// declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done = 1;
char msg[20];

// Thread function
void* foo()
{

	while(1){
		pthread_mutex_lock(&lock);
		if (done == 1){
			done = 2;
//			scanf("%s",msg);
			printf("Waiting on condition variable cond1\n");
			pthread_cond_wait(&cond1, &lock);
		}
		
		pthread_mutex_unlock(&lock);
	}
	printf("Returning thread\n");

	return NULL;
}

void * foo1()
{
	while(1){
		pthread_mutex_lock(&lock);
		if(done==2){
			done =1;
			printf("from thread 1 msg: %s",msg);
			printf("Signaling condition variable cond1\n");
			sleep(1);
			pthread_cond_signal(&cond1);
			
		}
		pthread_mutex_unlock(&lock);
	}

	printf("Returning thread\n");

	return NULL;
}

// Driver code
int main()
{
	pthread_t tid1, tid2;

	// Create thread 1
	pthread_create(&tid1, NULL, foo, NULL);
	pthread_create(&tid2, NULL, foo1, NULL);

	// wait for the completion of thread 2
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
