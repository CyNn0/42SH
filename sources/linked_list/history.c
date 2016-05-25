/*
** history.c for 42sh in C:\Users\gambin_l\Documents\Virtual Machines\Shared\42SH\sources\linked_list
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Wed May 25 10:14:09 2016 Gambini Lucas
** Last update Wed May 25 10:26:03 2016 Gambini Lucas
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
