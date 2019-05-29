#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
struct test {
	sem_t mutex1;
	sem_t mutex2;
	sem_t mutex3;
	sem_t mutex4;
	int temp;
};

int main(int argc, char **argv)
{
	int fd, i,zero=0,*ptr;
	struct test *testptr;	
	int count=0;
	ptr = mmap(NULL, sizeof(struct test),PROT_READ |PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,0,0);
	if(ptr == (void *)-1) {
	   printf("mmap failure\n");
	   exit(-1);
	 }

	testptr = (struct test *) ptr;
	/* initialize semaphore */
	if( sem_init(&(testptr->mutex1),1,1) < 0)
	{
		perror("semaphore initilization");
		exit(0);
	}

	/* create, initialize semaphore */
	if( sem_init(&(testptr->mutex2),1,0) < 0)
	{
		perror("semaphore initilization");
		exit(0);
	}

	if( sem_init(&(testptr->mutex3),1,0) < 0)
	{
		perror("semaphore initilization");
		exit(0);
	}

	if( sem_init(&(testptr->mutex4),1,0) < 0)
	{
		perror("semaphore initilization");
		exit(0);
	}

	if (fork() == 0) { /* child process*/
		while(1){
			sem_wait(&(testptr->mutex2));
			printf("child: 2\n");
			sem_post(&(testptr->mutex3));
		}
		exit(0);
	}

	if (fork() == 0) { /* child process*/
		while(1){
			sem_wait(&(testptr->mutex3));
			printf("child: 3\n");
			sem_post(&(testptr->mutex4));
		}
		exit(0);
	}

	if (fork() == 0) { /* child process*/
		while(1){
			sem_wait(&(testptr->mutex4));
			printf("child: 4\n");
			sleep(1);
			sem_post(&(testptr->mutex1));
		}
		exit(0);
	}

	/* back to parent process */
	while(1){
		sem_wait(&(testptr->mutex1));
		printf("parent : 1 %d\n",count++);
		sem_post(&(testptr->mutex2));
	}
	exit(0);

}
