/*
** history.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/linked_list
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Jun 06 20:41:33 2016 Philippe Lefevre
** Last update Mon Jun 06 22:03:24 2016 Philippe Lefevre
*/

#include		"42.h"

char			*give_new_line(char *line, int status)
{
  struct tm		*inst;
  time_t		sec;
  char			*new_line;
  static int		nb = 0;

  if (status)
    {
      time(&sec);
      inst = localtime(&sec);
      new_line = xmalloc(16 + strlen(line));
      memset(new_line, '\0', 16 + strlen(line));
      sprintf(new_line, "     %d\t%d:%d\t%s\n", ++nb, inst->tm_hour,
	      inst->tm_min, line);
    }
  else
    {
      new_line = xmalloc(strlen(line) + 2);
      new_line = strcpy(new_line, line);
      new_line = strcat(new_line, "\n\0");
      nb++;
    }
  return (new_line);
}

void			add_history_bis(t_list *list, t_hist *new)
{
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

t_list			*add_history(t_list *list, char *line, int status)
{
  t_hist		*new;
  char			*new_line;

  if (line[0] == '\0')
    return (list);
  new_line = give_new_line(line, status);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (list);
  if (new != NULL)
    {
      if (!line || line[0] == 0 || line[0] == '\n'
	  || ((new->s = new_line) == NULL))
	return (list);
      new->next = NULL;
      add_history_bis(list, new);
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
