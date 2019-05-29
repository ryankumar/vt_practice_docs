#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "CreatTcpSocket.c"
#include "AcceptTcpConnection.c"
void ProcessMain(int servSock);      /* Main program of process */
#define RCVBUFSIZE 32   /* Size of receive buffer */
void HandleTCPClient(int clntSocket)
{
	char echoBuffer[RCVBUFSIZE];        /* Buffer for echo string */
	int recvMsgSize;                    /* Size of received message */
	/* Receive message from client */
	if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
		DieWithError("recv() failed");
	/* Send received string and receive again until end of transmission */
	while (recvMsgSize > 0)      /* zero indicates end of transmission */
	{
		/* Echo message back to client */
		if (send(clntSocket, echoBuffer, recvMsgSize, 0) != recvMsgSize)
			DieWithError("send() failed");
		/* See if there is more data to receive */
		if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
			DieWithError("recv() failed");
	}
	close(clntSocket);    /* Close client socket */
}

void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}

int main(int argc, char *argv[]) 
{
	int servSock;                    /* Socket descriptor for server*/
	unsigned short echoServPort;     /* Server port */
	pid_t processID;                 /* Process ID */
	unsigned int processLimit;       /* Number of child processes to create */
	unsigned int processCt;          /* Process counter */
	if (argc != 3) {     /* Test for correct number of arguments */
		fprintf(stderr,"Usage:  %s <SERVER PORT> <FORK LIMIT>\n", argv[0]);
		exit(1);
	}
	echoServPort = atoi(argv[1]);  /* First arg: local port */
	processLimit= atoi(argv[2]);  /* Second arg:  number of child processes */
	servSock = CreateTCPServerSocket(echoServPort);
	for (processCt=0; processCt< processLimit; processCt++)
	if ((processID = fork()) < 0) DieWithError("fork() failed");    /* Fork child process */
	else if (processID == 0) ProcessMain(servSock); 
	/* If this is the child process */
	exit(0);  /* The children will carry on */
}
void ProcessMain(int servSock) {
	int clntSock;                  /* Socket descriptor for client connection */	
	for (;;) { /* Run forever */ 
	clntSock = AcceptTCPConnection(servSock);
	printf("with child process: %d\n", (unsigned int) getpid());
	HandleTCPClient(clntSock);
	}
}
