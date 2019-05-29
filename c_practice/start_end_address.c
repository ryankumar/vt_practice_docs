#include<stdio.h>
extern char __executable_start;
extern char __etext;
int main()
{
	printf("start address:0x%1x\n",(unsigned long)&__executable_start);
	printf("end address:0x%1x\n",(unsigned long)&__etext);
//	getchar();
	return 0;
}
