#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
	int fd = 0;
	char buff[1024];
	char nbuff[1024];
	char ch;
	//Setup Buffer Array
	memset(buff, '0',sizeof(buff));	

	//Create Socket
	fd = socket(AF_INET, SOCK_STREAM, 0);
    	if(fd<0)
	{
		perror("Client Error: Socket not created succesfully");
		return 0;
	}

	//Structure to store details
	struct sockaddr_in server; 
	memset(&server, '0', sizeof(server)); 

	//Initialize	
	server.sin_family = AF_INET;
	server.sin_port = htons(1234); 
        server.sin_addr.s_addr = htonl(INADDR_ANY);
   

	bind(fd, (struct sockaddr*)&server, sizeof(server)); 

	int in;
	
	listen(fd, 10); 
	while(1)
	{	
		in = accept(fd, (struct sockaddr*)NULL, NULL);
		if(in<0)
		{
			perror("accept failed : connection failed.");
			return 0;
		}
		printf("client is connected\n");

		int childpid,n,p;
		
		if ( (childpid = fork ()) == 0 ) 
		{
		
			//close listening socket
			close (fd);
		
			//Clear Zeroes
			bzero(buff,256);
			bzero(nbuff,256);
							
			while (1)  
			{
				// Recieve from client
				
				n = recv(in, buff, 256,0) ;
				if (n<0) 
				{
					perror("\nServer Error: Reading from Client");

					return 0;
				}
														                
				printf("Server Received: %s",buff);

				// send to client
				
			//	fgets(nbuff,1024,stdin);
			   while(n>0){

				p=send(in, buff, strlen(nbuff), 0);
				if (p !=n) 
				{
					perror("\nServer Error: Writing to Server");
					return 0;															   
			        }
				 n = recv(in, buff, 256,0) ;
				                                
				if (n<0)
			
				{
					perror("\nServer Error: Reading from Client");

					return 0;
				}
			   }

				
				bzero(buff,256);
			//	bzero(nbuff,1024);
										
			}
		 }
			close(in);
			
	}
	exit(0);
}
