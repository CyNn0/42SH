/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Gambini Lucas
** Last update Sat May 28 10:26:17 2016 Gambini Lucas
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

int			prepare_pipe(t_cmd *tmp)
{
  int			i;
  t_cmd			*tmp2;
  t_pipe		*tab_pipe;

  if ((tab_pipe = create_tab_linked_cmd(tmp)) == NULL)
    return (FAILURE);
  i  = -1;
  while (++i < tab_pipe[0].nb_pipe)
    {
      printf("lefevr == [here]\n");
      tmp2 = tab_pipe[i].beg;
      while (tmp2 != tab_pipe[i].end)
	{
	  printf("lefevr == [%s]\n", tmp->cmd[0]);
	  tmp2 = tmp2->next;
	}
    }
  return (SUCCESS);
}

int			exec_scatter(t_list *list)
{
  char		**env;
  t_cmd		*tmp;
  int		builtin;

  tmp = list->head;
  env = extract_env(list->myEnv);
  if (prepare_pipe(tmp) == FAILURE)
    return (FAILURE);
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
