##
## Makefile for  in /home/xx/Rendu/PSU/42SH
##
## Made by boris saint-bonnet
## Login   <saint-_o@epitech.net>
##
## Started on  Wed May 18 04:15:48 2016 boris saint-bonnet
## Last update Wed May 18 05:02:43 2016 boris saint-bonnet
##

CC		=		gcc

RM		=		rm -f

NAME		=		42sh

CFLAGS		+=		-W -Wall -Wextra
CFLAGS		+=		-Iinclude -ansi -pedantic
CFLAGS		+=		-g -g3

SRC		=		sources/main.c					\
				sources/parsing/check_pipes.c			\
				sources/parsing/check_right_redirection.c	\
				sources/parsing/check_left_redirection.c	\
				sources/parsing/check_separator.c		\
				sources/parsing/check_and.c			\
				sources/parsing/pre_check.c			\
				sources/string.c				\
				sources/my_strcut.c				\
				sources/utils/get_next_line.c		\

OBJ		=		$(SRC:.c=.o)

all:				$(NAME)

$(NAME):			$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
				$(RM) $(OBJ)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:				all clean fclean re
