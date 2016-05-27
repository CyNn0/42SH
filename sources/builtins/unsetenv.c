/*
** unsetenv.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 25 22:51:35 2016 boris saint-bonnet
** Last update Fri May 27 14:18:44 2016 Gambini Lucas
*/

#include "42.h"

int		unsetenv_checking(t_list *list, char **cmd)
{
  if (list->myEnv->head == NULL)
    return (FAILURE);
  if (!(cmd[1]))
    {
      fprintf(stderr, "%s: Too few arguments\n", cmd[0]);
      return (FAILURE);
    }
  return (SUCCESS);
}

int			is_last_node(t_node *tmp, t_list *list)
{
  free_node(tmp);
  tmp = list->myEnv->tail;
  list->myEnv->head = NULL;
  list->myEnv->tail = NULL;
  return (SUCCESS);
}

int		builtin_unsetenv(t_list *list, char **cmd)
{
  int		i;
  t_node	*tmp;

  i = 0;
  if (unsetenv_checking(list, cmd) == FAILURE)
    return (FAILURE);
  while (cmd[++i])
    {
      tmp = list->myEnv->head;
      if (tmp == list->myEnv->tail && tmp == list->myEnv->tail)
	{
	  if ((strcmp(tmp->name, cmd[1])) == 0)
	    return (is_last_node(tmp, list));
	}
      while (tmp != NULL)
	{
	  if ((strcmp(cmd[i], tmp->name)) == 0)
	    list = del_link(list, tmp->name);
	  tmp = tmp->next;
	}
    }
  return (SUCCESS);
}
