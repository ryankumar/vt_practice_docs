#include <stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

       #include <fcntl.h>           /* For O_* constants */
       #include <sys/stat.h>        /* For mode constants */
       #include <semaphore.h>

sem_t bin_sem;
int main()
{
	int shmid;
	char *msg;
	sem_t *res;	
	if((shmid=shmget(13,1024,666|IPC_CREAT))==-1) {
		perror("shmget");
		exit(1);
	}
//	sem_unlink ("mysem"); 	/* sem_unlink - remove a named semaphore */
	msg=shmat(shmid,0,0);
	res=sem_open("mysem",O_CREAT,0666,2);	
	if(res==SEM_FAILED){
		perror("semopen");
	}
	sem_wait(res);
	printf("Enter the data you want to write into shared memory\n");
	fgets(msg,1024,stdin);
	sem_post(res);
	printf("Data successfully written\n");
	sem_unlink("mysem");
	getchar();
	shmdt(msg);
//	shm_unlink("");
}
	
	
