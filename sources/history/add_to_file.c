/*
** add_to_file.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Tue May 31 18:46:34 2016 boris saint-bonnet
** Last update Mon Jun  6 19:36:17 2016 boris saint-bonnet
*/

#include		"42.h"

int			open_history(char *s)
{
  time_t		sec;
  int			fd;
  struct tm		*inst;

  if ((fd = open("tmp/.42history", __HIST)) == -1)
    return (FAILURE);
  time(&sec);
  inst = localtime(&sec);
  dprintf(fd, "%d:%d\t%s\n", inst->tm_hour, inst->tm_min, s);
  if ((close(fd)) == -1)
    return (FAILURE);
  return (SUCCESS);
}
