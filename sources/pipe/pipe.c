/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Fri May 27 20:26:16 2016 Philippe Lefevre
*/

#include		"42.h"

#include		<sys/wait.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<string.h>

int			exec_pipe(t_list *list)
{
  int			pipefd[2];
  pid_t			pid;
  char			buf;
  char			**env;
  t_cmd			*tmp;
  int			builtin;
  int			i;
  int			is_pipe_exec;

  tmp = list->head;
  is_pipe_exec = 0;
  while (tmp && tmp->cmd[0])
    {
      if (tmp->token == PIPE)
	is_pipe_exec = 1;
      tmp = tmp->next;
    }
  if (is_pipe_exec == 0)
    return (FAILURE);
  tmp = list->head;
  while (!(list->do_exit) && tmp && tmp->cmd[0])
    {
      free_tab(env);
      env = extract_env(list->myEnv);

      if (pipe(pipefd) == -1)
	{
	  perror("pipe");
	  exit(EXIT_FAILURE);
	}

      if ((pid = fork()) == -1)
	{
  	  perror("fork");
  	  exit(EXIT_FAILURE);
  	}
      else if (pid == 0)
	{
	  close(pipefd[1]);
	  if ((builtin = check_built(list, tmp)) == SUCCESS)
	    return (SUCCESS);
	  if (tmp->go_on == 1)
	    normal_scatter(tmp, env, list, builtin - 20);
	}
      else
	{
	  close(pipefd[0]);
          if ((builtin = check_built(list, tmp)) == SUCCESS)
	    return (SUCCESS);
	  if (tmp->go_on == 1)
	    normal_scatter(tmp, env, list, builtin - 20);
	  xwaitpid(pid, 0, 0);
        }

      tmp = tmp->next;
    }
  return (SUCCESS);
}
