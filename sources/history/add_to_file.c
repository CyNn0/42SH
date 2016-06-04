/*
** add_to_file.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Tue May 31 18:46:34 2016 boris saint-bonnet
** Last update Sat Jun  4 14:39:01 2016 boris saint-bonnet
*/

#include		"42.h"

int		open_history(char *s)
{
  int		fd;
  time_t	sec;
  struct tm	*inst;

  if ((fd = open(".42history", __DOUBLE)) == -1)
    {
      fprintf(stderr, "Error: loading history\n");
      return (FAILURE);
    }
  time(&sec);
  inst = localtime(&sec);
  dprintf(fd, "%d:%d\t%s\n", inst->tm_hour, inst->tm_min, s); 
  return (SUCCESS);
}



