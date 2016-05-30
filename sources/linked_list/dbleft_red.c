/*
** dbleft_red.c for 42SH in C:\Users\gambin_l\42SH\sources\linked_list
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Mon May 30 11:55:20 2016 Gambini Lucas
** Last update Mon May 30 12:26:32 2016 Philippe Lefevre
*/

# include		"42.h"

void			free_list_dbleft(t_list *list)
{
  t_dbleft		*tmp;

  if (list->dbleftptr->head)
    tmp = list->dbleftptr->head->next;
  else
    return;
  while (tmp)
    {
      free(tmp->line);
      tmp = tmp->next;
    }
  if (list->dbleftptr->tail != NULL)
    free(list->dbleftptr->tail);
  list->dbleftptr->head = NULL;
  list->dbleftptr->tail = NULL;
}

t_list			*dbleft_buffer(t_list *list, char *line)
{
  t_dbleft		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (list);
  if (!line || line[0] == 0 || line[0] == '\n'
      || (new->line = strdup(line)) == NULL)
    return (list);
  new->next = NULL;
  if (list->dbleftptr->tail == NULL)
    {
      new->prev = NULL;
      list->dbleftptr->head = new;
      list->dbleftptr->tail = new;
    }
  else
    {
      list->dbleftptr->tail->next = new;
      new->prev = list->dbleftptr->tail;
      list->dbleftptr->tail = new;
    }
  return (list);
}
