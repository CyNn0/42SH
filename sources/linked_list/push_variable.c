/*
** push_variable.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 25 10:13:39 2016 boris saint-bonnet
** Last update Fri May 27 14:43:37 2016 Gambini Lucas
*/

#include "42.h"

t_node		*init_push_var(t_node *node, char *name, char *data)
{
  if ((node->data = (data == NULL) ? "" :  strdup(data)) == NULL)
    return (NULL);
  if ((node->name = (name == NULL) ? "" : strdup(name)) == NULL)
    return (NULL);
  node->next = NULL;
  node->p = true;
  return (node);
}

t_list          *push_variable(t_list *list, char *name, char *data)
{
  t_node        *node;

  if ((node = malloc(sizeof(*node))) == NULL)
    {
      fprintf(stderr, "Error: allocation memory failed\n");
      return (NULL);
    }
  if (node != NULL)
    {
      if (init_push_var(node, name, data) == NULL)
	return (list);
      if (list->myEnv->tail == NULL)
	{
	  node->prev = NULL;
	  list->myEnv->head = node;
	  list->myEnv->tail = node;
	}
      else
	{
	  list->myEnv->tail->next = node;
	  node->prev = list->myEnv->tail;
	  list->myEnv->tail = node;
	}
    }
  return (list);
}
