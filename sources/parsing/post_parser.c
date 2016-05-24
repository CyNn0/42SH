/*
** post_parser.c for post_parser in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 15:55:00 2016 Lucas Gambini
** Last update Tue May 24 09:34:50 2016 Gambini Lucas
*/

#include "42.h"

void            check_flag(t_cmd *tmp)
{
  char          *redirect;
  int           i;

  redirect = "><";
  i = -1;
  while (tmp->cmd[++i])
    {
      if (tmp->cmd[i][0] == redirect[0])
	{
	  (tmp->cmd[i][1] == redirect[0]) ?
	      (tmp->flag = DOUBLE_R) : (tmp->flag = SIMPLE_R);
	  break;
	}
      else if (tmp->cmd[i][0] == redirect[1])
	{
	  tmp->flag = (tmp->cmd[i][1] == redirect[1]) ?
	      (DOUBLE_L) : (SIMPLE_L);
	  break;
	}
      else
	tmp->flag = (EXE);
    }
}

t_list          *post_parser(t_list *list)
{
  t_cmd         *tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (tmp->token != PIPE)
        check_flag(tmp);
      tmp = tmp->next;
    }
  return (list);
}
