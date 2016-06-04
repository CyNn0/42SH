/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Gambini Lucas
** Last update Sat Jun 04 14:37:39 2016 Gambini Lucas
*/

#include		"42.h"

int			normal_scatter(t_cmd *cmd, char **env,
				       t_list *list, int builtin)
{
  return ((cmd->flag == SIMPLE_R) ? (simple_right(cmd, list, env, builtin))
   : ((cmd->flag == SIMPLE_L) ? (simple_left(cmd, list, env, builtin))
      : ((cmd->flag == DOUBLE_R) ? (double_right(cmd, list, env, builtin))
	 : ((cmd->flag == DOUBLE_L) ? (double_left(cmd, list, env, builtin))
	    : ((simple_exec(cmd, list, env, builtin)))))));
}

int			exec_scatter(t_list *list)
{
  char		**env;
  t_cmd		*tmp;
  int		builtin;

  tmp = list->head;
  free_path(list);
  env = extract_env(list->myEnv);
  path_to_list(list);
  while (!(list->do_exit) && tmp && tmp->cmd[0])
    {
      if ((builtin = check_built(list, tmp)) == SUCCESS)
	return (SUCCESS);
      if (tmp->go_on == 1)
	{
	  if (tmp->token == PIPE)
	    scatter_pipe(tmp, list, env);
	  else
	    if (normal_scatter(tmp, env, list, builtin - 20))
		return (FAILURE);
	}
      tmp = tmp->next;
    }
  if (env)
    free_tab(env);
  return (SUCCESS);
}
