/*
** get_cmd.c for get_cmd in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 20 06:28:24 2016 Lucas Gambini
** Last update Sat May 21 08:51:21 2016 Lucas Gambini
*/

#include "42.h"

t_list		*get_cmd(t_list *list, char *line)
{
  char		**tab;

  if (line == NULL || (tab = cmd_to_tab(line)) == NULL)
    return (NULL);
  return (list);
}
