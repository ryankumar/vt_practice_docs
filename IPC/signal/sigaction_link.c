#include  <stdio.h>
#include  <signal.h>

void  main(void)
{

   while (1)
    {
        sleep(1);
	printf("RUNNING");
        kill(27719, SIGUSR1);
	
    }

}
