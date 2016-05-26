/*
** exit.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/misc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:57:19 2016 Philippe Lefevre
** Last update Thu May 26 12:02:04 2016 Gambini Lucas
*/

#define			_POSIX_SOURCE
#include		"42.h"

int			my_exit(int status)
{
  (void)status;
  kill(getpid(), SIGKILL);
  return (FAILURE);
}
