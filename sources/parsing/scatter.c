/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Lucas Gambini
** Last update Tue May 24 21:30:18 2016 boris saint-bonnet
*/

#include	"42.h"

int		exec_scatter(t_list *list)
{
  char		**env;
  t_cmd		*tmp;

  tmp = list->head;
  env = extract_env(list->myEnv);
  while (tmp && tmp->cmd[0])
    {
      if (check_built(tmp) == FAILURE)
	{
	  (tmp->flag == SIMPLE_R) ? (simple_right(tmp, list->path, env))
	    : ((tmp->flag == SIMPLE_L) ? (printf("SIMPLE_L\n"))
	       : ((tmp->flag == DOUBLE_R) ? (double_right(tmp, list->path, env))
		  : ((tmp->flag == DOUBLE_L) ? (printf("DOUBLE_L\n"))
		     : ((simple_exec(tmp, list->path, env))))));
	}
      (tmp->go_on == 1) ? (tmp = tmp->next)
	: (tmp = tmp->next->next);
    }
  free_tab(env);
  return (SUCCESS);
}
