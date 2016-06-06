/*
** my_swap.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon Jun  6 09:33:57 2016 boris saint-bonnet
** Last update Mon Jun  6 22:30:01 2016 Lucas Gambini
*/

#include "42.h"

char                    **reset_alias(t_bash *list)
{
  t_node                *tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      tmp->p = 0;
      tmp = tmp->next;
    }
  return (NULL);
}

char			**dep_swap1(t_node *tmp, t_cmd *cmd,
				    char **tab, int *pos)
{
  if (tmp->p > 0)
    {
      fprintf(stderr, "Alias loop.\n");
      cmd->go_on = 0;
      return (NULL);
    }
  if (tmp->data)
    tab = prepare_tab(cmd_to_tab(tmp->data, ' ', ' ', ' '), cmd->cmd);
  tmp->p = ++(*pos);
  return (tab);
}

char			**dep_swap2(t_node *tmp, t_cmd *cmd,
				    char **tab, int *pos)
{
  if (tmp->p > 0)
    {
      fprintf(stderr, "Alias loop.\n");
      cmd->go_on = 0;
      return (NULL);
    }
  tab = prepare_tab(cmd_to_tab(tmp->data, ' ', ' ', ' '), tab);
  tmp->p = ++(*pos);
  return (tab);
}

t_cmd                   *swap_alias(t_cmd *cmd, t_bash *bash, int pos)
{
  t_node                *tmp;
  char                  **tab;

  tab = reset_alias(bash);
  tmp = bash->head;
  while (tmp)
    {
      if (!tab && strcmp(tmp->name, cmd->cmd[0]) == 0 &&
	  (tmp->p != pos || pos == 0))
	{
	  if ((tab = dep_swap1(tmp, cmd, tab, &pos)) == NULL)
	    return (cmd);
	  tmp = bash->head;
	}
      else if (tab && strcmp(tmp->name, tab[0]) == 0 &&
	       (tmp->p != pos || pos == 0))
	{
	  if ((tab = dep_swap2(tmp, cmd, tab, &pos)) == NULL)
	    return (cmd);
	  tmp = bash->head;
	}
      tmp = tmp->next;
    }
  return (ret_cmd(cmd, tab));
}
