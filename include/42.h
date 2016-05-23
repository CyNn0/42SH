/*
** 42.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:20:11 2016 boris saint-bonnet
** Last update Mon May 23 19:11:54 2016 boris saint-bonnet
*/

#ifndef		__42_H__
# define	__42_H__

/*
** DEFINE
*/
# define SUCCESS	10
# define FAILURE	-1
# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define PURPLE		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define GREY		"\033[1;37m"
# define DEFAULT	"\033[0;m"
# define ERRNO          perror("Error; ")
# define __SIMPLE	O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
# define __DOUBLE	O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

/*
** INCLUDES
*/

# include	<stdio.h>
# include	<strings.h>
# include	<string.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	"prototype.h"
# include	"get_next_line.h"
# include	"linked_list.h"
# include	"parsing.h"
/*
** STRUCTURES
*/


#endif /* !__42_H__ */
