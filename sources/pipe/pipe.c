/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Mon May 30 12:24:42 2016 Philippe Lefevre
*/

#include		"42.h"

#include		<sys/wait.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<string.h>

int			exec_pipe(t_cmd *cmd, t_list *list, char **env,
				  int builtin)
{
  int			pipefd[2];
  pid_t			pid;
  t_cmd			*next_cmd;

  if (pipe(pipefd) == -1)
    fprintf(stderr, "Error: pipe failure\n");
  if ((pid = fork()) == -1)
    fprintf(stderr, "Error: fork failure\n");
  else if (pid == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      close(pipefd[1]);
      if (builtin >= 0)
	simple_exec_builtin(list, cmd, builtin);
      else
	simple_exec(cmd, list, env, -1);
      list->do_exit = 1;
      list->value_exit = 0;
      return (SUCCESS);
    }
  else
    {
      xwaitpid(pid, 0, 0);
      next_cmd = cmd->next;
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      close(pipefd[0]);
      if (builtin >= 0)
	simple_exec_builtin(list, next_cmd, builtin);
      else
	simple_exec(next_cmd, list, env, -1);
    }
  return (SUCCESS);
}
