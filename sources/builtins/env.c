/*
** env.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/builtins
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sat Jun 04 15:21:47 2016 Philippe Lefevre
** Last update Sat Jun 04 15:36:17 2016 Philippe Lefevre
*/

#include		"42.h"

int			builtin_env(t_list *list, char **cmd)
{
  t_node		*tmp;

  tmp = list->myEnv->head;
  if (list != NULL)
    {
      while (tmp != NULL)
	{
	  if (!(tmp->god))
	    printf("%s=%s\n", tmp->name, tmp->data);
	  tmp = tmp->next;
	}
    }
  return (0);
}
