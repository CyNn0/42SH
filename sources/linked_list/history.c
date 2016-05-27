/*
** history.c for hist in /home/gambin_l/Shared/42SH/sources/linked_list
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 27 14:35:49 2016 Gambini Lucas
** Last update Fri May 27 14:36:02 2016 Gambini Lucas
*/

# include	"42.h"

t_list		*add_history(t_list *list, char *line)
{
  t_hist	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (list);
  if (new != NULL)
    {
      if (!line || line[0] == 0 || line[0] == '\n'
	  || (new->s = strdup(line)) == NULL)
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
