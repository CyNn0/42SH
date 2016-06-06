/*
** 42.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:20:11 2016 boris saint-bonnet
** Last update Mon Jun 06 17:48:51 2016 Gambini Lucas
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
# include		<sys/ioctl.h>
# include		<fcntl.h>
# include		<stdlib.h>
# include		<unistd.h>
# include		<errno.h>
# include		<time.h>
# include		<stdio.h>
# include               <signal.h>

# include		"prototype.h"
# include		"get_next_line.h"
# include		"linked_list.h"
# include		"parsing.h"
# include		"exec.h"
# include		"builtins.h"
# include		"globbing.h"

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
# define		__RIGHT		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
# define 		__SIMPLE	O_WRONLY | O_CREAT | O_TRUNC, __RIGHT
# define 		__DOUBLE	O_WRONLY | O_CREAT | O_APPEND, __RIGHT
# define		__HIST		O_RDWR | O_CREAT | O_APPEND, __RIGHT
# define		__HISTC		O_RDWR | O_CREAT | O_TRUNC, __RIGHT

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
int			dprintf(int fd, const char *format, ...);

#endif			/* !_42_H_ */
