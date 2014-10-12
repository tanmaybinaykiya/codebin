/********************************************************
USAGE::
./a.out webUrl/lorem/ipsum 80
ie::  ./new www.whatsapp.com 80
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

#define WHITESPACE 64
#define EQUALS     65
#define INVALID    66
#define HTMLBUFFER 4000
 
	static const unsigned char d[] = {
		66,66,66,66,66,66,66,66,66,64,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
		66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,62,66,66,66,63,52,53,
		54,55,56,57,58,59,60,61,66,66,66,65,66,66,66, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,66,66,66,66,66,66,26,27,28,
		29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,66,66,
		66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
		66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
		66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
		66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
		66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
		66,66,66,66,66,66
	};

	void parse(char[]);
	void parseLocation(char []);
	void getImg(char imgUrl[],char cwd[], char fileName[]);
	char * removeHeader(char *replyStart);
	void parsecomplete(char []);
	int decodeNStore(char *,int);
    char * imgLocn;	
    int incomplete = 0;
	int inBlock=0;
	char host[200];
	char port[4];
	char *pageUrl;
	int base64ImgCount=00;
    char imgQuote[]="'";


int main(int argc, char* argv[]){
  
	struct addrinfo hints;
	struct addrinfo *serverInfo;  										// will point to the results
	int socket_desc;													// socket Descriptor
	int status;
	
	char server_reply[HTMLBUFFER+1];

	if(argc!=3){
	//	printf("FORMAT :: ./a.out HOST PORT");
		return 1;
	}

	//----------------------------------------------------------------seperate host from link
	
	// printf("HELLLLLLLLLLLO\n");
	pageUrl=strstr(argv[1],"/");
	// printf("HELLLLLLLLLLLO\n");
	
	if(pageUrl==NULL)
		strcpy(host,argv[1]);
	else
	{
		strncpy(host,argv[1],pageUrl-argv[1]);
		host[pageUrl-argv[1]]='\0';
	}
	
//	printf("PAGE URL %s\n",pageUrl );
//	printf("host %s\n",host );
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
	if (socket_desc == -1){
		printf("Could not create socket\n");
		exit(EXIT_FAILURE);
	}

	//------------------------------------------------------------------Connect to remote server using socket and server record

	if (connect(socket_desc ,  serverInfo->ai_addr, serverInfo->ai_addrlen)){
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
	strcat (message," HTTP/1.0\r\nHOST: ");
	strcat (message,host);
	strcat (message,"\r\n\r\n");
	//printf("\nGET REQUESt \n%s\n",message );


	if( send(socket_desc , message , strlen(message) , 0) < 0){
		printf("Send failed :");
		exit(EXIT_FAILURE);
	}
//printf("Data Sent\n---------\n");

	//-------------------------------------------------------------------Receive a reply from the server
	size_t rec_len=-1;
	if( (rec_len=recv(socket_desc, server_reply , HTMLBUFFER , 0)) < 0){
		printf("Receive failed");
		exit(EXIT_FAILURE);
	}

	FILE *htmlFile;
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout, "Current working dir: %s\n", cwd);
	else
	   perror("getcwd() error");

	strcat(cwd,"/");
	strcat(cwd,"index.html");
	int headerFlag=1;
	htmlFile=fopen(cwd,"w+");
//	printf("cwd: %s\n",cwd );
	char *headerEnd;
	headerEnd=strstr(server_reply,"\n\r\n")+3;

	do{
		server_reply[rec_len]='\0';
		
		if(headerFlag==1){
			// printf("SERVER REPLY:: \n%s\n",server_reply);
			fwrite((void*)headerEnd,sizeof(char),rec_len-(headerEnd-server_reply),htmlFile);	
			headerFlag=0;
		}
		else{
			fwrite((void*)server_reply,sizeof(char),rec_len,htmlFile);
		}
		
		printf("the value of incomplete is %d\n",incomplete);
		if(incomplete==1)
		 {  
		    printf("Calling parsecomplete\n");
		    parsecomplete(server_reply);
		  //  memset(server_reply,'\0',sizeof(server_reply));       
		    }
		else
		 parse(server_reply);
		 
		//printf("IM BACK BITCH!\n");
		memset(server_reply,'\0',sizeof(server_reply));

	}
	while( (rec_len=recv(socket_desc, server_reply , HTMLBUFFER , 0)) > 0);

	fclose(htmlFile);
	//--------------------------------------------------------------------CLOSE CONNECTION
	close(socket_desc);

	return 0;
}
void parsecomplete(char server_reply[])
{
  char 	  parseString[HTMLBUFFER+5],								// copy serverReply here
			 *imgptr=parseString,
			 *imgLinkEndPtr,											// if there is a ? in the img link	
			 *imgSrc;											// will point to end of img locn
			 												// will point to location of img

  printf("In parsecomplete--\nImage Quote %s\n",imgQuote);
  char *imgEndptr = strstr(server_reply,";");
  if(imgEndptr==NULL)
   imgEndptr = strstr(server_reply,imgQuote);
  if(imgEndptr!=NULL)
  {     
        int i=0;
        for(;i<=imgEndptr-server_reply;i++)
          printf("%c",server_reply[i]);
        printf("\n");  
        incomplete = 0; 
        int urlLength = strlen(imgLocn)+imgEndptr-server_reply;
        char *temp;
        temp =(char *)calloc(urlLength+2,sizeof(char));
        memset(temp,'\0',urlLength+2);
        printf("IMG LOCN parse comp %s\n-------------\n",imgLocn);
        strncat(temp,imgLocn,strlen(imgLocn));
        strncat(temp,server_reply,(imgEndptr-server_reply));
        imgLocn = temp;
         printf("IMG LOCN after manup parse comp %s\n-------------\n",imgLocn);																	// finds size of img url
		// printf("IMGSRC:: %s\n",imgSrc );
		printf("src in parsecomplete::  %s\n",imgLocn );
		imgptr=imgEndptr+1;
		assert(imgptr!=NULL);
		if (imgptr!=NULL){
			inBlock=0;
			char *base64=strstr(imgLocn,"data:image");
			if(base64!=NULL){
				printf("BASE64 FOUND\n");
				base64=strstr(base64,",")+1;
				// base64+=11;
				assert(base64!=NULL);

				int decodeStatus=decodeNStore(base64,urlLength);
				if(decodeStatus!=0){
					printf("DECODE ERROR\n");
				}
			}
			else{
				//DLD IF PNG IMAGE
				//for other formats only parse location shld wrk
				char *ext =(strstr(imgLocn,"."));
				if((strstr(ext,"png")!=NULL)||(strstr(ext,"PNG")!=NULL)){
					printf("IS PNG \n");
					parseLocation(imgLocn+1);
				}
			}
		}
		else{
			printf("imgptr==NULL\n");
		}
	
 
   printf("pasrse location for %s",imgLocn+1);
   
   parse(imgEndptr+1);
   }
   else
     strcat(imgLocn,server_reply); //entire buffer
  
}    
  
void parse(char serverReply[]){
	char 	  parseString[HTMLBUFFER+5],								// copy serverReply here
			 *imgptr=parseString,
			 *imgLinkEndPtr,											// if there is a ? in the img link	
			 *imgEndptr,
			 *imgSrc;											// will point to end of img locn
			 												// will point to location of img

	strcpy (parseString,serverReply);
	printf("\nPARSE--------------------------------------------------------------\n\n");

	while (    (     (imgptr=strstr(imgptr,"<img")) !=NULL)   && (inBlock==0 ) ){							// finds first instance of <img
		inBlock=1;
		int urlLength=0;
		
				
		imgSrc=strstr(imgptr,"src=");																		// finds locn of "src="
		imgSrc+=4;																							// moves ptr to end of "str='"
		strncpy(imgQuote,imgSrc,1);
		imgEndptr=strstr(imgSrc+1,imgQuote);
		if(imgEndptr==NULL)
		 {
		  printf("the image end in other packet\n");
		  printf(" get the url end from other packet and then continue\n");
		  incomplete = 1;
		  break;
		 }													// finds the end of img address ie finds the second quote
		//imgLinkEndPtr=strstr(imgSrc+1,"?");																	// finds if there is a ? in the img link
		urlLength=(imgEndptr-imgSrc);																		// finds size of img url
		imgLocn	=(char *)calloc(urlLength+2,sizeof(char));
		memset(imgLocn,'\0',urlLength+2);
		imgLocn=strncpy(imgLocn+1,imgSrc,urlLength);

		// printf("IMGSRC:: %s\n",imgSrc );
		printf("src::  %s\n",imgLocn+1 );
		imgptr=imgEndptr+1;
		assert(imgptr!=NULL);
		if (imgptr!=NULL){
			inBlock=0;
			char *base64=strstr(imgLocn,"data:image");
			if(base64!=NULL){
				printf("BASE64 FOUND\n");
				base64=strstr(base64,",")+1;
				// base64+=11;
				assert(base64!=NULL);

				int decodeStatus=decodeNStore(base64,urlLength);
				if(decodeStatus!=0){
					printf("DECODE ERROR\n");
				}
			}
			else{
				
					parseLocation(imgLocn+1);
				
			}
		}
		else{
			printf("imgptr==NULL\n");
		}
	}
	
}

void parseLocation(char imgLocn[]){
	
	printf("\n---------------------------------------\nParseLocn:: %s\n\n",imgLocn);

	char imgUrl[200];
	memset(imgUrl,'\0',sizeof(imgUrl));
	strcpy(imgUrl,imgLocn);

	char *dirStructure,*endptr,*oldEndPtr;
	dirStructure=imgLocn;
	

	if(strstr(dirStructure,"http")!=NULL){												// http://folder1/folder2/img.png
		dirStructure=strstr(dirStructure,"//")+1;
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

	//printf("\n---------------------------------------\ngetImg \n\timgUrl:: %s\n\tcwd:: %s\n\tfilename:: %s\n\n",imgUrl,cwd,fileName);

	//-------------------------REQUEST ---------------------------------------------
	char message[500] = "GET ";
	char hostUrl[300];
	memset(hostUrl,'\0',sizeof(hostUrl));
	char *temp;
	// printf("lalala000000\n");

	if(strstr(imgUrl,"http")!=NULL){
		// printf("lalalaif000000\n");
		imgUrl=strstr(imgUrl,"//")+2;
		temp=imgUrl;
		imgUrl=strstr(imgUrl,"/");
		strncpy(hostUrl,temp,(imgUrl-temp));
		// printf("IF line 301 img Url:: %s \n hostUrl :: %s \n",imgUrl, hostUrl);
		strcat(message,imgUrl);
	}
	else{
		// printf("lalalaelse000000\n");
		strcpy(hostUrl,host);

		if(pageUrl!=NULL)
			strcat(message,pageUrl);
		else
			strcat(message,"/");
		strcat(message,imgUrl+1);
	}

	// printf("lalala000001\n");

	strcat(message," HTTP/1.0\r\nHost: ");
	strcat(message,hostUrl);
	strcat(message,"\r\n\r\n");
	//printf("\n\n--------------------------------\nGET REQUEST::\n%s\n",message);
	// printf("lalala000002\n");

	//-------------------------FILE ---------------------------------------------
	
	FILE *img;
	strcat(cwd,fileName);
	img=fopen(cwd,  "w+");
	
	// HANDLE fileHandle = (HANDLE)_get_osfhandle(fileno(img));

	//-------------------------SOCKETS ---------------------------------------------
	// printf("lalala000003\n");
	
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
	if (socket_desc == -1){
		printf("Could not create socket");
		exit(EXIT_FAILURE);
	}

	//------------------------------------------------------------------Connect to remote server using socket and server record

	if (connect(socket_desc ,  serverInfo->ai_addr, serverInfo->ai_addrlen)){
		printf("connect error");
		exit(EXIT_FAILURE);
	}
	printf("Connected \n---------\n");

	if( send(socket_desc , message , strlen(message) , 0) < 0){
		printf("IMG Send failed :");
		exit(EXIT_FAILURE);
	}
	//printf("IMG REQUEST Sent\n");

	//-------------------------------------------------------------------Receive a reply from the server
	size_t rec_len=-1;
	char reply[500], *replyStart;
	replyStart=reply;
	int headerFlag=1;
	// printf("SIZE OF REPLY::%ld\n",sizeof(reply));
	memset (reply, '\0', sizeof(reply));

//	printf("IMG REPLY:: \n");
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
	
	fclose(img);
	printf("IMAGE WRITE SUCCESS\n---------------------------\n");
}

char* removeHeader(char *replyStart){
	
	char *pngStart;
	pngStart=strstr(replyStart,"\n\r\n")+3;
	assert(pngStart!=NULL);
	return pngStart;
}

int decodeNStore(char *in, int inLen){

	unsigned char *out;
	size_t outLen=3000;

	out=(char *)calloc(outLen,sizeof(char));
	
	char *end = in + inLen;
	size_t buf = 1, len = 0;
 
	while (in < end) {
		printf("WHILE\n");
		unsigned char c = d[*in++];
 
		switch (c) {
			case WHITESPACE: continue;   /* skip whitespace */
			case INVALID:    return 1;   /* invalid input, return error */
			case EQUALS:                 /* pad character, end of data */
				in = end;
				continue;

			default:
				buf = buf << 6 | c;
	 
				/* If the buffer is full, split it into bytes */
				if (buf & 0x1000000) {
					if ((len += 3) > outLen) return 1; /* buffer overflow */
					*out++ = buf >> 16;
					*out++ = buf >> 8;
					*out++ = buf;
					buf = 1;
			}   
		}
	}

	if (buf & 0x40000) {
		if ((len += 2) > outLen) return 1; 						/* buffer overflow */
		*out++ = buf >> 10;
		*out++ = buf >> 2;
	}
	else if (buf & 0x1000) {
		if (++len > outLen) return 1; 							/* buffer overflow */
		*out++ = buf >> 4;
	}

	outLen = len; 												/* modify to reflect the actual output size */

	char cwd[1024];												//CURRENT WORKING DIRECTORY
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout, "Current working dir: %s\n", cwd);
	else
	   perror("getcwd() error");


	FILE *img;
	char fname[12]="base64img";
	char num[2];
	num[0]=(char)(((int)'0')+base64ImgCount/10);
	num[1]=(char)(((int)'0')+base64ImgCount%10);

	strcat(fname,num);
	strcat(cwd,"/");
	strcat(cwd,fname);
	strcat(cwd,".png");

	img=fopen(cwd,  "w+");
	
	fwrite((void*)out,sizeof(unsigned char),outLen,img);	
	fclose(img);
	return 0;
}