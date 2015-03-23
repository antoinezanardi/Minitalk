##
## Makefile for make in /home/zanard_a/rendu/Projets Piscines/expr
##
## Made by Antoine Zanardi
## Login   <zanard_a@epitech.net>
##
## Started on  Tue Oct 21 16:47:57 2014 Antoine Zanardi
## Last update Wed Feb 25 18:45:12 2015 Antoine Zanardi
##

DEBUG	=	no

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g -Wall -Wextra -pedantic
endif

NAME_CLIENT	=	client

NAME_SERVER	=	server

SERVER_PA	=	./server/

CLIENT_PA	=	./client/

SRCS_CLIENT	=	$(CLIENT_PA)main.c \
			$(CLIENT_PA)error.c \
			$(CLIENT_PA)fc_base.c \
			$(CLIENT_PA)my_putchar.c \
			$(CLIENT_PA)my_putstr.c \
			$(CLIENT_PA)my_getnbr.c \

SRCS_SERVER	=	$(SERVER_PA)main.c \
			$(SERVER_PA)my_putchar.c \
			$(SERVER_PA)my_put_nbr.c \
			$(SERVER_PA)my_putstr.c \

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

INC	=	-I include/

CFLAGS	+=	$(INC)


all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER)
	cc -Wall $(OBJS_SERVER) $(INC) -o ./server/$(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	cc -Wall $(OBJS_CLIENT) $(INC) -o ./client/$(NAME_CLIENT)

clean:
	rm -f $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER)

fclean: clean
	rm -f ./server/$(NAME_SERVER)
	rm -f ./client/$(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean all
