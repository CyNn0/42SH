/*
** push_variable.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Wed May 25 10:13:39 2016 boris saint-bonnet
** Last update Wed May 25 10:42:48 2016 boris saint-bonnet
*/

#include "42.h"

t_list          *push_variable(t_list *list, char *name, char *data)
{
  t_node        *node;

  if ((node = malloc(sizeof(*node))) == NULL)
    {
      fprintf(stderr, "Error: allocation memory failed\n");
      exit(42);
    }
  if (list != NULL)
    {
      if (node != NULL)
	{
	  if ((node->data = strdup(data)) == NULL)
	    return (list);
	  if ((node->name = strdup(name)) == NULL)
	    return (list);
	  node->next = NULL;
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
    }
  return (list);
}
