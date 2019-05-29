#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void hdl (int sig, siginfo_t *siginfo, void *context)
{
    printf("sig no = %d \n", sig);
    if(sig == SIGINT)
        exit(0);
    printf ("Sending PID: %ld, UID: %ld\n",
            (long)siginfo->si_pid, (long)siginfo->si_uid);
}

int main (int argc, char *argv[])
{
    struct sigaction act;


    sigemptyset(&act.sa_mask);

    act.sa_sigaction = &hdl;
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &act, NULL) < 0) {
        perror ("sigaction SIGUSR1");
        return 1;
    }
    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror ("sigaction SIGINT");
        return 1;
    }

    while (1)
    {
        sleep(1);
    }

    return 0;
}
