#include<iostream>
#include<stdlib.h>
#include<pthread.h>
#include <time.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>
using namespace std ;
#define SHARED 0
#define BUFSIZE 20

int terminatethreads=0;


sem_t *Sempty, *Sfull, *Sflag; /* the semaphore descriptors */
char sem1[] = "/semEmpty";  //The names for the semaphores
char sem2[] = "/semFull";
//char sem3[] = "/semFlag";
int buf[BUFSIZE];     /* shared buffer         */
int mycount;

#include "producer.h"
#include "consumer.h"
/*static void sig_alarm(int signo)    
{
	cout << "\nWe got the Signal Alarm, Terminating the threads...\n"<< endl;
	terminatethreads=1;
	return;
}
*/
int main(int argc, char *argv[])    
{
	int ans;
	time_t now;
	pthread_t pid, cid;  

//	time (&now);
//	srand (now); 
//	if (signal (SIGALRM, sig_alarm) == SIG_ERR)   	{
//		cout << "The signal function returned an error" << endl;
//		exit (1);
//	}
	
	//Here we set the alarm to specified seconds.
//	alarm (atoi(argv[1]));
//	cout << "Alarm set.  Now for semaphores" << endl;
//	Sflag = sem_open (sem3, O_CREAT, 660, 1);
	Sfull = sem_open (sem2, O_CREAT, 0666, 0);
	Sempty = sem_open (sem1, O_CREAT, 0666, BUFSIZE);
	mycount = 0;
	cout << "main started" << endl;
	pthread_create(&pid, 0, Producer, NULL);
	pthread_create(&cid, 0, Consumer, NULL);
	cout << "Created both threads" << endl;
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	cout << "The number of items still in the buffer is " << mycount << endl;
	sem_getvalue(Sfull, &ans);
	cout << "The value of Sfull is " << ans << endl;
//	sem_close(Sflag);
	sem_close(Sfull);
	sem_close(Sempty);
	sem_unlink(sem1);
	sem_unlink(sem2);
//	sem_unlink(sem3);
	cout << "Main done\n" << endl;
	return 0;
}
