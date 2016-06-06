/*
** rc.c for 42sh in C:\Users\gambin_l\42SH\sources\linked_list
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Sat Jun 04 20:56:01 2016 Gambini Lucas
** Last update Mon Jun 06 02:36:24 2016 Gambini Lucas
*/

# include		"42.h"

int			free_alias(t_list *list)
{
  t_node		*tmp;

  if (!list->myRc->head)
    return (FAILURE);
  if (list->myRc->head->next)
    tmp = list->myRc->head->next;
  else
{
      free(list->myRc->head);
      list->myRc->head = NULL;
      return (FAILURE);
    }
  while (tmp)
    {
      free(tmp->prev->data);
      free(tmp->prev);
      tmp = tmp->next;
    }
  if (list->myRc->tail)
    free(list->myRc->tail);
  list->myRc->head = NULL;
  list->myRc->tail = NULL;
  return (SUCCESS);
}

int			builtin_source(t_list *list, char **cmd)
{
  int			fd;
  char			*buff;

  (void)cmd;
  if (list->myRc->head)
    free_alias(list);
  if ((fd = open("tmp/.42shrc", O_RDWR | O_CREAT | O_APPEND, __RIGHT)) == -1)
    return (FAILURE);
  list = free_cmd(list);
  while ((buff = get_next_line(fd)))
    {
      if ((list = get_cmd(list, pre_check(buff, list))) == NULL)
	continue;
      exec_scatter(list);
      list = free_cmd(list);
    }
  list = free_cmd(list);
  close(fd);
  return (SUCCESS);
}
