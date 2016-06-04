/*
** check_built.c for check_built in /home/puccio_c/rendu/minishell/42SH/sources/parsing
**
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
**
** Started on  Mon May 23 17:29:52 2016 cyril puccio
** Last update Sat Jun 04 15:40:20 2016 Philippe Lefevre
*/

#include		"42.h"

int			check_built(t_list *list, t_cmd *cmd)
{
  char			*builtin[8];
  int			i;
  int			j;

  i = -1;
  builtin[0] = "cd";
  builtin[1] = "setenv";
  builtin[2] = "unsetenv";
  builtin[3] = "echo";
  builtin[4] = "exit";
  builtin[5] = "env";
  builtin[6] = "history";
  builtin[7] = NULL;
  while (!(list->do_exit) && cmd->cmd[++i] != NULL)
    {
      j = -1;
      while (builtin[++j] != NULL)
	if (strcmp(cmd->cmd[i], builtin[j]) == 0)
	  {
	    if (j == 4)
	      return (builtin_exit(list, cmd->cmd));
	    cmd->is_builtin = j;
	    return (j + 20);
	  }
    }
  return (FAILURE);
}
