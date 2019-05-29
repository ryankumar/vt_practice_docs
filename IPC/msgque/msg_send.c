
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

    	qid = msgget(key, 0666 | IPC_CREAT);
	if (qid < 0) {
		perror("msgget");
		exit(0);
    	}
	message.type = 123;
	strcpy(message.msg, "testing");
     while(1){//fgets(message.msg,sizeof(message.msg),stdin)!=NULL){
		int len=strlen(message.msg);

		if ((n = msgsnd(qid, &message, len+1, 0)) < 0) {
			perror("msgsnd");
			exit(0);
    		}
	
	printf("return value: %d   key:%d \n",n,key);
    	printf("msg sent\n");
     }
	return 0;
}
