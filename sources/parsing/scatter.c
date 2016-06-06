/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Gambini Lucas
** Last update Mon Jun  6 22:04:22 2016 cyril puccio
*/

#include		"42.h"

int			normal_scatter(t_cmd *cmd, char **env,
				       t_list *list, int builtin)
{
  cmd = swap_alias(cmd, list->myRc, 0);
  if (cmd->go_on == 0)
    return (FAILURE - 42);
  return ((cmd->flag == SIMPLE_R)
	  ? (simple_right(cmd, list, env, builtin))
	  : ((cmd->flag == SIMPLE_L)
	     ? (simple_left(cmd, list, env, builtin))
	     : ((cmd->flag == DOUBLE_R)
		? (double_right(cmd, list, env, builtin))
		: ((cmd->flag == DOUBLE_L)
		   ? (double_left(cmd, list, env, builtin))
		   : ((simple_exec(cmd, list, env, builtin)))))));
}

char			**init_scatter(t_list *list)
{
  char                  **env;

  free_path(list);
  env = extract_env(list->myEnv);
  path_to_list(list);
  return (env);
}

int			exec_scatter(t_list *list)
{
  char			**env;
  t_cmd			*tmp;

  tmp = list->head;
  env = init_scatter(list);
  while (!(list->do_exit) && tmp && tmp->cmd[0])
    {
      if (tmp->go_on == 1)
	{
	  if (tmp->token == PIPE)
	    {
	      if (scatter_pipe(tmp, list, env) == FAILURE)
		{
		  free_tab(env);
		  return (FAILURE);
		}
	    }
	  else
	    if (normal_scatter(tmp, env, list, -20) == (FAILURE - 42))
	      return (FAILURE);
	}
      tmp = tmp->next;
    }
  return (SUCCESS);
}
