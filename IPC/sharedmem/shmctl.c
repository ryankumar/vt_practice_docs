

#include <stdio.h>

#include <stdlib.h>

#include <sys/ipc.h>

#include <sys/shm.h>



main()

{

	int shmid;

	key_t key;
	key = ftok("/home/mahannee/empid-1017/IPC/sharedmem", 65);
	printf("key:%d\n",key);

	if((shmid=shmget(key,0,0))==-1) {

		perror("shmid");

		exit(1);

	}

	

	if(shmctl(shmid,IPC_RMID,0)==-1) {

		perror("shmctl");

		exit(1);

	}



	

	printf("Shared memory successfully removed\n");

}
