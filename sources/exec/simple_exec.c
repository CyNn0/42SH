/*
** exec.c for exec in /home/puccio_c/rendu/minishell/42SH/sources/exec
**
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
**
** Started on  Mon May 23 13:05:23 2016 cyril puccio
** Last update Mon May 23 20:26:58 2016 boris saint-bonnet
*/

#include	"42.h"

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

static int		xwaitpid(int pid, int status, int opt)
{
  int			ret;

  ret = waitpid(pid, &status, opt);
  if (ret == -1)
    fprintf(stderr, "Can't perfom waitpid (pid = %d)\n", pid);
  if (WIFEXITED(status))
    status = WEXITSTATUS(status);
  else
    print_signal_message(status);
  return (ret);
}

static char		*parsing_cmd_exec_find_path(t_path *path, char *bin)
{
  t_node		*tmp;
  char			*cmd;

  tmp = path->head;
  while (tmp != NULL)
    {
      cmd = malloc(strlen(tmp->data) + strlen(bin) + 2);
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

int			simple_exec(t_cmd *cmd, t_path *path, char **env)
{
  int			status;
  pid_t			pid;

  if (path->head->data != NULL)
    {
      cmd->cmd[0] = parsing_cmd_exec_find_path(path, cmd->cmd[0]);
      if ((pid = fork()) == -1)
	fprintf(stderr, "Error: Fork Failed\n");
      else if (pid == 0)
	{
	  status = execve(cmd->cmd[0], cmd->cmd, env);
	  my_exit(status);
	}
      else
	xwaitpid(pid, 0, 0);
      if (!(access(cmd->cmd[0], F_OK)) && !((access(cmd->cmd[0], X_OK))))
	  return (SUCCESS);
    }
  return (FAILURE);
}
