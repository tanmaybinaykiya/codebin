#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>  // for struct sockaddr_in AF_IN
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>  // for inet_pton
#include <netinet/in.h> // for IPPROTO_TCP

#define PORT "80"
#define BAIDU_IP "119.75.217.56"
// #define GET_INFO "GET / HTTP/1.1\r\nHost: www.google.com:80\r\n\r\n"

int main(int argc, char *argv[])
{
	if (argc != 2) {
        fprintf(stderr,"usage: client \n");
        return 1;
    }

	int sock_local;
	in_port_t port = atoi(PORT);
	struct sockaddr_in server;

	char getInfo[150];
	strcpy (getInfo,"GET / HTTP/1.1\r\nHost: ");
	strcat(getInfo,argv[1]);
	strcat(getInfo,":80\r\n\r\n");

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(port);		//Big endian small endian   host to network 

	sock_local = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	assert(sock_local > 0);

	int retVal = -1;
	retVal = inet_pton(AF_INET, BAIDU_IP, &server.sin_addr.s_addr);
	assert(retVal == 1);

	if (connect(sock_local, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}

	ssize_t nByte = send(sock_local, getInfo, strlen(getInfo), 0);
	if( nByte <= 0)
	{
		perror("send");
		exit(EXIT_FAILURE);
	}

	char BUF[BUFSIZ];
	size_t recived_len = 0;
	while ((recived_len = recv(sock_local, BUF, BUFSIZ-1, 0)) > 0)
	{
		int statu;
		BUF[recived_len] = '\0';
		printf("%s", BUF);
		statu = (recived_len==BUFSIZ-1) ? 0 : 1;
	}
	if (recived_len < 0)
	{
		perror("recv");
	}

	close(sock_local);
	return 0;
}