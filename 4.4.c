#include <stdio.h>
#include <string.h>		//strlen
#include <sys/socket.h>
#include <arpa/inet.h>		//inet_addr
#include <unistd.h>		//write

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char *message[1000], buffer[1000];

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1)
	{
		printf("Could not create socket");
	}

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

}
