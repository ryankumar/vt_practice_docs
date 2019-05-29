#include<stdio.h>
#include<string.h>
int main()
{
	char buf[]="goodmorning";
	char *buf1=buf;
	memmove(buf+3,buf,strlen(buf));
	printf("memmov %s\n",buf);
	memcpy(buf1+3,buf1,strlen(buf1));
	printf("memcpy %s\n",buf1);
}
