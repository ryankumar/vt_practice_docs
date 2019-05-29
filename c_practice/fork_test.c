#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	char *ch ; //=(char *) malloc(sizeof(char));
	int pid;
	int b=20;
	printf("%d\n",b);
	if((pid=fork()))
	{
		ch=(char *) malloc(sizeof(char));

		*ch='a';
		printf("pid : %d  ppid:%d -%c\n",getpid(),getppid(),*ch);
	}
	else
	{
		*ch='c';
		printf("pid: %d   ppid:%d  -%c\n",getpid(),getppid(),*ch);
	}
	int a=10;
	printf("%d\n",a);
	printf("%d\n",b);
	free(ch);
//	getchar();
	return 0;
}
