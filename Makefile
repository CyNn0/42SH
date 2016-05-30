##
## Makefile for  in /home/xx/Rendu/PSU/42SH
##
## Made by boris saint-bonnet
## Login   <saint-_o@epitech.net>
##
## Started on  Wed May 18 04:15:48 2016 boris saint-bonnet
## Last update Mon May 30 12:11:15 2016 Lucas Gambini
##

CC		=	gcc -g -g3

RM		=	rm -f

PLZ		=	echo PLS

ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[5;31m"
YELLOW          =       "\033[1;33m"
FINISH          =       "\033[5;1;35m"

NAME		=	42sh

CFLAGS		=	-W -Wall -Wextra
CFLAGS		+=	-Iinclude -ansi -pedantic
CFLAGS		+=	-g -g3

SRC		=	sources/main.c				\
			sources/parsing/check_error.c		\
			sources/parsing/double.c		\
			sources/parsing/pre_check.c		\
			sources/parsing/my_strcut.c		\
			sources/parsing/get_cmd.c		\
			sources/parsing/cmd_to_tab.c		\
			sources/parsing/cmdtab_func.c		\
                        sources/parsing/my_strtok.c		\
			sources/parsing/check_bquotes.c		\
			sources/parsing/simple.c		\
			sources/parsing/post_parser.c		\
			sources/parsing/scatter.c		\
			sources/parsing/check_built.c		\
			sources/parsing/string.c		\
			sources/misc/get_next_line.c		\
			sources/misc/exit.c			\
			sources/linked_list/linked_list.c	\
			sources/linked_list/free_fighter.c	\
			sources/linked_list/list_cmd.c		\
			sources/linked_list/history.c		\
			sources/linked_list/push_variable.c	\
			sources/linked_list/del_link.c		\
			sources/linked_list/for_prompt.c	\
			sources/linked_list/dbleft_red.c	\
			sources/env/my_env_in_list.c		\
			sources/env/print_env.c			\
			sources/path/path_to_list.c		\
                        sources/path/print_path.c		\
			sources/redirect/simple_right.c		\
			sources/redirect/simple_left.c		\
			sources/redirect/exec_right.c		\
			sources/redirect/exec_left.c		\
			sources/redirect/pars_right.c		\
			sources/redirect/pars_left.c		\
			sources/redirect/double_right.c		\
			sources/redirect/double_left.c		\
			sources/exec/simple_exec.c		\
			sources/exec/check_go_on.c		\
			sources/builtins/echo/echo.c		\
			sources/builtins/echo/check_options.c	\
			sources/builtins/echo/print.c		\
			sources/builtins/echo/get_varenv.c	\
			sources/builtins/exit.c			\
			sources/builtins/setenv.c		\
			sources/builtins/unsetenv.c		\
			sources/builtins/cd/cd.c		\
			sources/builtins/cd/dep_cd.c		\
			sources/pipe/pipe.c			\

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && \
			$(ECHO) $(GREEN) "[BIN]	" $(TEAL) $(NAME) $(DEFAULT) || \
			$(ECHO) $(RED) "[XXX]	" $(TEAL) $(NAME) $(DEFAULT)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

%.o:			%.c
		        @$(CC) $(CFLAGS) -c $^ -o $@ && \
		        $(ECHO) $(GREEN) "[OK]   " $(TEAL) $^ $(DEFAULT) ||\
	        	$(ECHO) $(RED) "[ERROR]" $(TEAL) $^ $(DEFAULT)

.PHONY:			all clean fclean re
