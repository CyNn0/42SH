/*
** exit.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/builtins
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed May 25 11:24:01 2016 Philippe Lefevre
** Last update Mon Jun 06 04:33:02 2016 Philippe Lefevre
*/

#include		"42.h"

int			builtin_exit(t_list *list, char **cmd)
{
  int			i;

  list->do_exit = 1;
  i = -1;
  while (cmd[++i])
    {
      list->value_exit = my_atoi(cmd[i]);
      /* arrete la boucle quand separator */
    }
  if (i > 2)
    list->do_exit =
  fprintf(stderr, "exit: too many arguments\n");
  else
    {
      if (isatty(0) == 1)
	printf("exit\n");
      return (SUCCESS);
    }
  list->do_exit = 0;
  list->value_exit = 0;
  return (FAILURE);
}
