/*
** rc.c for 42sh in C:\Users\gambin_l\42SH\sources\linked_list
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Sat Jun 04 20:56:01 2016 Gambini Lucas
** Last update Sun Jun 05 14:43:38 2016 Gambini Lucas
*/

# include		"42.h"

int			free_alias(t_list *list)
{
  t_node		*tmp;

  if (list->myRc && list->myRc->head)
    {
      if (list->myRc->head->next)
	tmp = list->myRc->head->next;
      else
	{
	  free(list->myRc->head);
	  list->myRc->head = NULL;
	  return (FAILURE);
	}
    }
  else
    return (FAILURE);
  while (tmp)
    {
      free(tmp->prev->data);
      free(tmp->prev);
      tmp = tmp->next;
    }
  if (list->myRc->tail)
    free(list->myRc->tail);
  return (SUCCESS);
}

int			builtin_source(t_list *list, char **cmd)
{
  int			fd;
  char			*buff;

  (void)cmd;
  if ((fd = open("tmp/.42shrc", O_RDWR | O_CREAT | O_APPEND, __RIGHT)) == -1)
    return (FAILURE);
  free_alias(list);
  while ((buff = get_next_line(fd)))
    {
      if (buff[0] && buff[0] != '#')
	{
	if ((list = get_cmd(list, pre_check(buff, list))) == NULL)
	  continue;
	exec_scatter(list);
	  list = free_cmd(list);
	}
    }
  return (SUCCESS);
}
