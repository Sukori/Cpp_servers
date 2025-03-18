#include "http.hpp"

static std::string	read_file(const std::string& file_path)
{
	std::ifstream file(file_path.c_str());
	if (!file.is_open())
	{
		std::cout << "failed html" << std::endl;
		return (NULL);
	}
	std::stringstream buffer;
	buffer << file.rdbuf();
	return (buffer.str());
}

static int	handle_client(int client)
{
	std::string	http_response = "HTTP/1.1 200 OK\r\n";
	http_response += "Content-type: text/html\r\n";
	http_response += "\r\n";
	http_response += read_file("index.html");
	send(client, http_response.c_str(), http_response.size(), 0);
	close(client);
	return (0);
}

int	start_server(void)
{
	int				serv_socket;
	int				client_socket;
	char			buffer[1024] = {0};
	sockaddr_in		serv_address;
	std::ofstream	log_file("server.log", std::ios::app);

	if (!log_file.is_open())
	{
		std::cout << "failed logs" << std::endl;
		return (-1);
	}
	serv_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_socket < 0)
	{
		std::cout << "socket failed" << std::endl;
		return (-1);
	}
	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(8080);
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(serv_socket, (struct sockaddr *)&serv_address, sizeof(serv_address)) < 0)
	{
		std::cout << "bind failed" << std::endl;
		close(serv_socket);
		return (-1);
	}
	if (listen(serv_socket, 5) < 0)
	{
		std::cout << "listen failed" << std::endl;
		close(serv_socket);
		return (-1);
	}
	while (42)
	{
		client_socket = accept(serv_socket, NULL, NULL);
		if (client_socket < 0)
		{
			std::cout << "accept failed" << std::endl;
			continue;
		}
		recv(client_socket, buffer, sizeof(buffer),0);
		log_file << "Client connected:\n" << buffer << std::endl;
		std::memset(buffer, 0, sizeof(buffer));
		handle_client(client_socket);
	}
	close(serv_socket);
	log_file.close();
	return (0);
}

int	main()
{
	start_server();
	return (0);
}

