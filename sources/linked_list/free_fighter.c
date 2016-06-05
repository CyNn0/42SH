/*
** free_fighter.c for free_fighter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 20 04:39:28 2016 Lucas Gambini
** Last update Sun Jun 05 05:18:02 2016 Philippe Lefevre
*/

#include	"42.h"

void		free_hist(t_list *list)
{
  t_hist	*tmp;

  tmp = list->myHist->head;
  while (tmp != NULL)
    {
      xfree(tmp->s);
      xfree(tmp->prev);
      tmp = tmp->next;
    }
  if (list->myHist->tail != NULL)
    xfree(list->myHist->tail);
  xfree(list->myHist);
}

void		free_env(t_list *list)
{
  t_node	*tmp;

  tmp = list->myEnv->head;
  while (tmp != NULL)
    {
      xfree(tmp->name);
      xfree(tmp->prev);
      tmp = tmp->next;
    }
  if (list->myEnv->tail != NULL)
    xfree(list->myEnv->tail);
  xfree(list->myEnv);
}

void		free_path(t_list *list)
{
  t_node	*tmp;

  if (list->path->head)
    tmp = list->path->head;
  else
    return;
  while (tmp != NULL)
    {
      xfree(tmp->data);
      xfree(tmp->prev);
      tmp = tmp->next;
    }
  if (list->path->tail != NULL)
    xfree(list->path->tail);
  list->path->head = NULL;
  list->path->tail = NULL;
}

void		free_fighter(t_list *list)
{
  free_env(list);
  free_path(list);
  free_hist(list);
  close(list->history);
  xfree(list);
}
