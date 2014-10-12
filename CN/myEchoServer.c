#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
int main(int argc, char *argv[]){


/*
	int getaddrinfo(const char *node,    			// e.g. "www.example.com" or IP
	const char *service,  							// e.g. "http" or port number
	const struct addrinfo *hints,
	struct addrinfo **res);							// will point to the results
*/
	if (argc != 2) {
       fprintf(stderr,"usage %s port\n", argv[0]);
       exit(0);
    }
    // int portNo=atoi(argv[2]);
	int status;
	struct addrinfo hints, *res;  					

	memset(&hints, 0, sizeof hints); 				// make sure the struct is empty
	hints.ai_family = AF_INET;     					// don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; 				// TCP stream sockets
	hints.ai_flags = AI_PASSIVE;     				// fill in my IP for me

	status = getaddrinfo(NULL, argv[2], &hints, &res);

	if (status==-1) {
		fprintf(stderr, "Getaddrinfo error: %s\n", gai_strerror(status));
		return(1);
	}
	
	int sock= socket(res->ai_family, res->ai_socktype, res->ai_protocol);				//int socket(int domain, int type, int protocol);  
	if (sock==-1){
		fprintf(stderr, "Socket error: %s\n", strerror(sock));
		return(1);
	}

	int conn =bind(sock, res->ai_addr, res->ai_addrlen);								//int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);

	listen(sock,5); 																	//int listen(int sockfd, int backlog /*NO OF CONNECTIONS*/; 
	


	struct sockaddr_storage their_addr;
	socklen_t addr_size = sizeof (their_addr);

	int new_fd = accept(sock, (struct sockaddr *)&their_addr, &addr_size);
	if(new_fd<0){
		fprintf(stderr, "accept error: %s\n", strerror(new_fd));
		return(1);
	}

	char buffer[256];
	bzero(buffer,256);

	int n = read(new_fd,buffer,255);
	
	if (n < 0) 
		error("ERROR reading from socket");
	
	printf("Client: %s\n",buffer);
	n = write(new_fd,buffer,255);
	
	if (n < 0) 
		error("ERROR writing to socket");

	close(new_fd);
    close(sock);

	return 1;

}