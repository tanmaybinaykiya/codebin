// TCP client Code. Before running this code, make sure that server code is running and is listening to port 5000
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main()

{
	int sock_ctrl,sock_data, bytes_received,ctrlno,i;  
	char send_data[1024],recv_data[1024],ctrl[10], filename[20],path[50];
	struct hostent *host;
	struct sockaddr_in server_ctrl_addr,server_data_addr;  

	host = gethostbyname("127.0.0.1"); //self loop IP

	if ((sock_ctrl= socket(AF_INET, SOCK_STREAM, 0)) == -1) { 
		perror("Socket");
		exit(1);
	}
	
	server_ctrl_addr.sin_family = AF_INET;     
	server_ctrl_addr.sin_port = htons(7432);    // control Port to connect to server
	server_ctrl_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(server_ctrl_addr.sin_zero),8);
	
	server_data_addr.sin_family = AF_INET;     
	server_data_addr.sin_port = htons(7433);    // data Port to connect to server
	server_data_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(server_data_addr.sin_zero),8); 
	
	//control connection
	if (connect(sock_ctrl, (struct sockaddr *)&server_ctrl_addr,sizeof(struct sockaddr)) == -1) 
	{
		perror("control Connect");
		exit(1);
	} 
	
	while(1)
	{
		printf("\n\nUser have following options:LIST  ULOAD  DLOAD  DEL  CHNG MAKE QUIT\n");
		printf("Type any of the above commands:");
		
		gets(ctrl);
		
		if(strcmp(ctrl,"LIST")==0)
		{
			ctrlno=0;	
		}
		else if(strcmp(ctrl,"ULOAD")==0)
		{
			ctrlno=1;	
		}
		else if(strcmp(ctrl,"DLOAD")==0)
		{
			ctrlno=2;	
		}
		else if(strcmp(ctrl,"DEL")==0)
		{
			ctrlno=3;	
		}
		else if(strcmp(ctrl,"CHNG")==0)
		{
			ctrlno=4;	
		}
		else if(strcmp(ctrl,"MAKE")==0)
		{
			ctrlno=5;	
		}
		else
		{
			ctrlno=6;	
		}
		
			
		if(strcmp(ctrl,"LIST")==0||strcmp(ctrl,"ULOAD")==0||strcmp(ctrl,"DLOAD")==0||strcmp(ctrl,"DEL")==0||strcmp(ctrl,"CHNG")==0||strcmp(ctrl,"QUIT")==0||strcmp(ctrl,"MAKE")==0 )
		{
			send(sock_ctrl,ctrl,strlen(ctrl), 0); 
			//establish data connection
			if ((sock_data= socket(AF_INET, SOCK_STREAM, 0)) == -1) { 
			perror("Socket");
			exit(1);
			}
			if(connect(sock_data, (struct sockaddr *)&server_data_addr,sizeof(struct sockaddr)) == -1) 
			{
				perror("data Connect");
				exit(1);
			}
		
			switch(ctrlno)
			{
				case 0: //strcpy(bytes_received,"\0");
						bytes_received = recv(sock_data,recv_data,1024,0);
						recv_data[bytes_received] = '\0';
						printf("\n%s\n", recv_data); 
						break;
					
				case 1:
						printf("Give the name of the file to upload:");
						gets(filename);
						send(sock_data,filename,strlen(filename), 0);
						FILE *fp;
						if((fp = fopen(filename, "r")) == NULL)
						{
							printf("\nFile is not found in the curent directory,Upload not succesful\n");
							send(sock_data,"NF",strlen("NF"), 0);
						}
						else
						{
							i=0;
							while((send_data[i]=fgetc(fp))!=EOF)
							{
								i++;
							}
							send_data[i]='\0';
							fclose(fp);
							send(sock_data,send_data,strlen(send_data), 0);
						} 
						break;
				case 2:
						printf("Give the name of the file to download:");
						gets(filename);
						send(sock_data, filename, strlen(filename), 0);
						bytes_received = recv(sock_data, recv_data, 1024, 0);
						recv_data[bytes_received] = '\0';
						if(strcmp(recv_data,"NF")==0)
						{
							printf("\nFile not found in the server,Download not succesfull\n");
						}
						else
						{
							FILE *fp1;
							fp1 = fopen(filename, "w");
							fprintf(fp1, "%s", recv_data);
							fclose(fp1);
							printf("File has been succesfully downloaded\n");
						}
						break;
				case 3:
						printf("Give the name of the file to be deleted:");
						gets(filename);
						send(sock_data,filename,strlen(filename),0);
						break;
				case 4:
				  		printf("Give the path to change directory:");
				  		gets(path);
				  		send(sock_data,path,strlen(path),0);
				  		break;
				case 5:
						printf("Give the path to create the Directory:");
						gets(path);
						send(sock_data,path,strlen(path),0);
				  		break;
				case 6:
						close(sock_data);
						close(sock_ctrl);
						exit(1);								  									
			}      
			close(sock_data);
		}	
		else
		{
			printf("INVALID COMMAND\n");
		}	
	}   
	return 0;
}
