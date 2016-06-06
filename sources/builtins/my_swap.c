/*
** my_swap.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Mon Jun  6 09:33:57 2016 boris saint-bonnet
** Last update Mon Jun  6 09:37:05 2016 boris saint-bonnet
*/

#include "42.h"

void                    reset_alias(t_bash *list)
{
  t_node                *tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      tmp->p = 0;
      tmp = tmp->next;
    }
}

t_cmd                   *swap_alias(t_cmd *cmd, t_bash *bash)
{
  t_node                *tmp;
  char                  **tab;
  int                   pos;

  pos = 0;
  tab = NULL;
  reset_alias(bash);
  tmp = bash->head;
  while (tmp)
    {
      if (!tab && strcmp(tmp->name, cmd->cmd[0]) == 0 && (tmp->p != pos || pos == 0))
	{
	  if (tmp->p > 0)
	    {
	      fprintf(stderr, "Alias loop.\n");
	      return (cmd);
	    }
	  tab = prepare_tab(cmd_to_tab(tmp->data, ' ', ' ', ' '), cmd->cmd);
	  tmp->p = ++pos;
	  tmp = bash->head;
	}
      else if (tab && strcmp(tmp->name, tab[0]) == 0 && (tmp->p != pos || pos == 0))
	{
	  if (tmp->p > 0)
	    {
	      fprintf(stderr, "Alias loop.\n");
	      return (cmd);
	    }
	  tab = prepare_tab(cmd_to_tab(tmp->data, ' ', ' ', ' '), tab);
	  tmp->p = ++pos;
	  tmp = bash->head;
	}
      tmp = tmp->next;
    }
  return (ret_cmd(cmd, tab));
}
