// TCP server Code. First Run this code and make it listen to the port number 5000.

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main()
{
	int sock_ctrl,sock_data, ctrlconnected,dataconnected,bytes_received ,ctrl_received,ctrlno, true = 1,filename_size,path_size;
	int i;
	char send_data[1024] , recv_data[1024],ctrl[10], filename[20],path[50];
	pid_t pid;       
	
	char *serverhomepath=getcwd(NULL,0);
	//printf("%s",serverhomepath);
	struct sockaddr_in server_ctrl_addr,server_data_addr,client_addr;    
	int sin_size;

	if ((sock_ctrl = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}
	
	if ((sock_data = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}
	
	if (setsockopt(sock_ctrl,SOL_SOCKET,SO_REUSEADDR,&true,sizeof(int)) == -1) {
		perror("Setsockopt");
		exit(1);
	}
	
	if (setsockopt(sock_data,SOL_SOCKET,SO_REUSEADDR,&true,sizeof(int)) == -1) {
		perror("Setsockopt");
		exit(1);
	}
	
	server_ctrl_addr.sin_family = AF_INET;    //IPv4 Protocol     
	server_ctrl_addr.sin_port = htons(7432);   // Port number  
	server_ctrl_addr.sin_addr.s_addr = INADDR_ANY; 
	bzero(&(server_ctrl_addr.sin_zero),8);
	
	server_data_addr.sin_family = AF_INET;    //IPv4 Protocol     
	server_data_addr.sin_port = htons(7433);   // Port number  
	server_data_addr.sin_addr.s_addr = INADDR_ANY; 
	bzero(&(server_data_addr.sin_zero),8); 

	if (bind(sock_ctrl, (struct sockaddr *)&server_ctrl_addr, sizeof(struct sockaddr)) // bind a name 
		                == -1) {
		perror("Unable to bind to control port");
		exit(1);
	}
	
	if (bind(sock_data, (struct sockaddr *)&server_data_addr, sizeof(struct sockaddr)) // bind a name 
		                == -1) {
		perror("Unable to bind for data port");
		exit(1);
	}
	
	if (listen(sock_ctrl, 5) == -1) { // listening to control socket port #
		perror("control Listen");
		exit(1);
	}
	
	if (listen(sock_data, 5) == -1) 
	{ // listening to a data port #
		perror("Listen");
		exit(1);
	}
	
	while(1)
	{
		printf("\nFTPServer Waiting for client on control port 7432"); 
		fflush(stdout);
		
		sin_size = sizeof(struct sockaddr_in);
		
		ctrlconnected = accept(sock_ctrl, (struct sockaddr *)&client_addr,&sin_size);		
		printf("\n I got a control connection from (%s , %d)\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		
		while (1)
		{	
			ctrl_received = recv(ctrlconnected,ctrl,10,0);
			ctrl[ctrl_received] = '\0';
			  		
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
		
	
			dataconnected = accept(sock_data, (struct sockaddr *)&client_addr,&sin_size);

			printf("\n I got a data connection from (%s , %d)\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
			switch(ctrlno)
			{
				case 0:	
						close(1);	
						FILE *fp;
						fp = fopen("list.txt", "w");
						dup(fp);
						execlp("/bin/ls", "ls", NULL);
						close(fp);
						FILE *fp9;
						i=0;
						fp9 = fopen("list.txt", "r");
						while((send_data[i]=fgetc(fp9))!=EOF)
						{
							i++;
						}
						send_data[i]='\0';
						fclose(fp9);
						remove("list.txt");
						send(dataconnected, send_data, strlen(send_data), 0);
						break;		
				case 1: 
						filename_size = recv(dataconnected, filename, 20, 0);
						filename[filename_size] ='\0';
						bytes_received = recv(dataconnected,recv_data,1024,0);
						recv_data[bytes_received] = '\0';
						if(strcmp(recv_data, "NF") == 0)
						{
							printf("\nNO file to upload\n");
						}
						else
						{	
							FILE *fp2;
							fp2 = fopen(filename, "w");
							fprintf(fp2, "%s", recv_data);
							fclose(fp2);
							printf("\nFile has been succesfully uploaded\n");
						}	
						break;
				case 2: 
						filename_size = recv(dataconnected, filename, 20, 0);
						filename[filename_size] ='\0';
						FILE *fp1;
						if((fp1 = fopen(filename, "r")) == NULL)
						{
							send(dataconnected,"NF",strlen("NF"),0);
						}
						else
						{
							i=0;
							while((send_data[i]=fgetc(fp1))!=EOF)
							{
								i++;
							}
							send_data[i]='\0';
							fclose(fp1);
							send(dataconnected, send_data, strlen(send_data), 0);
						}	
						break;
				case 3: 
						filename_size=recv(dataconnected,filename,20,0);
						filename[filename_size]='\0';
						//printf("\n%s\n",filename);
						if((remove(filename))!=0)
						{
							printf("File to be deleted doesn't exist\n");
						}
						else
						{
							printf("File %s has been deleted\n",filename);	
						}
						break;
				case 4: path_size=recv(dataconnected,path,50,0);
						path[path_size]='\0';
						if((chdir(path))!=0)
						{
							printf("Invalid path\n");
						}
						else
						{
							printf("Directory changed\n");	
						}
						break;
				case 5: path_size=recv(dataconnected,path,50,0);
						path[path_size]='\0';
						if((mkdir(path,0777))!=0)
						{
							printf("Invalid path\n");
						}
						else
						{
							printf("New Directory created on the server\n");	
						}
						break;
				case 6: 
						chdir(serverhomepath);
						break;	
				}
			if(ctrlno==6)
			{
				printf("Terminating the connection with client\n");
				break;
			}	
		}
	}       

	close(sock_ctrl);
	return 0;
} 
