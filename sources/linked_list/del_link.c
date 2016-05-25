/*
** del_link.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Wed May 25 22:59:19 2016 boris saint-bonnet
** Last update Wed May 25 23:07:15 2016 boris saint-bonnet
*/

#include "42.h"

t_list		*del_first_link(t_list *list)
{
  t_node        *tmp;

  if (list != NULL)
    {
      tmp = list->myEnv->head;
      list->myEnv->head = tmp->next;
      tmp->next->prev = NULL;
    }
  free(tmp);
  return (list);
}

t_list		*del_last_link(t_list *list)
{
  t_node        *tmp;

  if (list != NULL)
    {
      tmp = list->myEnv->tail;
      list->myEnv->tail = tmp->prev;
      tmp->prev->next = NULL;
    }
  free(tmp);
  return (list);
}

t_list          *del_link(t_list *list, char *name)
{
  t_node        *tmp;

  tmp = list->myEnv->head;
  while (tmp != NULL)
    {
      if ((my_strcmp(name, tmp->name)) == 0)
	{
	  if (tmp != list->myEnv->head && tmp != list->myEnv->tail)
	    {
	      tmp->next->prev = tmp->prev;
	      tmp->prev->next = tmp->next;
	    }
	  else if (tmp == list->myEnv->head)
	    list = del_first_link(list);
	  else
	    list = del_last_link(list);
	}
      tmp = tmp->next;
    }
  free(tmp);
  return (list);
}
