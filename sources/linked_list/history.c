/*
** history.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/linked_list
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Jun 06 20:41:33 2016 Philippe Lefevre
** Last update Mon Jun 06 21:12:13 2016 Philippe Lefevre
*/

#include		"42.h"

char			*hist_save_path(t_list *list)
{
  t_node		*tmp;
  char			*save;

  tmp = list->myEnv->head;
  save = NULL;
  while (tmp != NULL)
    {
      if (!(strcmp(tmp->name, "HOME")) && tmp->data != NULL)
	{
	  save = xmalloc(strlen(tmp->data) + 12);
          save = strcpy(save, tmp->data);
          save = strcat(save, "/");
	  save = strcat(save, ".42history");
	  save[strlen(tmp->data) + 11] = '\0';
	  return (save);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

int			open_history(t_list *list)
{
  char			*buf;
  int			fd;

  list->path_history = hist_save_path(list);
  if ((fd = open(list->path_history, __HIST)) == -1)
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
  if ((fd = open(list->path_history,  __HISTC)) == -1)
    return (FAILURE);
  while (tmp != NULL)
    {
      dprintf(fd, "%s", tmp->s);
      tmp = tmp->next;
    }
  close(fd);
  free(list->path_history);
  return (SUCCESS);
}

t_list			*add_history(t_list *list, char *line)
{
  t_hist		*new;
  struct tm		*inst;
  time_t		sec;
  static int		nb = 0;
  char			*new_line;

  if (line[0] == '\0')
    return (list);
  time(&sec);
  inst = localtime(&sec);
  new_line = xmalloc(16 + strlen(line));
  memset(new_line, '\0', 16 + strlen(line));
  sprintf(new_line, "     %d\t%d:%d\t%s\n", ++nb, inst->tm_hour,
	  inst->tm_min, line);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (list);
  if (new != NULL)
    {
      if (!line || line[0] == 0 || line[0] == '\n'
	  || (new->s = new_line) == NULL)
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
  int			len;

  history = list->myHist->head;
  tmp = history;
  if (cmd[1] && !(strcmp(cmd[1], "-c")))
    return (clear_history(list));
  else if (cmd[1] && (strcmp(cmd[1], "-c")))
    {
      history = list->myHist->tail;
      tmp = history;
      len = my_atoi(cmd[1]);
      if (len < 0)
	fprintf(stderr, "%s\n", "history: Badly formed number.");
      while (tmp != NULL && --len)
	tmp = tmp->prev;
    }
  while (tmp != NULL)
    {
      printf("%s", tmp->s);
      tmp = tmp->next;
    }
  return (FAILURE);
}
