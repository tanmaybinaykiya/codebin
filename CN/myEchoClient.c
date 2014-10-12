#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]){
	if (argc != 3) {
		fprintf(stderr,"usage %s hostname port\n", argv[0]);
		return 0;
	}
	// portno = atoi(argv[2]);

	int status;
	struct addrinfo hints, *res;  					

	memset(&hints, 0, sizeof hints); 				// make sure the struct is empty
	hints.ai_family = AF_INET;     					// don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; 				// TCP stream sockets
	hints.ai_flags = AI_PASSIVE;     				// fill in my IP for me

	status = getaddrinfo(NULL, argv[2], &hints, &res);

	if (status==-1) {
		printf("Getaddrinfo error: %s\n", gai_strerror(status));
		return 1;
	}
	
	int sock= socket(res->ai_family, res->ai_socktype, res->ai_protocol);				//int socket(int domain, int type, int protocol);  
	if (sock==-1){
		printf("Socket error: %s\n", strerror(gerror));
		return 1;
	}

	struct hostent *server;
	server=gethostbyname(argv[1]);
	
	if (server == NULL) {
		printf("ERROR, no such host\n");
		return 0;
	}

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");


    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    close(sockfd);

    return 0;
}