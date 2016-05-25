/*
** check_built.c for check_built in /home/puccio_c/rendu/minishell/42SH/sources/parsing
**
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
**
** Started on  Mon May 23 17:29:52 2016 cyril puccio
** Last update Wed May 25 12:41:31 2016 Philippe Lefevre
*/

#include		"42.h"

void			free_built(char *tab[])
{
  int			i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
}

int			check_built(t_list *list, t_cmd *cmd)
{
  char			*builtin[6];
  int			i;
  int			j;

  i = -1;
  builtin[0] = strdup("cd");
  builtin[1] = strdup("setenv");
  builtin[2] = strdup("unsetenv");
  builtin[3] = strdup("echo");
  builtin[4] = strdup("exit");
  builtin[5] = NULL;
  while (!(list->do_exit) && cmd->cmd[++i] != NULL)
    {
      j = -1;
      while (builtin[++j] != NULL)
	if (strcmp(cmd->cmd[i], builtin[j]) == 0)
	  {
	    free_built(builtin);
	    if ((strncmp(cmd->cmd[i], "exit ", 5) != 0)
		|| (strcmp(cmd->cmd[i], "exit ") != 0))
	      builtin_exit(list, cmd->cmd);
	    return (j + 20);
	  }
    }
  free_built(builtin);
  return (FAILURE);
}
