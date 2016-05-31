/*
** push_bash.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Tue May 31 17:23:41 2016 boris saint-bonnet
** Last update Tue May 31 17:34:21 2016 boris saint-bonnet
*/

# include		"42.h"

t_bash			*push_bash(t_bash *list, char *data, char *name)
{
  t_node		*node;

  node = malloc(sizeof(*node));
  if (list != NULL && node != NULL)
    {
      if ((node->data = strdup(data)) == NULL)
	return (list);
      if ((node->name = strdup(name)) == NULL)
	return (list);
      node->next = NULL;
      node->p = false;
      if (list->tail == NULL)
	{
	  node->prev = NULL;
	  list->head = node;
	  list->tail = node;
	}
      else
	{
	  list->tail->next = node;
	  node->prev = list->tail;
	  list->tail = node;
	}
    }
  return (list);
}
