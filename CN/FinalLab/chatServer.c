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
int clientFd[BACKLOG];
int noOfConns=0;


void * threadFunc(void * ptr);	

int main(int argc, char* argv[]){

	struct addrinfo hints;
	struct addrinfo *serverInfo;  										// will point to the results
	int socketDesc,bindStatus;										// socket Descriptor
	int status,listenStatus;
	
	struct sockaddr *host;
	socklen_t addrSize;
	struct sockaddr_storage clientAddr;

	pthread_t threads[BACKLOG];
	int threadRet[BACKLOG];
	
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

	bindStatus=bind(socketDesc, serverInfo->ai_addr, serverInfo->ai_addrlen);
	if (bindStatus == -1){
		// printf("Could not bind\n");
		perror("Bind Failed");
		exit(EXIT_FAILURE);
	}
	printf("Ready to listen... \n---------\n");

	//------------------------------------------------------------------Listen

	listenStatus=listen(socketDesc, BACKLOG);
	if (listenStatus == -1){
		perror("Listen");
		exit(EXIT_FAILURE);
	}
	printf("Listening, Ready to accept... \n---------\n");

	addrSize=sizeof (clientAddr);
	int i;

	for(i=0;i<BACKLOG;i++){
		clientFd[i]=accept(socketDesc,(struct sockaddr *)&clientAddr, &addrSize);
		noOfConns++;
		threadRet[i]=pthread_create( &threads[i], NULL, threadFunc, (void*)clientFd[i]);
		printf("Thread Created %d\n",threads[i] );

		if(threadRet[i]){
			printf("Error - pthread[%d]_create() return code: %u\n",i,threadRet[i]);
			exit(EXIT_FAILURE);
		}
	}

	// for(i=0;i<BACKLOG;i++){
	// 	pthread_join( threadRet[i], NULL);
	// }

	close(socketDesc);
	return 0;
}

void * threadFunc(void *ptr){
	int thr;
	thr = (int *) ptr;
	printf("Accepted... %d \n---------\n",thr);
	int rec_len=0,i;
	char *buffer;

	buffer=(char *)calloc(BUFFERSIZE,sizeof(char));
	strcpy(buffer,"Client");
	char *c;
	c=(char *)calloc(2,sizeof(char));
	c[0]='0';
	c[0]+=thr;
	strcat(buffer,c);
	strcat(buffer," : ");
	while (1){
		rec_len=recv(thr, buffer+10, BUFFERSIZE-10 , 0);
		if (rec_len>0){
			//send to all 
			for(i=0;i<noOfConns;i++){
				if (clientFd[i]!=thr){
					if( send(clientFd[i] , buffer , rec_len+10, 0) < 0){
						printf("Send failed :");
						exit(EXIT_FAILURE);
					}
					else{
						printf("SENT %d\n",i);
					}
				}
			}
		}
	}
	// close(thr);
	// pthread_exit();
}