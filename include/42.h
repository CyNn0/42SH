/*
** 42.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:20:11 2016 boris saint-bonnet
** Last update Wed May 25 01:08:30 2016 boris saint-bonnet
*/

#ifndef			_42_H_
# define		_42_H_

/*
** INCLUDES
*/
# include		<stdio.h>
# include		<strings.h>
# include		<string.h>
# include		<sys/types.h>
# include		<sys/stat.h>
# include		<sys/wait.h>
# include		<fcntl.h>
# include		<stdlib.h>
# include		<unistd.h>
# include		<errno.h>

# include		"prototype.h"
# include		"get_next_line.h"
# include		"linked_list.h"
# include		"parsing.h"
# include		"exec.h"

/*
** DEFINE
*/

# define 		SUCCESS		(0)
# define 		FAILURE		(1)
# define 		BLACK		"\033[1;30m"
# define 		RED		"\033[1;31m"
# define 		GREEN		"\033[1;32m"
# define 		YELLOW		"\033[1;33m"
# define 		BLUE		"\033[1;34m"
# define 		PURPLE		"\033[1;35m"
# define 		CYAN		"\033[1;36m"
# define 		GREY		"\033[1;37m"
# define 		DEFAULT		"\033[0;m"

# define 		__3RRN0()       perror("Error");
# define 		__SIMPLE	O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
# define 		__DOUBLE	O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

/*
** STRUCTURES
*/

typedef struct		s_error
{
  int			error_status;
  char			*error;
}			t_error;

int			xwaitpid(int pid, int status, int opt);
void			print_signal_message(int status);

#endif			/* !_42_H_ */
