CLIENT_NAME = client
SERVER_NAME = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SERVER_SRCS = server.c
CLIENT_SRCS = error.c client.c

all: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -I. -I$(LIBFTDIR) $(SERVER_SRCS) $(LIBFT) -o $(SERVER_NAME)
	@echo "Compiled $(SERVER_NAME) successfully!"

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -I. -I$(LIBFTDIR) $(CLIENT_SRCS) $(LIBFT) -o $(CLIENT_NAME)
	@echo "Compiled $(CLIENT_NAME) successfully!"

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re