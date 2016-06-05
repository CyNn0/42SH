/*
** push_bash.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Tue May 31 17:23:41 2016 boris saint-bonnet
** Last update Sun Jun 05 14:02:36 2016 Gambini Lucas
*/

# include		"42.h"

t_bash			*push_bash(t_bash *list, char *data, char *name)
{
  t_node		*node;

  if ((node = malloc(sizeof(*node))) == NULL)
    return (NULL);
  if (list != NULL && node != NULL)
    {
      if (data && (node->data = strdup(data)) == NULL)
	return (list);
      if (name && (node->name = strdup(name)) == NULL)
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
