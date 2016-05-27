/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Gambini Lucas
** Last update Fri May 27 08:03:33 2016 Philippe Lefevre
*/

#include		"42.h"

int			normal_scatter(t_cmd *cmd, char **env,
			       t_list *list, int builtin)
{
  (cmd->flag == SIMPLE_R) ? (simple_right(cmd, list, env, builtin))
      : ((cmd->flag == SIMPLE_L) ? (/*simple_left(cmd, list, env, builtin)*/printf("simple_l.\n"))
       : ((cmd->flag == DOUBLE_R) ? (double_right(cmd, list, env, builtin))
	  : ((cmd->flag == DOUBLE_L) ? (printf("DOUBLE_L\n"))
	     : ((simple_exec(cmd, list, env, builtin))))));
  return (SUCCESS);
}

int			exec_scatter(t_list *list)
{
  char		**env;
  t_cmd		*tmp;
  t_cmd		*tmp2;
  t_pipe	*tab_pipe;
  int		builtin;
  int		i;

  tmp = list->head;
  env = extract_env(list->myEnv);
  if ((tab_pipe = create_tab_linked_cmd(tmp)) == NULL)
    return (FAILURE);
  i  = -1;
  while (++i < tab_pipe[0].nb_pipe)
    {
      printf("Pipe numero %d\n", (i + 1));
      tmp2 = tab_pipe[i].beg;
      while (tmp2 != tab_pipe[i].end)
	{
	  printf("Pipe: Premiere command == [%s]\n", tmp->cmd[0]);
	  tmp2 = tmp2->next;
	}
    }
  while (!(list->do_exit) && tmp && tmp->cmd[0])
    {
      free_tab(env);
      env = extract_env(list->myEnv);
      if ((builtin = check_built(list, tmp)) == SUCCESS)
	return (SUCCESS);
      if (tmp->go_on == 1)
	normal_scatter(tmp, env, list, builtin - 20);
      tmp = tmp->next;
    }
  return (SUCCESS);
}
