#include<stdio.h>

unsigned int swap_bit(unsigned int x)
{
	return ((x & 0b1010101010101010) >>1) | ((x & 0b0101010101010101) <<1);

}

int main()
{
	unsigned int a= 0x0A08;
	printf("%02X\n",swap_bit(a));
}
