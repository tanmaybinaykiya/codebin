/********************************************************
Assumption ./a.out webUrl/lorem/ipsum 80
./new www.whatsapp.com 80
The first eight bytes of a PNG datastream always contain the following (decimal) values:
   137 80 78 71 13 10 26 10
********************************************************/


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

	void parse(char[]);
	void parseLocation(char []);
	void getImg(char imgUrl[],char cwd[], char fileName[]);
	char * removeHeader(char *replyStart);

	int inBlock=0;
	char host[200];
	char port[4];
	char *pageUrl;

int main(int argc, char* argv[]){
	struct addrinfo hints;
	struct addrinfo *serverInfo;  										// will point to the results
	int socket_desc;													// socket Descriptor
	int status;
	

	char server_reply[2000];

	if(argc!=3){
		printf("FORMAT :: ./a.out HOST PORT");
		return 1;
	}

	//----------------------------------------------------------------seperate host from link
	
	// printf("HELLLLLLLLLLLO\n");

	pageUrl=strstr(argv[1],"/");
	// printf("HELLLLLLLLLLLO\n");
	
	if(pageUrl==NULL){
		strcpy(host,argv[1]);
	}
	else{
		strncpy(host,argv[1],pageUrl-argv[1]);
		host[pageUrl-argv[1]]='\0';
	}
	printf("PAGE URL %s\n",pageUrl );
	printf("host %s\n",host );
	strcpy(port,argv[2]);
	//------------------------------------------------------------------getHostByName
	
	memset(&hints, 0, sizeof hints); 									// make sure the struct is empty
	hints.ai_family = AF_INET;     										// don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; 									// TCP stream sockets

	//-------------------------------------------------------------------GET ADDR INFO

	status = getaddrinfo(host, port, &hints, &serverInfo);
	if(status!=0){
		printf("Could Not Get AddrInfo:: %s\n", gai_strerror(status));
		exit(EXIT_FAILURE);
	}
	
	//------------------------------------------------------------------Create socket
	

	socket_desc = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);
	if (socket_desc == -1)
	{
		printf("Could not create socket\n");
		exit(EXIT_FAILURE);
	}


	//------------------------------------------------------------------Connect to remote server using socket and server record

	if (connect(socket_desc ,  serverInfo->ai_addr, serverInfo->ai_addrlen))
	{
		printf("connect error\n");
		exit(EXIT_FAILURE);
	}
	printf("Connected \n---------\n");

	//-------------------------------------------------------------------Send some data

	// char message[] = "GET / HTTP/1.1\r\nHost: \r\n\r\n";


	char message[500] = "GET ";
	if(pageUrl!=NULL){
		strcat (message,pageUrl);
	}
	else{
		strcat (message,"/");
	}
	strcat (message," HTTP/1.1\r\nHOST: ");
	strcat (message,host);
	strcat (message,"\r\n\r\n");
	printf("\nGET REQUESt \n%s\n",message );


	if( send(socket_desc , message , strlen(message) , 0) < 0)
	{
		printf("Send failed :");
		exit(EXIT_FAILURE);
	}
	printf("Data Sent\n---------\n");

	//-------------------------------------------------------------------Receive a reply from the server
	size_t rec_len=-1;
	if( (rec_len=recv(socket_desc, server_reply , 2000 , 0)) < 0)
	{
		printf("Receive failed");
		exit(EXIT_FAILURE);
	}

	do{
		server_reply[rec_len]='\0';
		// printf("SERVER REPLY:: \n%s\n",server_reply);
		parse(server_reply);	
	}
	while( (rec_len=recv(socket_desc, server_reply , 2000 , 0)) > 0);

	//--------------------------------------------------------------------CLOSE CONNECTION
	close(socket_desc);

	return 0;
}

void parse(char serverReply[]){
	char 	  parseString[2005],		//copy serverReply here
			 *imgptr=parseString,		
			 *imgEndptr,				//will point to end of img locn
			 *imgSrc;					//will point to location of img

	strcpy (parseString,serverReply);
	printf("\nPASS--------------------------------------------------------------\n\n");

	while (    (     (imgptr=strstr(imgptr,"<img")) !=NULL)   && (inBlock==0 ) ){							// finds first instance of <img
		inBlock=1;
		int urlLength=0;
		char *imgLocn, imgQuote[]="'";
				
		imgLocn	=(char *)calloc(100,sizeof(char));
		imgSrc=strstr(imgptr,"src=");																		// finds locn of "src="
		imgSrc+=4;																							// moves ptr to end of "str='"
		strncpy(imgQuote,imgSrc,1);
		imgEndptr=strstr(imgSrc+1,imgQuote);																	// finds the end of img address
		// printf("\n-----------------------\nINBLOCK 1.5\n imgSrc :%s \n imgEND :%s \n",imgSrc,imgEndptr);
		urlLength=(imgEndptr-imgSrc);																		// finds size of img url
		// printf("\n-----------------------\nINBLOCK2\n l=%d , imgendptr : %s  \n",urlLength,imgEndptr);
		imgLocn=strncpy(imgLocn+1,imgSrc,urlLength);
		// printf("IMGSRC:: %s\n",imgSrc );
		// printf("IMGLOCN::  %s\n",imgLocn );



		imgptr=strstr(imgptr,"/>")+2;

		if (imgptr!=NULL){
			inBlock=0;
			//DLD IF PNG IMAGE
			char *ext =(strstr(imgLocn,"."));
			if((strstr(ext,"png")!=NULL)||(strstr(ext,"PNG")!=NULL)){
				printf("IS PNG \n");
				parseLocation(imgLocn+1);
			}

		}
		
	}

}
void parseLocation(char imgLocn[]){
	printf("\n---------------------------------------\nParseLocn:: %s\n\n",imgLocn);


	char imgUrl[200];
	strcpy(imgUrl,imgLocn);

	char *dirStructure,*endptr,*oldEndPtr;
	dirStructure=imgLocn;
	if(*dirStructure!='/'){
		dirStructure=strstr(dirStructure,"/")+1;
		dirStructure=strstr(dirStructure,"/")+1;
		dirStructure=strstr(dirStructure,"/")+1;
		printf("Directory Structure: /%s\n",dirStructure);
	}
	else {
		dirStructure++;
		printf("Directory Structure: /%s\n",dirStructure);
	}
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout, "Current working dir: %s\n", cwd);
	else
	   perror("getcwd() error");


	endptr=strtok(dirStructure,"/");
	while(endptr!=NULL){
		char *temp;
		temp=strstr(endptr,".");
		// printf("temp :: %s\n",temp);
		if(temp!=NULL && strstr(temp,"/")==NULL){

			// printf("END FOUND\t Breaking Bad! \nFile name :: %s\n",endptr);
			break;
		}
		// printf ("CURR TOKEN:: %s\n",endptr);
		strcat(cwd,"/");
		strcat(cwd,endptr);
		printf ("Dir to be created %s\n",cwd);
		struct stat st = {0};
		if (stat(cwd, &st) == -1) {
			printf("\tDirectory Does not exist, CREATING \n");
			if(mkdir(cwd, 0700)==-1){
				int err=errno;
				perror("\tMKDIR ERROR");
				printf("%s \n",strerror(err));
			}
		}
		else{
			printf("\tDirectory already exists \n");
		}
		endptr = strtok (NULL, "/");	
	}
	strcat(cwd,"/");
	// printf("finally at %s\n",cwd);

	getImg(imgUrl,cwd,endptr);
}

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

	printf("HIIIIIIIIIIIIIIIIII1\n");

	if(imgUrl[0]!='/'){
		imgUrl=strstr(imgUrl,"/")+1;
		imgUrl=strstr(imgUrl,"/")+1;
		temp=imgUrl;
		imgUrl=strstr(imgUrl,"/");
		strncpy(hostUrl,temp,(imgUrl-temp));
		strcat(message,imgUrl);
	}
	else{
		strcpy(hostUrl,host);

		if(pageUrl!=NULL)
			strcat(message,pageUrl);
		else
			strcat(message,"/");
		strcat(message,imgUrl+1);
	}
	
	strcat(message," HTTP/1.0\r\nHost: ");
	printf("EIIIIIIIIIIIIIIIIII1\n");
	strcat(message,hostUrl);
	printf("EIIIIIIIIIIIIIIIIII1\n");
	strcat(message,"\r\n\r\n");
	printf("EIIIIIIIIIIIIIIIIII1\n");
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
	char reply[1024], *replyStart;
	replyStart=reply;
	int headerFlag=1;
	// printf("SIZE OF REPLY:::::::::::::::::::::::::::::::::::::::::::::::::::::: %ld\n",sizeof(reply));
	memset (reply, '\0', sizeof(reply));


	printf("IMG REPLY:: \n");
	while( (rec_len=recv(socket_desc,reply , sizeof(reply) -1, 0)) > 0){
		// printf("\n%s\n",reply);
		if(headerFlag==1){
			replyStart=reply;
			if(strstr(reply,"HTTP/1.0 404 Not Found")!=NULL ){
				fclose(img);
				break;
			}
			replyStart=removeHeader(replyStart);
			if(replyStart==NULL){

				printf("\n%s\n",reply);
				printf("replyStart NULL\n");
				break;
			}
		}
		
		if (img!=NULL)
		{	
			if(headerFlag==1){
				fwrite((void*)replyStart,sizeof(char),rec_len-(replyStart-reply),img);
				headerFlag=0;
			}
			else{
				fwrite((void*)reply,sizeof(char),rec_len,img);
			}
	  	}
	  	memset (reply, '\0', sizeof(reply));
	}

	if( rec_len==-1)
	{
		printf("IMG Receive failed %s",strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("IMAGE WRITE SUCCESS\n");
	fclose(img);
}



char* removeHeader(char *replyStart){
	
/*The first eight bytes of a PNG datastream always contain the following (decimal) values:
137 80 78 71 13 10 26 10
*/
	uint arr[]={137,80,78,71,13,10,26,10};
	char *pngStart;
	pngStart=strstr(replyStart,(char *)&arr[0]);
	

	return pngStart;
}