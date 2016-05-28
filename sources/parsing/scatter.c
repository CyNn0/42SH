/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Gambini Lucas
** Last update Sat May 28 14:50:30 2016 Philippe Lefevre
*/

#include		"42.h"

int			normal_scatter(t_cmd *cmd, char **env,
			       t_list *list, int builtin)
{
  (cmd->flag == SIMPLE_R) ? (simple_right(cmd, list, env, builtin))
      : ((cmd->flag == SIMPLE_L) ? (simple_left(cmd, list, env, builtin))
       : ((cmd->flag == DOUBLE_R) ? (double_right(cmd, list, env, builtin))
	  : ((cmd->flag == DOUBLE_L) ? (printf("DOUBLE_L\n"))
	     : ((simple_exec(cmd, list, env, builtin))))));
  return (SUCCESS);
}

int			exec_scatter(t_list *list)
{
  char		**env;
  t_cmd		*tmp;
  int		builtin;

  tmp = list->head;
  env = extract_env(list->myEnv);
  if (exec_pipe(list) == SUCCESS)
    return (SUCCESS);
  while (!(list->do_exit) && tmp && tmp->cmd[0])
    {
      if ((builtin = check_built(list, tmp)) == SUCCESS)
	return (SUCCESS);
      if (tmp->go_on == 1)
	normal_scatter(tmp, env, list, builtin - 20);
      tmp = tmp->next;
    }
  return (SUCCESS);
}
