/*
** for_prompt.c for 42SH in C:\Users\gambin_l\42SH\sources\linked_list
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Fri May 27 14:36:49 2016 Gambini Lucas
** Last update Fri May 27 14:37:20 2016 Gambini Lucas
*/

# include		"42.h"

char		*find_user(t_list *list, char *str)
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
