##
## Makefile for Makefile in /home/brunne_s/rendu/Communaute_du_C/minitalk
## 
## Made by brunner steeven
## Login   <brunne_s@epitech.net>
## 
## Started on  Mon Mar 24 14:48:40 2014 brunner steeven
## Last update Mon Mar 24 14:48:42 2014 brunner steeven
##

CC	= gcc

RM	= rm -f

NAME	= client

NAME2	= server

SRC	= client.c \

SRC2	= server.c \

OBJ	= $(SRC:.c=.o)

OBJ2	= $(SRC2:.c=.o)


all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

clean:
	$(RM) $(OBJ) $(OBJ2)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all
