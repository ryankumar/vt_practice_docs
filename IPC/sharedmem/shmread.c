

#include <stdio.h>

#include <stdlib.h>

#include<sys/ipc.h>

#include<sys/shm.h>

#include<stdio.h>
main()

{
	int shmid;
	char ch;
	char *msg=&ch;
	key_t key;
	key = ftok("/home/mahannee/empid-1017/IPC/sharedmem", 65);
	printf("key:%d\n",key);
	if((shmid=shmget(key,1024,0))==-1) {
		perror("shmget");
		exit(1);
	}
	msg=shmat(shmid,0,0);
	printf("Data written in the shared memory is:%s\n",msg);
	getchar();
	shmdt(msg);
}

	
	
