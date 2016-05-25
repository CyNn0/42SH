/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Lucas Gambini
** Last update Wed May 25 13:23:14 2016 Gambini Lucas
*/

#include	"42.h"

int		normal_scatter(t_cmd *cmd, char **env, t_path *path)
{
  (cmd->flag == SIMPLE_R) ? (simple_right(cmd, path, env))
    : ((cmd->flag == SIMPLE_L) ? (printf("SIMPLE_L\n"))
       : ((cmd->flag == DOUBLE_R) ? (double_right(cmd, path, env))
	  : ((cmd->flag == DOUBLE_L) ? (printf("DOUBLE_L\n"))
	     : ((simple_exec(cmd, path, env))))));
  return (SUCCESS);
}

int		exec_scatter(t_list *list)
{
  char		**env;
  t_cmd		*tmp;
  int		builtin;

  tmp = list->head;
  env = extract_env(list->myEnv);
  while (!(list->do_exit) && tmp && tmp->cmd[0])
    {
      builtin = check_built(list, tmp);
      printf("%d\n", tmp->is_builtin)
      if (tmp->go_on == 1)
	normal_scatter(tmp, env, list->path);
      tmp = tmp->next;
    }
  free_tab(env);
  return (SUCCESS);
}
