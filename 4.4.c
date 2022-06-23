#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>		//inet_addr

int main(int argc, char **argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message = malloc (1000);
	char server_reply[2000];

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1)
	{
		printf("Could not create socket");
	}

	server.sin_addr.s_addr = inet_addr("192.168.53.3");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	//Connect to remote server
	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("Connetion Error");
		return 1;
	}

	puts("Connected \n");

	//Send some data
	while(1)
	{
		printf("Client's message:");
		fgets(message, 1000, stdin);
		send(socket_desc, message, 1000, 0);
		break;		//terminate while loop
	}

	if(send (socket_desc, message, strlen(message), 0) < 0)
	{
		puts("Send Failed");
		return 1;
	}

	puts("Message send to server\n");

	//Receive a reply from server
	if( recv (socket_desc, server_reply, 2000, 0) < 0)
	{
		puts("Receiver Failed");
	}

	printf("Server: %s\n", server_reply);
	puts("Receive reply from Server\n");
	close(socket_desc);

	return 0;
}
