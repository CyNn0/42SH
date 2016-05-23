/*
** exit.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/misc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:57:19 2016 Philippe Lefevre
** Last update Mon May 23 20:19:35 2016 Philippe Lefevre
*/

#define			_POSIX_SOURCE
#include		<sys/types.h>
#include		<signal.h>
#include		<unistd.h>
#include		<sys/wait.h>

void			my_exit(int status)
{
  (void)status;
  kill(getpid(), SIGINT);
}
