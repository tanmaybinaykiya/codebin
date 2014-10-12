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

void getImg(char imgUrl[],char cwd[],char fileName[]){
	struct addrinfo hints;			
	struct addrinfo *serverInfo;  										// will point to the results
	int socket_desc;													// socket Descriptor
	int status;
	char port[4]="80";

	printf("\n---------------------------------------\ngetImg \n\timgUrl:: %s\n\tcwd:: %s\n\tfilename:: %s\n\n",imgUrl,cwd,fileName);

//-------------------------REQUEST ---------------------------------------------
	char message[500] = "GET ";
	char hostUrl[300];
	char *temp;
	
	imgUrl=strstr(imgUrl,"/")+1;
	imgUrl=strstr(imgUrl,"/")+1;
	temp=imgUrl;
	imgUrl=strstr(imgUrl,"/");
	strncpy(hostUrl,temp,(imgUrl-temp));

	strcat(message,imgUrl);
	strcat(message," HTTP/1.0\r\nHost: ");
	strcat(message,hostUrl);
	strcat(message,"\r\n\r\n");
	printf("\n\n--------------------------------\nGET REQUEST::\n%s\n",message);
	


//-------------------------FILE ---------------------------------------------
	FILE *img;
	strcat(cwd,fileName);
	img=fopen(cwd,  "w+");
	// HANDLE fileHandle = (HANDLE)_get_osfhandle(fileno(img));

//-------------------------SOCKETS ---------------------------------------------
	memset(&hints, 0, sizeof hints); 									// make sure the struct is empty
	hints.ai_family = AF_INET;     										// don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; 									// TCP stream sockets

	//-------------------------------------------------------------------GET ADDR INFO

	status = getaddrinfo(hostUrl, port, &hints, &serverInfo);
	if(status!=0){

		printf("Could Not Get AddrInfo Error:: %s\n",gai_strerror(status));
		exit(EXIT_FAILURE);
	}
	
	//------------------------------------------------------------------Create socket
	

	socket_desc = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
		exit(EXIT_FAILURE);
	}


	//------------------------------------------------------------------Connect to remote server using socket and server record

	if (connect(socket_desc ,  serverInfo->ai_addr, serverInfo->ai_addrlen))
	{
		printf("connect error");
		exit(EXIT_FAILURE);
	}
	printf("Connected \n---------\n");



	if( send(socket_desc , message , strlen(message) , 0) < 0)
	{
		printf("IMG Send failed :");
		exit(EXIT_FAILURE);
	}
	printf("IMG Data Sent\n");

	//-------------------------------------------------------------------Receive a reply from the server
	size_t rec_len=-1;
	char reply[1024];
	memset (reply, '\0', sizeof(reply));


	printf("IMG REPLY:: ");
	while( (rec_len=recv(socket_desc,reply , 1024 , 0)) > 0){

		//write to disk
		printf("\n%s\n",reply);
		// reply=strstr(reply,"");
		if (img!=NULL)
		{	
			// fputs(reply,img);
			// fwrite ( (void *) reply, sizeof(char), (1024/sizeof(char)), img );
			fwrite((void*)reply,sizeof(char),1024,img);
	  	}
	  	memset (reply, '\0', sizeof(reply));
	}
	if( rec_len<= 0)
	{
		printf("IMG Receive failed");
		exit(EXIT_FAILURE);
	}
	
	fclose(img);
}