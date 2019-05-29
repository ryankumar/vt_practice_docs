#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{ 
	printf("main is here\n");
} 

// _start() function 
void _start(void) 
{ 
	printf("GeeeksforGeeks"); 

	// Call main() function 
//	int var = main(); 
	exit(0); 
} 

