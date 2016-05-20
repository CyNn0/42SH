/*
** linked_list.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Thu May 19 18:53:01 2016 boris saint-bonnet
** Last update Fri May 20 04:49:04 2016 boris saint-bonnet
*/

# include "42.h"

t_list *create_list(t_list *list)
{
  if ((list = malloc(sizeof(*list))) == NULL)
    return (NULL);
  if ((list->path = malloc(sizeof(struct s_path))) == NULL)
    return (NULL);
  if ((list->myEnv = malloc(sizeof(struct s_env))) == NULL)
    return (NULL);
  list->myEnv->head = NULL;
  list->myEnv->tail = NULL;
  list->head = NULL;
  list->tail = NULL;
  list->path->head = NULL;
  list->path->tail = NULL;
  return (list);
}

t_list		*push_env(t_list *list, char *data, char *name)
{
  t_node        *node;

  if ((node = malloc(sizeof(*node))) == NULL)
    return (NULL);
  if (list != NULL)
    {
      if (node != NULL)
	{
	  node->data = strdup(data);
	  node->name = strdup(name);
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

t_list		*push_path(t_list *list, char *data)
{
  t_node        *node;

  if ((node = malloc(sizeof(*node))) == NULL)
    return (NULL);
  if (data == NULL)
    return (list);
  node->data = strdup(data);
  node->name = NULL;
  node->next = NULL;
  if (list->path->tail == NULL)
    {
      node->prev = NULL;
      list->path->head = node;
      list->path->tail = node;
    }
  else
    {
      list->path->tail->next = node;
      node->prev = list->path->tail;
      list->path->tail = node;
    }
  return (list);
}

char	*find_user(t_list *list, char *str)
{
  t_node        *tmp;

  tmp = list->myEnv->head;
  while (tmp != NULL)
    {
      if ((strcmp(tmp->name, str) == 0))
	return (tmp->data);
      tmp = tmp->next;
    }
  return (NULL);
}

char    *find_path(t_list *list)
{
  t_node        *tmp;

  tmp = list->myEnv->head;
  while (tmp != NULL)
    {
      if ((strcmp(tmp->name, "PATH") == 0))
	return (tmp->data);
      tmp = tmp->next;
    }
  return (NULL);
}
