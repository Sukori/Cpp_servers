GPP		= g++

FLAGS	= -Wall -Wextra -Werror -std=c++98

HEAD	= http.hpp

CLIENT	= client

SERVER	= server

SRCC	= $(addsuffix .cpp, $(CLIENT))

SRCS	= $(addsuffix .cpp, $(SERVER))

OBJC	= $(addsuffix .o, $(CLIENT))

OBJS	= $(addsuffix .o, $(SERVER))

all: $(OBJC) $(OBJS) $(HEAD)

$(OBJC): $(SRCC)
	$(GPP) $(FLAGS) $^ -o client

$(SRCC):
	$(GPP) $(FLAGS) -c $^

$(OBJS): $(SRCS)
	$(GPP) $(FLAGS) $^ -o server

$(SRCS):
	$(GPP) $(FLAGS) -c $^

fclean:
	rm server client

re: fclean
	make all

.PHONY: all clean fclean re

