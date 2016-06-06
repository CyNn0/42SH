/*
** history.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/linked_list
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Jun 06 20:41:33 2016 Philippe Lefevre
** Last update Mon Jun 06 21:43:24 2016 Philippe Lefevre
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
      list = add_history(list, buf, 0);
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
