#ifndef HTTP_HPP
# define HTTP_HPP

# include <unistd.h>
# include <sys/socket.h>
# include <cstring>
# include <iostream>
# include <arpa/inet.h>
# include <fstream>
# include <sstream>

int	start_server(void);
int	start_client(void);

#endif
