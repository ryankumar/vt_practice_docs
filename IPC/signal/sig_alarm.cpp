#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

#define MAXLINE 128
static void sig_alarm(int signo);

int main ()   
{
	int n;
	char line [MAXLINE];
	struct sigaction act;
	memset (&act, 0, sizeof(act));
	act.sa_handler = &sig_alarm;
	act.sa_flags = SA_RESTART;
	if ((sigaction(SIGALRM, &act, NULL)) < 0)	
	{

		cout <<"The sigact function returned an error" << endl;	
		exit (1);	
	}
	alarm (5);
	if ( cin.getline(line, MAXLINE) < 0)	
	{
		cout << "cin returned an error" << endl;
		exit(1);
	}
	alarm(0);
	cout << line << endl;
	exit(0);
}

static void sig_alarm(int signo)  
{
	cout << " ### We got the alarm signal!! ###" << endl;
}
