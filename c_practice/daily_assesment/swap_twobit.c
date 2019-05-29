#include<stdio.h>
int main()
{
	unsigned char data=0x07 ;
	data^=(1<<1);
	data^=(1<<2);
	printf("%02X\n",data);


}
