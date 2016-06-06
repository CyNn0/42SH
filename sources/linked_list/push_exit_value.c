/*
** push_exit_value.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/linked_list
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sun Jun 05 03:18:12 2016 Philippe Lefevre
** Last update Mon Jun 06 21:53:38 2016 Philippe Lefevre
*/

#include		"42.h"

int			push_exit_value(t_list *list, int pid, t_cmd *cmd)
{
  t_node		*tmp;
  int			status;

  status = 0;
  if (cmd->token != PIPE)
    status = xwaitpid(pid, 0, 0);
  tmp = list->myEnv->head;
  while (tmp != NULL)
    {
      if (!(strcmp("?", tmp->name)))
	{
	  xfree(tmp->data);
	  tmp->data = my_itoa(status);
	}
      tmp = tmp->next;
    }
  if (status != 0)
    return (FAILURE);
  list->value_exit = 0;
  return (SUCCESS);
}
