/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Tue May 31 20:34:18 2016 Philippe Lefevre
*/

#include		"42.h"

int			prepare_pipe(t_cmd *cmd)
{
  t_cmd			*tmp;
  int			count_pipe;

  tmp = cmd;
  count_pipe = 1;
  while (tmp)
    {
      if (tmp->token == PIPE)
	count_pipe += 1;
      tmp = tmp->next;
    }
  tmp = cmd;
  while (count_pipe--)
    {
      tmp->go_on = 0;
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int			exec_pipe(t_cmd *cmd, t_list *list, char **env,
				  int builtin)
{
  pid_t			pid;
  t_cmd			*next_cmd;
  t_cmd			*tmp;

  prepare_pipe(cmd);
  tmp = cmd;
  while (tmp && tmp->token == PIPE)
    {
      fprintf(stderr, "Pipe [%s]\n", tmp->cmd[0]);
      tmp = tmp->next;
    }
  /*
  if ((pid = fork()) == -1)
    fprintf(stderr, "Error: fork failure\n");
  else if (pid == 0)
    {
      dup2(cmd->fd[1], 1);
      normal_scatter(cmd, env, list, builtin - 20);
      list->do_exit = 1;
      list->value_exit = 0;
      return (SUCCESS);
    }
  else
    {
      xwaitpid(pid, 0, 0);
      next_cmd = cmd->next;
      close(cmd->fd[1]);
      dup2(cmd->fd[0], 0);
      dup2(next_cmd->fd[0], 0);
      normal_scatter(next_cmd, env, list, builtin - 20);
    }
  */
  return (SUCCESS);
}
