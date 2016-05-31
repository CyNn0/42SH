/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Tue May 31 22:23:52 2016 Philippe Lefevre
*/

#include		"42.h"

int			prepare_pipe(t_cmd *cmd, t_list *list)
{
  t_cmd			*tmp;
  int			count_pipe;
  int			out;

  tmp = cmd;
  count_pipe = 1;
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
	  printf("==[%s]\n", tmp->cmd[0]);
	  count_pipe += 1;
	}
      tmp = tmp->next;
    }
  if (out)
    return (out);
  return (count_pipe);
}

int			exec_child(t_cmd *cmd, t_list *list, char **env,
				   int builtin)
{
  pid_t			pid;

  if ((pipe(cmd->fd) == -1)
      || ((pid = fork()) == -1))
    {
      fprintf(stderr, "Error: %s\n", strerror(errno));
      exit(FAILURE);
    }
  else if (pid == 0)
    {
      if (cmd->token == PIPE)
	dup2(cmd->fd[1], 1);
      if (builtin >= 0)
	exit(simple_exec_builtin(list, cmd, builtin));
      execve(cmd->cmd[0], cmd->cmd, env);
      fprintf(stderr, "Error: %s %s\n", cmd->cmd[0], strerror(errno));
    }
  dup2(cmd->fd[0], 0);
  return (SUCCESS);
}

int			exec_pipe(t_cmd *cmd, t_list *list, char **env,
				  int builtin)
{
  t_cmd			*tmp;
  int			count_pipe;
  int			cur;
  int			back_stdin;

  if ((count_pipe = prepare_pipe(cmd, list)) == -1)
    return (FAILURE);
  back_stdin = dup(0);
  cur = 0;
  tmp = cmd;
  while (++cur < count_pipe)
    {
      exec_child(tmp, list, env, (builtin - 20));
      tmp->go_on = 0;
      tmp = tmp->next;
    }
  dup2(back_stdin, 0);
  return (SUCCESS);
}
