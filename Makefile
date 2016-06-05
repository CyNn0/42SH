##
## Makefile for  in /home/xx/Rendu/PSU/42SH
##
## Made by boris saint-bonnet
## Login   <saint-_o@epitech.net>
##
## Started on  Wed May 18 04:15:48 2016 boris saint-bonnet
## Last update Sun Jun  5 19:13:20 2016 Philippe Lefevre
##


NAME		=	42sh

ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[5;31m"
YELLOW          =       "\033[1;33m"
FINISH          =       "\033[5;1;35m"

CC		=	gcc -g -g3
CFLAGS		=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-Iinclude

RM		=	rm -f

SRCDIR		=	sources

SRC		=	$(SRCDIR)/main.c				\
			$(SRCDIR)/parsing/check_error.c			\
			$(SRCDIR)/parsing/double.c			\
			$(SRCDIR)/parsing/check_variable.c		\
			$(SRCDIR)/parsing/pre_check.c			\
			$(SRCDIR)/parsing/my_strcut.c			\
			$(SRCDIR)/parsing/get_cmd.c			\
			$(SRCDIR)/parsing/cmd_to_tab.c			\
			$(SRCDIR)/parsing/cmdtab_func.c			\
                        $(SRCDIR)/parsing/my_strtok.c			\
			$(SRCDIR)/parsing/check_bquotes.c		\
			$(SRCDIR)/parsing/simple.c			\
			$(SRCDIR)/parsing/post_parser.c			\
			$(SRCDIR)/parsing/scatter.c			\
			$(SRCDIR)/parsing/check_built.c			\
			$(SRCDIR)/parsing/string.c			\
			$(SRCDIR)/parsing/inihb.c			\
			$(SRCDIR)/misc/get_next_line.c			\
			$(SRCDIR)/misc/my_exit.c			\
			$(SRCDIR)/misc/my_itoa.c			\
			$(SRCDIR)/misc/my_atoi.c			\
			$(SRCDIR)/misc/my_strcat.c			\
			$(SRCDIR)/misc/xmalloc.c			\
			$(SRCDIR)/misc/xfree.c				\
			$(SRCDIR)/linked_list/linked_list.c		\
			$(SRCDIR)/linked_list/push_bash.c		\
			$(SRCDIR)/linked_list/free_fighter.c		\
			$(SRCDIR)/linked_list/list_cmd.c		\
			$(SRCDIR)/linked_list/history.c			\
			$(SRCDIR)/linked_list/push_variable.c		\
			$(SRCDIR)/linked_list/del_link.c		\
			$(SRCDIR)/linked_list/for_prompt.c		\
			$(SRCDIR)/linked_list/push_exit_value.c		\
			$(SRCDIR)/env/my_env_in_list.c			\
			$(SRCDIR)/env/print_env.c			\
			$(SRCDIR)/path/path_to_list.c			\
                        $(SRCDIR)/path/print_path.c			\
			$(SRCDIR)/redirect/simple_right.c		\
			$(SRCDIR)/redirect/simple_left.c		\
			$(SRCDIR)/redirect/exec_right.c			\
			$(SRCDIR)/redirect/exec_left.c			\
			$(SRCDIR)/redirect/pars_right.c			\
			$(SRCDIR)/redirect/pars_left.c			\
			$(SRCDIR)/redirect/double_right.c		\
			$(SRCDIR)/redirect/double_left.c		\
			$(SRCDIR)/exec/simple_exec.c			\
			$(SRCDIR)/exec/check_go_on.c			\
			$(SRCDIR)/builtins/echo/echo.c			\
			$(SRCDIR)/builtins/echo/check_options.c		\
			$(SRCDIR)/builtins/echo/print.c			\
			$(SRCDIR)/builtins/echo/get_varenv.c		\
			$(SRCDIR)/builtins/exit.c			\
			$(SRCDIR)/builtins/env.c			\
			$(SRCDIR)/builtins/setenv.c			\
			$(SRCDIR)/builtins/unsetenv.c			\
			$(SRCDIR)/builtins/source.c			\
			$(SRCDIR)/builtins/cd/cd.c			\
			$(SRCDIR)/builtins/cd/dep_cd.c			\
			$(SRCDIR)/builtins/swap_alias.c		\
			$(SRCDIR)/builtins/alias.c			\
			$(SRCDIR)/pipe/pipe.c				\
			$(SRCDIR)/history/add_to_file.c			\
			$(SRCDIR)/history/show_history.c		\
			$(SRCDIR)/globbing/globbing.c		\

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && \
			$(ECHO) $(GREEN) "[BIN]	" $(TEAL) $(NAME) $(DEFAULT) || \
			$(ECHO) $(RED) "[XXX]	" $(TEAL) $(NAME) $(DEFAULT)

.c.o		:
		        @$(CC) $(CFLAGS) -c $< -o $@ && \
		        $(ECHO) $(GREEN) "[OK]   " $(TEAL) $< $(DEFAULT) || \
	        	$(ECHO) $(RED) "[ERROR]" $(TEAL) $< $(DEFAULT)

clean		:
			@$(RM) $(OBJ)

fclean		:	clean
			@$(RM) $(NAME)
			@$(RM) tmp/.42history

re		:	fclean all

.PHONY		:	all clean fclean re
