/*
** simple_exec.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/exec
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 23:00:09 2016 Philippe Lefevre
** Last update Thu May 26 14:54:18 2016 Gambini Lucas
*/

#include		"42.h"

void			print_signal_message(int status)
{
  int			i;
  t_error   		error[11] =
  {
    {SIGHUP, "Hangup"},
    {SIGQUIT, "Quit (core dumped)"},
    {SIGABRT, "Abort (core dumped)"},
    {SIGBUS, "Bus error (core dumped)"},
    {SIGFPE, "Floating exception (core dumped)"},
    {SIGKILL, "Killed"},
    {SIGUSR1, "User signal 1"},
    {SIGSEGV, "Segmentation fault (core dumped)"},
    {SIGUSR2, "User signal 2"},
    {SIGPIPE, "Broken pipe"},
    {SIGTERM, "Terminated"},
  };

  if (WIFSIGNALED(status))
    {
      status = WTERMSIG(status);
      i = -1;
      while (++i < 11)
	if (status == error[i].error_status)
	    fprintf(stderr, "%s\n", error[i].error);
    }
}

 int			xwaitpid(int pid, int status, int opt)
{
  int			ret;

  ret = waitpid(pid, &status, opt);
  if (ret == -1)
    fprintf(stderr, "Error: %s\n", strerror(errno));
  if (WIFEXITED(status))
    status = WEXITSTATUS(status);
  else
    print_signal_message(status);
  return (ret);
}

char			*exec_find_path(t_path *path, char *bin)
{
  t_node		*tmp;
  char			*cmd;

  tmp = path->head;
  while (tmp != NULL)
    {
      if ((cmd = malloc(strlen(tmp->data) + strlen(bin) + 2)) == NULL)
	 return (NULL);
      cmd = strcpy(cmd, tmp->data);
      cmd = strcat(cmd, "/");
      cmd = strcat(cmd, bin);
      if (!(access(cmd, F_OK)) && !((access(cmd, X_OK))))
	{
	  free(bin);
	  return (cmd);
	}
      free(cmd);
      tmp = tmp->next;
    }
  return (bin);
}

int			simple_exec_builtin(t_list *list, t_cmd *cmd,
					    int	builtin)
{
    int			(*p[5])(t_list*, char**);

    /*p[0] = &exec_cd;*/
    p[1] = &builtin_setenv;
    p[2] = &builtin_unsetenv;
    p[3] = &builtin_echo;
    if (p[builtin](list, cmd->cmd) == FAILURE)
      {
	check_go_on(cmd);
	return (FAILURE);
      }
    return (SUCCESS);
}

int			simple_exec(t_cmd *cmd, t_list *list,
				    char **env, int builtin)
{
  pid_t			pid;

  if (builtin >= 0)
    return (simple_exec_builtin(list, cmd, builtin));
  if (list->path->head && list->path->head->data != NULL)
    {
      if ((cmd->cmd[0] = exec_find_path(list->path, cmd->cmd[0])) == NULL)
	return (FAILURE);
      if (!(access(cmd->cmd[0], X_OK)))
	{
	  if ((pid = fork()) == -1)
	    fprintf(stderr, "Error: %s\n", strerror(errno));
	  else if (pid == 0)
	    {
	      execve(cmd->cmd[0], cmd->cmd, env);
	      fprintf(stderr, "Error: %s\n", strerror(errno));
	    }
	  else
	    xwaitpid(pid, 0, 0); /* setenv $? avec le retour de la fonction */
	  return (SUCCESS);
	}
    }
  fprintf(stderr, "%s: Command not found.\n", cmd->cmd[0]);
  check_go_on(cmd);
  return (FAILURE);
}
