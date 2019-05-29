#include <stdio.h>
#include <stdlib.h>    
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>    
#include <pthread.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <stropts.h>
#include <string.h>

void *connection_recv(void *);
void *connection_send(void *);

#define MAX_SIZE 50

int main(int argc , char *argv[])
{
	int socket_desc , c , *new_sock, client_sock;
    	struct sockaddr_in server , client;
    
    	int i = 0 , fd , fd1;

    	//Create socket
    	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    	if (socket_desc == -1)
    	{
        	printf("Could not create socket");
    	}
    	puts("Socket created");

    	//Prepare the sockaddr_in structure
    	server.sin_family = AF_INET;
    	server.sin_addr.s_addr = INADDR_ANY;
    	server.sin_port = htons(1234 );

    	int tr = 1;
   
    	// kill Address already in use error message

    	if (setsockopt(socket_desc,SOL_SOCKET,SO_REUSEADDR,&tr,sizeof(int)) == -1) {
    	perror("setsockopt");
    	exit(1);
    	}


    	//Bind
    	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    	{
        	printf("bind failed\n");
        	//print the error message
       		// perror("bind failed. Error");
        	return 1;
    	}
 
    	puts("bind done");

    	//Listen
    	listen(socket_desc ,5);

    	//Accept and incoming connection
    	puts("Waiting for incoming connections...");
    
    	c = sizeof(struct sockaddr_in);

    	// FIFO file path
    	char *myfifo = "myfifoo" , *myfifo1 = "myfifo1";

    	mkfifo("myfifoo", 0666);

    	mkfifo("myfifo1", 0666);

    	fd = open("myfifoo", O_RDWR);

    	fd1 = open("myfifo1", O_RDWR);

        pthread_t sniffer_thread[2];

        if( pthread_create( &sniffer_thread[0] , NULL ,  connection_send, &fd) < 0)
        {
            perror("could not create thread");
            return 1;
        }

        if(pthread_create(&sniffer_thread[1] , NULL, connection_recv,&fd1) < 0)
        {
                perror("could not create thread2");
                return 1;
        }

       	while(1)
       	{
           	client_sock = accept(socket_desc,(struct sockaddr*)&client,(socklen_t*)&c);           
           	puts("Connection accepted");
           	printf("\n\n");

        	write(fd, &client_sock, sizeof(client_sock));

        	write(fd1, &client_sock, sizeof(client_sock));

		//     printf("%d:IP address is: %s\n",i,inet_ntoa(client.sin_addr));
		//printf("port is: %d\n", (int) ntohs(client_addr.sin_port));

		//        printf("Server side(sock desc):%d , pipe fd:%d\n",client_sock,fd);
    
    		//pthread_join(sniffer_thread[0],NULL);
    		//pthread_join(sniffer_thread[1],NULL); 

    		if (client_sock < 0)
    		{
        		perror("accept failed");
        		return 1;
    		}
       }
     	return 0;

}
void *connection_send(void *socket_desc)
{
  
    	//Get the socket descriptor
    	int sock = *(int*)socket_desc;
    	int n = 0,fd = 0 ,i =0, count = 0,cfd;
    	char sendBuff[100];
	//    char arr[] = "quit";
    	int res = 0;
    	char * tmp_buff;

       	int clientfd[10] = {0};
       	int sd = 0 , k = 0 ,l = 0;

       	fd_set readfds;

    	while(1)
        {
                FD_ZERO(&readfds);
                FD_SET(sock,&readfds);
        	FD_SET(0,&readfds);
        	//printf("Please enter your message:\n");

                fd = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);

                if (fd < 0)
                {
                    printf("select failed\n ");
                    exit(-1);
                }

                if(fd > 0)
                {        
             		if(FD_ISSET(sock, &readfds))
                        {
                                read(sock , &cfd , sizeof(cfd));
                                clientfd[count] = cfd;
                                count++;
                        }

                	printf("\n\n-------------------------------------------------------\n");
                	printf("Choose the descriptor from the following descriptors:\n");

                        for(i = 0;i < count;i++)
                        {
                               printf("client %d desriptor is '%d' \n",i,clientfd[i]);
                        }
                   
                        printf("-------------------------------------------------------\n\n");
	                printf("Now Please enter the client descriptor and then message:\n");
			printf("eg: 4 hello\n");

            		if(FD_ISSET(0,&readfds))    
            		{     
                            
                		printf("If you want to disconnect please enter 'end'\n");

                		fgets(sendBuff, 100 , stdin);
                    
                		printf("sendBuff:%s\n",sendBuff);

                		sd = sendBuff[0] - 48;
                	               		
				tmp_buff = &sendBuff[2];

                		printf("Before loop,sd : %d , sendbuff : %s \n",sd , sendBuff);
                
                		if((sd != -1) && (tmp_buff[0] != '\0' ))
                		{
                			for(i =0 ;i < count;i++)
                			{
                    				if(sd == clientfd[i])
                    				{
                        				printf("In loop,sd : %d sendBuff: %s \n",sd , tmp_buff);
                        
                                            		n = send(sd,tmp_buff,strlen(tmp_buff),0);

                        				res = strcmp(tmp_buff,"end\n");
                        
                        			//	printf("res:%d",res);

                                        		if((n == 0) || (res == 0)) 
                        				{
                            					printf("Client Disconnected : %d\n",sd);
    
                                             			int temp = 0 , j = i;
                                             			count = count-1;

                                             			while(j <= count)
                                              			{
                                                     		  	temp = clientfd[j];
                                                    			clientfd[j] = clientfd[j+1];
                                                     			clientfd[j+1] = temp;
                                                     			j++;
                                                  		}

                                              			close(sd);
                                             			// printf("%d\n",count);
                                              			clientfd[j] = 0;
                                            		}
            
                        				if(n < 0)
                                        		perror("send failed");
                        
                        				bzero(sendBuff,MAX_SIZE);
                    				}
                			}
                			
                		}
            		}
        	}

      }

      close(sock);
	pthread_exit(NULL);
    	pthread_detach(pthread_self());
    	return 0;
}

void *connection_recv(void *socket_desc)
{

    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int n = 0,fd = 0,i =0, count = 0,cfd;
    char client_message[2000];
  //  char arr[] = "quit";
    int clientfd[10] = {0};
    int sd = 0 , res = 0 ;

       fd_set readfds;

        while(1)
        {
                FD_ZERO(&readfds);
                FD_SET(sock,&readfds);

                for(i =  0; i < count ; i++)
                {
                    FD_SET(clientfd[i], &readfds);
                }

                fd = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);

                if (fd < 0)
                {
                    printf("select failed\n ");
                    exit(-1);
                }
        
        if(fd > 0)
                {
                        if(FD_ISSET(sock, &readfds))
                        {
                                read(sock , &cfd , sizeof(cfd));
                                clientfd[count] = cfd;
                                count++;
                        }
        
                        for(i = 0; i<count ; i++)
                        {
                            	sd = clientfd[i] ;
            			//    printf("%d\n",count);
                
                                if (FD_ISSET(sd, &readfds))
                                {
		                        n = recv(sd,client_message,2000,0);

                                    	printf("received from client descriptor (%d) : %s\n",sd,client_message);
                
                                                                
                      		    	res = strcmp(client_message,"end");
                    
                        
                                    	if((n==0) ||  (res == 0))
                                    	{
                                          	printf("Client Disconnected : %d\n",sd);
                 
                                          	int temp = 0 , j = i;
                          	     	  	count = count-1;

                                          	while(j <= count)
                                          	{
                                                	temp = clientfd[j];
                                                	clientfd[j] = clientfd[j+1];
                                                	clientfd[j+1] = temp;
                            				j++;
                                          	}

                          		  	close(sd);
                         		  	// printf("%d\n",count);
                          		  	clientfd[j] = 0;
                                    	}

                                    	if(n < 0)
                                    	perror("recv failed");

                                    	bzero(client_message,MAX_SIZE);

                		}

                        }
                }
    }

    close(sock);

    pthread_exit(NULL);
        pthread_detach(pthread_self());
    return 0;
}

