/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Wed Jun 01 03:28:02 2016 Philippe Lefevre
*/

#include		"42.h"

int			prepare_pipe(t_cmd *cmd)
{
  t_cmd			*tmp;
  int			count_pipe;

  count_pipe = 0;
  tmp = cmd;
  while (tmp)
    {
      if (tmp->token == PIPE || (tmp->prev && tmp->prev->token == PIPE))
	{
	  tmp->go_on = 0;
	  count_pipe += 1;
	}
      tmp = tmp->next;
    }
  return (count_pipe);
}

int			exec_child(t_cmd *cmd, t_list *list, char **env,
				   int count[2])
{
  pid_t			pid;
  int			builtin;

  if ((cmd->fd = malloc(sizeof(int) * 2)) == NULL)
    return (FAILURE);
  if ((pipe(cmd->fd) == -1)
      || ((pid = fork()) == -1))
    {
      fprintf(stderr, "Error: %s\n", strerror(errno));
      exit(FAILURE);
    }
  else if (pid == 0)
    {
      if (count[0] != 0)
	dup2(cmd->prev->fd[0], 0);
      if (count[0] < (count[1] - 1))
	dup2(cmd->fd[1], 1);
      if ((builtin = check_built(list, cmd)) == SUCCESS)
	return (SUCCESS);
      exit(normal_scatter(cmd, env, list, builtin - 20));
    }
  else
    {
      if (count[0] != 0)
	close(cmd->prev->fd[0]);
      if (count[0] < count[1] - 1)
	close(cmd->fd[1]);
    }
  return (SUCCESS);
}

int			exec_pipe(t_cmd *cmd, t_list *list, char **env,
				  int builtin)
{
  t_cmd			*tmp;
  int			count[2];
  int			cur;

  (void)builtin;
  if ((count[1] = prepare_pipe(cmd)) == -1)
    return (FAILURE);
  cur = 0;
  tmp = cmd;
  while (cur < count[1])
    {
      count[0] = cur;
      exec_child(tmp, list, env, count);
      tmp = tmp->next;
      cur++;
    }
  while (waitpid(-1, 0, 0) != -1);
  return (SUCCESS);
}
