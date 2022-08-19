NAME = server client
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

EXLIBS = libft/libft.a


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft
OFLAGS = -Wall -Wextra -Werror -Llibft -lft

all:	$(NAME)

server : $(EXLIBS) $(OBJECTS)
	$(CC) $(OFLAGS) server.o -o server

client : $(EXLIBS) $(OBJECTS)
	$(CC) $(OFLAGS) client.o -o client

$(EXLIBS):
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re