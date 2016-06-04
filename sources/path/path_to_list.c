/*
** path_to_list.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Thu May 19 23:48:19 2016 boris saint-bonnet
** Last update Sat Jun 04 20:22:05 2016 Philippe Lefevre
*/

#include	"42.h"

int		path_nb(char *path)
{
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  while (path && path[++i])
    {
      if (path[i] == ':')
	nb++;
    }
  return (nb + 1);
}

t_list  	*path_to_list(t_list *list)
{
  char          *var;
  char		*path_line;
  int           i;

  if ((path_line = find_path(list)) != NULL && path_line)
    var = strdup(path_line);
  else
    var = NULL;
  i = path_nb(var);
  if ((list = push_path(list, my_strtok(var, ":"))) == NULL)
    return (NULL);
  while (i >= 0)
    {
      if ((list = push_path(list, my_strtok(NULL, ":"))) == NULL)
	return (NULL);
      i--;
    }
  free(var);
  return (list);
}
