

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
//#include "key.h"
//#define KEY	555	

struct mesg{
  long int type;
    char msg[20];
   };


int main()
{  
	struct  mesg message;
	int qid,n;
	key_t key;
	key = ftok("/home/mahannee/empid-1017/IPC/msgque", 'b');

	qid=msgget(key,0666);
	if(qid<0)
	{ 
		perror("msgget");
		exit(0);
        }			// Any first message in the msg queue
	for(; ;){	
	if((n=msgrcv(qid,&message,20,0,0))<0)
  	{ 	
		perror("msgrcv");
		exit(0);
    	}
	
	printf("msg is:%s\n",message.msg);
	printf("msg typ is %ld\n",message.type);
	}
	return 0;
}
