##
## Makefile for  in /home/xx/Rendu/PSU/42SH
##
## Made by boris saint-bonnet
## Login   <saint-_o@epitech.net>
##
## Started on  Wed May 18 04:15:48 2016 boris saint-bonnet
## Last update Thu May 19 23:25:15 2016 boris saint-bonnet
##

CC		=		gcc -g -g3

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
				sources/parsing/my_strcut.c			\
				sources/utils/get_next_line.c			\
				sources/env/my_env_in_list.c			\
				sources/linked_list/linked_list.c		\
				sources/env/print_env.c				\
				sources/utils/string.c				\

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
