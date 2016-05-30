/*
** list_cmd.c for list_cmd in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 20 06:45:22 2016 Lucas Gambini
** Last update Mon May 30 14:48:30 2016 Philippe Lefevre
*/

#include		"42.h"

t_list			*free_cmd(t_list *list)
{
  t_cmd			*tmp;

  if (list->head == NULL || list->tail == NULL)
    return (list);
  tmp = list->head->next;
  while (tmp != NULL)
    {
      free_tab(tmp->cmd);
      if (tmp->pipefd != -1)
	close(tmp->pipefd);
      free(tmp->prev);
      tmp = tmp->next;
    }
  free(list->tail);
  list->head = NULL;
  list->tail = NULL;
  return (list);
}

void			show_cmd_list(t_list *list)
{
  t_cmd			*tmp;
  int			i;

  tmp = list->head;
  i = -1;
  while (tmp)
    {
      printf("---------\nMaillon: %d\nToken: %d\nFlag: %d\n",
	     ++i, tmp->token, tmp->flag);
      show_tab(tmp->cmd);
      tmp = tmp->next;
    }
}

t_list			*push_cmd(t_list *list, char **cmd)
{
  t_cmd			*new;

  if ((new = malloc(sizeof(t_cmd))) == NULL
      || list == NULL)
    return (NULL);
  new->cmd = cmd;
  new->next = NULL;
  new->pipefd = -1;
  if (list->tail == NULL)
    {
      new->prev = NULL;
      list->head = new;
      list->tail = new;
    }
  else
    {
      list->tail->next = new;
      new->prev = list->tail;
      list->tail = new;
    }
  return (list);
}
