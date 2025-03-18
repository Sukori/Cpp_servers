#include "http.hpp"

int	start_client(void)
{
	int			client_socket;
	char		message[] = "Hello server!";
	sockaddr_in	serv_address;

	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(8080);
	serv_address.sin_addr.s_addr = INADDR_ANY;
	connect(client_socket, (struct sockaddr *)&serv_address, sizeof(serv_address));
	send(client_socket, message, strlen(message), 0);
	close(client_socket);
	return (0);
}

int	main()
{
	start_client();
	return (0);
}

