/*
** free_fighter.c for free_fighter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 20 04:39:28 2016 Lucas Gambini
** Last update Fri May 20 05:51:26 2016 Lucas Gambini
*/

#include "42.h"

void		free_env(t_list *list)
{
  t_node	*tmp;

  tmp = list->myEnv->head;
  while (tmp != NULL)
    {
      free(tmp->name);
      free(tmp->data);
      free(tmp->prev);
      tmp = tmp->next;
    }
  if (list->myEnv->tail != NULL)
    free(list->myEnv->tail);
  free(list->myEnv);
}

void		free_path(t_list *list)
{
  t_node	*tmp;

  tmp = list->path->head;
  while (tmp != NULL)
    {
      free(tmp->data);
      free(tmp->prev);
      tmp = tmp->next;
    }
  if (list->path->tail != NULL)
    free(list->path->tail);
  free(list->path);
  free(tmp);
}

void		free_fighter(t_list *list)
{
  free_env(list);
  free_path(list);
  free(list);
}
