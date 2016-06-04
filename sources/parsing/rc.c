/*
** rc.c for 42sh in C:\Users\gambin_l\42SH\sources\linked_list
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Sat Jun 04 20:56:01 2016 Gambini Lucas
** Last update Sun Jun 05 01:18:29 2016 Philippe Lefevre
*/

# include		"42.h"

void			show_rc(t_list *list)
{
  t_node		*tmp;

  tmp = list->myRc->head;
  while (tmp)
    {
      printf("name: %s && data: %s\n", tmp->name, tmp->data);
      tmp = tmp->next;
    }
}

int			bash_in_list(t_list *list)
{
  int			fd;
  char			*buff;

  if ((fd = open(".42shrc", O_RDWR | O_CREAT | O_APPEND, __RIGHT)) == -1)
    return (fprintf(stderr, "%s: %s\n",
		    ".42shrc", strerror(errno)) * 0 + FAILURE);
  while ((buff = get_next_line(fd)))
    {
      list->myRc = push_bash(list->myRc, buff, NULL);
      free(buff);
    }
  show_rc(list);
  return (SUCCESS);
}
