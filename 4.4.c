#include <stdio.h>
<<<<<<< HEAD
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
=======
#include <string.h>		//strlen
#include <sys/socket.h>
#include <arpa/inet.h>		//inet_addr
#include <unistd.h>		//write

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char *message[1000], buffer[1000];
>>>>>>> 1ca4e275b2c19ba2db17df0da6e05ad2e54a2cc4

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1)
	{
		printf("Could not create socket");
	}

<<<<<<< HEAD
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
=======
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	//Bind
	if(bind (socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("Bind Failed");

		return 1;
	}

	puts("Done Bind\n");

	//Listen
	listen(socket_desc, 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...\n");

	int sizeOfStruct = sizeof(struct sockaddr_in);

	while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&sizeOfStruct)) ) 
	{
		//Receive message from client
		recv(new_socket, buffer, 1000, 0);
		printf("Client's message: %s\n", buffer);

		//Send message  to client
		printf("Server's message: ");
		fgets(buffer, 1000, stdin);
		send(new_socket, buffer, 1000, 0);
		puts("Message sent to server\n");
	}

	if (new_socket < 0)
		perror("accept()");

	close(socket_desc);
	return 0;

>>>>>>> 1ca4e275b2c19ba2db17df0da6e05ad2e54a2cc4
}
