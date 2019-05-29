#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
//#include "key.h"    
//# define KEY	555

   struct mesg{
   long int type;
	char msg[20];
    };

int main()
{
    	struct mesg message;
	int qid, n;
	key_t key;
//	system("clear");
	key = ftok("/home/mahannee/empid-1017/IPC/msgque", 'b');

    	qid = msgget(key, 0666);
	if (qid < 0) {
		perror("msgget");
		exit(0);
    	}
	if ((n = msgctl(qid,IPC_RMID, 0)) < 0) {
		perror("msgctl");
		exit(0);
    	}
	printf("return value :%d    key:%d\n",n,key);
    	printf("KEY msg removed\n");
	return 0;
}
