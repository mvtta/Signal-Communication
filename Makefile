################################################################################
# Makefile
################################################################################

# Makefile by mvaldeta (tired of !understanting makefiles)
# Version 0.0

################################################################################
# $@ evaluates to all
# $< evaluates to server
# $^ evaluates to server & client
#
# Automatic variables
#
# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $*: The stem of the target filename. A stem is typically a filename without its suffix. 
#
# The -c flag generates the .o file; see man gcc for a more detailed explanation. 
# The -o specifies the output file to create.
# make -p for makefile database
################################################################################

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SERVER = server
SERVER_SRCS = ./srcs/server.c

CLIENT = client
CLIENT_SRCS = ./srcs/client.c

all : $(SERVER) $(CLIENT)

$(CLIENT) : $(CLIENT_SRCS)
	@$(CC) $(CLIENT_SRCS) -o $(CLIENT)
	@printf "\e[32m$@ Built🗣\e[0m\n"

$(SERVER) : $(SERVER_SRCS)
	@$(CC) $(SERVER_SRCS) -o $(SERVER)
	@printf "\e[32m$@ Built🏔\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@rm -f client.o server.o
	@printf "\e[31mclean done ✔️\e[0m\n"

fclean : clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[31mfclean done ✔️\e[0m\n"

re : fclean all

.PHONY: all clean fclean re