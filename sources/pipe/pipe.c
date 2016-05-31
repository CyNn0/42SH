/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Tue May 31 15:29:27 2016 Philippe Lefevre
*/

#include		"42.h"

int			exec_pipe(t_cmd *cmd, t_list *list, char **env,
				  int builtin)
{
  int			back_stdin;
  pid_t			pid;
  t_cmd			*next_cmd;

  back_stdin = dup(0);
  if (pipe(cmd->fd) == -1)
    fprintf(stderr, "Error: pipe failure\n");
  if ((pid = fork()) == -1)
    fprintf(stderr, "Error: fork failure\n");
  else if (pid == 0)
    {
      if (cmd->prev && cmd->prev->token == PIPE)
	dup2(cmd->fd[0], cmd->prev->fd[0]);
      else
	{
	  dup2(cmd->fd[1], 1);
	  normal_scatter(cmd, env, list, builtin - 20);
	}
      list->do_exit = 1;
      list->value_exit = 0;
      return (SUCCESS);
    }
  else
    xwaitpid(pid, 0, 0);
  next_cmd = cmd->next;
  if (next_cmd->next == NULL || next_cmd->next->token != PIPE)
    {
      dup2(cmd->fd[0], 0);
      normal_scatter(next_cmd, env, list, builtin - 20);
    }
  dup2(back_stdin, 0);
  return (SUCCESS);
}
