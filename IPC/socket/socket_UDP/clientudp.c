/************* UDP CLIENT CODE *******************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main(){
  int clientSocket, portNum, nBytes;
  char buffer[1024];
   char buff[100];

  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /*Create UDP socket*/
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(12345);
  serverAddr.sin_addr.s_addr = inet_addr("192.168.2.200");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverAddr;

  while(1){

//	printf("Type a sentence to send to server:\n");
  //  fgets(buffer,1024,stdin);
    //printf("You typed: %s",buffer);
 
  //  nBytes = strlen(buffer) + 1;
    
    /*Send message to server*/
//    sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
	bzero(buffer,1024);
    /*Receive message from server*/
                nBytes = recvfrom(clientSocket,buff,100,0,NULL, NULL);
 	
    printf("Received from server: %s\n",buff);
    bzero(buff,100);
  }

  return 0;
}
