/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Lucas Gambini
** Last update Mon May 23 18:40:35 2016 Gambini Lucas
*/

#include "42.h"

int	exec_scatter(t_list *list)
{
  char	**env;
  t_cmd	*tmp;

  tmp = list->head;
  env = extract_env(list->myEnv);
  (void)env;
  while (tmp)
    {
      (tmp->flag == SIMPLE_R) ? (printf("SIMPLE_R\n"))
	  : ((tmp->flag == SIMPLE_L) ? (printf("SIMPLE_L\n"))
	      : ((tmp->flag == DOUBLE_R) ? (printf("DOUBLE_R\n"))
		  : ((tmp->flag == DOUBLE_L) ? (printf("DOUBLE_L\n"))
		      : ((printf("EXEC SIMPLE\n"))))));
      tmp = tmp->next;
    }
  return (SUCCESS);
}
