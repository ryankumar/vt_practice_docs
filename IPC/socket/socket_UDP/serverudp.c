#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int mai(int argc,char *argv[]){
  int udpSocket, nBytes;
  char buffer[1024];
  char buff[100];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i,ret;

  /*Create UDP socket*/
  udpSocket = socket(AF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = INADDR_ANY;//inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Bind socket with address struct*/
  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverStorage;
  
  // open file
   FILE *fr= fopen(argv[1],"r+");
    if(fr==NULL)
	    printf("File %s cannot be opend \n");
     
     
 // while(1){
    /* Try to receive any incoming UDP datagram. Address and port of 
      requesting client will be stored on serverStorage variable */
  //  nBytes = recvfrom(udpSocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);

    /*Convert message received to uppercase*/
   /* for(i=0;i<nBytes-1;i++)
      buffer[i] = toupper(buffer[i]);
*/
    //  printf("form client :%s",buffer);
   //  bzero(buffer,1024);
    /*Send uppercase message back to client, using serverStorage as the address*/
//	scanf("%s",buffer);
	__fpurge(stdin);
//	printf("send to client: \n");
//	fgets(buff,100,stdin);
	while((ret=fread(buff,sizeof(char),100,fr))>0){
    		sendto(udpSocket,buff,ret,0,(struct sockaddr *)&serverStorage,sizeof(serverStorage));
    		bzero(buff,100);
	}
	
 // }

  return 0;
}
