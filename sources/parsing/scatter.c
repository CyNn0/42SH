/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Gambini Lucas
** Last update Thu May 26 13:52:23 2016 Lucas Gambini
*/

#include	"42.h"

int		normal_scatter(t_cmd *cmd, char **env,
			       t_list *list, int builtin)
{
  (cmd->flag == SIMPLE_R) ? (simple_right(cmd, list, env, builtin))
    : ((cmd->flag == SIMPLE_L) ? (/*simple_left(cmd, list, env, builtin)*/printf("simple_l.\n"))
       : ((cmd->flag == DOUBLE_R) ? (double_right(cmd, list, env, builtin))
	  : ((cmd->flag == DOUBLE_L) ? (printf("DOUBLE_L\n"))
	     : ((simple_exec(cmd, list, env, builtin))))));
  return (SUCCESS);
}

int		exec_scatter(t_list *list)
{
  char		**env;
  t_cmd		*tmp;
  int		builtin;

  tmp = list->head;
  while (!(list->do_exit) && tmp && tmp->cmd[0])
    {
      env = extract_env(list->myEnv);
      if ((builtin = check_built(list, tmp)) == SUCCESS)
	return (SUCCESS);
      if (tmp->go_on == 1)
	normal_scatter(tmp, env, list, builtin - 20);
      tmp = tmp->next;
      free_tab(env);
    }
  return (SUCCESS);
}
