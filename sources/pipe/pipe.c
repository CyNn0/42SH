/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Mon May 30 23:16:59 2016 Philippe Lefevre
*/

#include		"42.h"

int			exec_pipe(t_cmd *cmd, t_list *list, char **env,
				  int builtin)
{
  int			pipefd[2];
  int			back_stdin;
  pid_t			pid;
  t_cmd			*next_cmd;

  back_stdin = dup(0);
  if (pipe(pipefd) == -1)
    fprintf(stderr, "Error: pipe failure\n");
  if ((pid = fork()) == -1)
    fprintf(stderr, "Error: fork failure\n");
  else if (pid == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      if (cmd->prev && cmd->prev->token != PIPE)
	dup2(0, cmd->prev->pipefd);
      else
	{
	  normal_scatter(cmd, env, list, builtin - 20);
	  list->do_exit = 1;
	  list->value_exit = 0;
	}
      close(pipefd[1]);
      exit(0);
    }
  else
    {
      xwaitpid(pid, 0, 0);
      next_cmd = cmd->next;
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      close(pipefd[0]);
      normal_scatter(next_cmd, env, list, builtin - 20);
      next_cmd->pipefd = dup(0);
    }
  dup2(back_stdin, 0);
  next_cmd->go_on = 0;
  return (SUCCESS);
}
