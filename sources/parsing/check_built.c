/*
** check_built.c for check_built in /home/puccio_c/rendu/minishell/42SH/sources/parsing
**
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
**
** Started on  Mon May 23 17:29:52 2016 cyril puccio
** Last update Mon Jun 06 22:11:27 2016 Philippe Lefevre
*/

#include		"42.h"

int			check_built(t_list *list, t_cmd *cmd, int i)
{
  char			*builtin[10];
  int			j;

  builtin[0] = "cd";
  builtin[1] = "setenv";
  builtin[2] = "unsetenv";
  builtin[3] = "echo";
  builtin[4] = "exit";
  builtin[5] = "env";
  builtin[6] = "history";
  builtin[7] = "source";
  builtin[8] = "alias";
  builtin[9] = NULL;
  while (!(list->do_exit) && cmd->cmd[++i] != NULL)
    {
      j = -1;
      while (builtin[++j] != NULL)
	if (strcmp(cmd->cmd[i], builtin[j]) == 0)
	  {
	    cmd->is_builtin = j;
	    return (j + 20);
	  }
    }
  return (FAILURE);
}
