/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Tue May 31 21:23:19 2016 Philippe Lefevre
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
  return (count_pipe);
}

int			exec_child(t_cmd *cmd, t_list *list, char **env,
				   int builtin)
{
  pid_t			pid;

  if (pipe(cmd->fd) == -1)
    fprintf(stderr, "Error: %s\n", strerror(errno));
  if ((pid = fork()) == -1)
    fprintf(stderr, "Error: %s\n", strerror(errno));
  else if (pid == 0)
    {
      if (cmd->prev && cmd->prev->token == PIPE)
	dup2(cmd->prev->fd[0], 0);
      dup2(cmd->fd[1], 1);
      normal_scatter(cmd, env, list, builtin - 20);
      my_exit(0);
    }
  /*
  else
    {
      next_cmd = cmd->next;
      normal_scatter(next_cmd, env, list, builtin - 20);
    }
  */
  close(cmd->fd[1]);
  return (SUCCESS);
}

int			exec_pipe(t_cmd *cmd, t_list *list, char **env,
				  int builtin)
{
  t_cmd			*tmp;
  int			count_pipe;
  int			cur;

  count_pipe = prepare_pipe(cmd);
  cur = -1;
  tmp = cmd;
  while (++cur < count_pipe)
    {
      fprintf(stderr, "===[%s]\n", tmp->cmd[0]);
      exec_child(cmd, list, env, builtin);
      tmp->go_on = 0;
      tmp = tmp->next;
    }
  return (SUCCESS);
}
