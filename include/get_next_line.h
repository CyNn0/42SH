/*
** get_next_line.h for 42SH in /home/lefevr_h/Workspace/Github/42SH/include
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 18:57:37 2016 Philippe Lefevre
** Last update Mon May 23 18:57:49 2016 Philippe Lefevre
*/

#ifndef			GET_NEXT_LINE_H_
# define		GET_NEXT_LINE_H_
# include		<unistd.h>
# include		<stdlib.h>
# include		<errno.h>

# ifndef		READ_SIZE
#  define		READ_SIZE	(4096)
# endif			/* !READ_SIZE */

char			*my_realloc(char *cur, int n);
char			*get_next_line(const int fd);

#endif			/* !GET_NEXT_LINE_H_ */
