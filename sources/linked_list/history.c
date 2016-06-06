/*
** history.c for hist in /home/gambin_l/Shared/42SH/sources/linked_list
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 27 14:35:49 2016 Gambini Lucas
** Last update Mon Jun 06 20:24:36 2016 Philippe Lefevre
*/

#include		"42.h"

int			open_history(t_list *list)
{
  char			*buf;
  int			fd;

  if ((fd = open(".42history", __HIST)) == -1)
    return (FAILURE);
  while ((buf = get_next_line(fd)) != NULL)
    {
      list = add_history(list, buf);
      free(buf);
    }
  close(fd);
  return (SUCCESS);
}

int			save_history(t_list *list)
{
  t_hist		*history;
  t_hist		*tmp;
  int			fd;

  history = list->myHist->head;
  tmp = history;
  if ((fd = open(".42history", __HISTC)) == -1)
    return (FAILURE);
  while (tmp != NULL)
    {
      dprintf(fd, "%s", tmp->s);
      tmp = tmp->next;
    }
  close(fd);
  return (SUCCESS);
}

t_list			*add_history(t_list *list, char *line)
{
  t_hist		*new;
  struct tm		*inst;
  time_t		sec;
  static int		nb = 0;
  char			*new_line;

  time(&sec);
  inst = localtime(&sec);
  new_line = xmalloc(16 + strlen(line));
  memset(new_line, 0, 16 + strlen(line));
  sprintf(new_line, "     %d\t%d:%d\t%s\n", ++nb, inst->tm_hour, inst->tm_min, line);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (list);
  if (new != NULL)
    {
      if (!line || line[0] == 0 || line[0] == '\n'
	  || (new->s = strdup(new_line)) == NULL)
	return (list);
      new->next = NULL;
      if (list->myHist->tail == NULL)
	{
	  new->prev = NULL;
	  list->myHist->head = new;
	  list->myHist->tail = new;
	}
      else
	{
	  list->myHist->tail->next = new;
	  new->prev = list->myHist->tail;
	  list->myHist->tail = new;
	}
    }
  free(new_line);
  return (list);
}

int			clear_history(t_list *list)
{
  t_hist		*tmp;

  tmp = list->myHist->head;
  while (tmp != NULL)
    {
      xfree(tmp->s);
      xfree(tmp->prev);
      tmp = tmp->next;
    }
  list->myHist->head = NULL;
  list->myHist->tail = NULL;
  return (SUCCESS);
}

int			builtin_history(t_list *list, char **cmd)
{
  t_hist		*history;
  t_hist		*tmp;

  if (!cmd[1])
    {
      history = list->myHist->head;
      tmp = history;
      while (tmp != NULL)
	{
	  printf("%s", tmp->s);
	  tmp = tmp->next;
	}
      return (SUCCESS);
    }
  else if (cmd[1] && !(strcmp(cmd[1], "-c")))
    return (clear_history(list));
  return (FAILURE);
}
