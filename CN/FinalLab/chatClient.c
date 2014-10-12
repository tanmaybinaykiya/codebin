// CLIENT1 is the server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>    											
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h> 													// inet_addr
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>  

#define BACKLOG 5
#define BUFFERSIZE 250

struct someStruct{
	int mySock;
	int *clients;
}typedef sockDescriptor;

char port[4];

void * recvFunc(void *ptr);	
void * sendFunc(void *ptr);	

int main(int argc, char* argv[]){

	struct addrinfo hints;
	struct addrinfo *serverInfo;  										// will point to the results
	int socketDesc,bindStatus;										// socket Descriptor
	int status,listenStatus;
	
	struct sockaddr *host;
	socklen_t addrSize;

	pthread_t threadrecv,threadsend;

	if(argc!=2){
		printf("FORMAT :: ./a.out PORT");
		return 1;
	}

	strcpy(port,argv[1]);

	//------------------------------------------------------------------getHostByName
	
	memset(&hints, 0, sizeof hints); 									// make sure the struct is empty
	hints.ai_family = AF_INET;     										// don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; 									// TCP stream sockets
	hints.ai_flags= AI_PASSIVE;											// localhost

	//-------------------------------------------------------------------GET ADDR INFO

	status = getaddrinfo(NULL, port, &hints, &serverInfo);
	if(status!=0){
		printf("Could Not Get AddrInfo:: %s\n", gai_strerror(status));
		exit(EXIT_FAILURE);
	}
	
	//------------------------------------------------------------------Create socket

	socketDesc = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);
	if (socketDesc == -1){
		perror("Socket Creation Failed");
		exit(EXIT_FAILURE);
	}

	//------------------------------------------------------------------Bind socket to port

	if (connect(socketDesc ,  serverInfo->ai_addr, serverInfo->ai_addrlen))
	{
		printf("connect error\n");
		exit(EXIT_FAILURE);
	}
	printf("Connected \n---------\n");

	//------------------------------------------------------------------Listen

	int recvRet=pthread_create( &threadrecv, NULL, recvFunc,(void *)socketDesc);
	int sendRet=pthread_create( &threadsend, NULL, sendFunc,(void *)socketDesc);

	while(1){
		;
	}

	close(socketDesc);
	return 0;
}

void * sendFunc(void *ptr){

	int desc;
	desc = (int *) ptr;
	char *buffer;
	buffer=(char *)calloc(BUFFERSIZE,sizeof(char));
	while (1){
		fgets(buffer,BUFFERSIZE,stdin);
		if(send(desc , buffer , strlen(buffer), 0) < 0){
			printf("Send failed :");
			exit(EXIT_FAILURE);
		}
	}
}

void * recvFunc (void *ptr){
	int desc;
	desc = (int *) ptr;
	int rec_len;
	char *buffer;
	buffer=(char *)calloc(BUFFERSIZE,sizeof(char));
	while(1){	
		rec_len=recv(desc, buffer, BUFFERSIZE , 0);
		if(rec_len>0)
			printf("%s\n",buffer );
	}
}