#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 

int main() 
{ 
	int clientSocket = socket(AF_INET, SOCK_STREAM, 0); 

	sockaddr_in serverAddress; 
	serverAddress.sin_family = AF_INET; 
	serverAddress.sin_port = htons(8080); 
	serverAddress.sin_addr.s_addr = INADDR_ANY; 

	connect(clientSocket, (struct sockaddr*)&serverAddress, 
			sizeof(serverAddress)); 

	const char* message = "Hi"; 
	send(clientSocket, message, strlen(message), 0); 

	char buffer[1024] = {0};
	recv(clientSocket, buffer, sizeof(buffer), 0);
	std::cout<< "Server: "<< buffer <<std::endl;

	close(clientSocket); 

	return 0; 
}
