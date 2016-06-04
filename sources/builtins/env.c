/*
** env.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/builtins
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sat Jun 04 15:21:47 2016 Philippe Lefevre
** Last update Sat Jun 04 16:13:45 2016 Philippe Lefevre
*/

#include		"42.h"

int			builtin_env(t_list *list, char **cmd)
{
  t_node		*tmp;
  int			i;
  int			no_line;

  i = 0;
  no_line = 0;
  while (cmd[++i])
    if ((!strcmp("-0", cmd[i]))
	|| (!strcmp("--null", cmd[i])))
	no_line = 1;
  tmp = list->myEnv->head;
  if (list != NULL)
    {
      while (tmp != NULL)
	{
	  if (!(tmp->god))
	    printf("%s=%s%c", tmp->name, tmp->data, ((no_line) ? (0) : ('\n')));
	  tmp = tmp->next;
	}
    }
  return (0);
}
