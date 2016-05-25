/*
** exit.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/builtins
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed May 25 11:24:01 2016 Philippe Lefevre
** Last update Wed May 25 17:07:38 2016 Philippe Lefevre
*/

#include		"42.h"

int			builtin_exit(t_list *list, char **cmd)
{
  int			i;

  list->do_exit = 1;
  i = -1;
  while (cmd[++i])
    {
      list->value_exit = atoi(cmd[i]);
      /* arrete la boucle quand separator */
    }
  if (i > 2)
    list->do_exit =
  fprintf(stderr, "exit: too many argumentsexit: too many arguments\n");
  else
    return (SUCCESS);
  list->do_exit = 0;
  list->value_exit = 0;
  return (FAILURE);
}
