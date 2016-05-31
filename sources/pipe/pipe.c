/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Wed Jun 01 01:45:33 2016 Philippe Lefevre
*/

#include		"42.h"

int			prepare_pipe(t_cmd *cmd, t_list *list)
{
  t_cmd			*tmp;
  int			count_pipe;
  int			out;

  tmp = cmd;
  count_pipe = 0;
  out = 0;
  while (tmp)
    {
      if (tmp->token == PIPE || (tmp->prev && tmp->prev->token == PIPE))
	{
	  if ((out == 0) && (tmp->cmd[0] =
			     exec_find_path(list->path, tmp->cmd[0])) == NULL)
	    {
	      fprintf(stderr, "%s: Command not found.\n", tmp->cmd[0]);
	      out = -1;
	    }
	  tmp->go_on = 0;
	  count_pipe += 1;
	}
      tmp = tmp->next;
    }
  if (out)
    return (out);
  return (count_pipe);
}

int			exec_child(t_cmd *cmd, t_list *list, char **env,
				   int count[2])
{
  pid_t			pid;

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
      /*if ((builtin = check_built(list, cmd)) >= 0)
	exit(simple_exec_builtin(list, cmd, builtin));*/
      execve(cmd->cmd[0], cmd->cmd, env);
      exit(-1);
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
  if ((count[1] = prepare_pipe(cmd, list)) == -1)
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
  return (SUCCESS);
}
