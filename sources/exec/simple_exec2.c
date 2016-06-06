/*
** simple_exec2.c for simple_exec2 in /home/puccio_c/rendu/minishell/42SH/sources/exec
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Mon Jun  6 13:22:03 2016 cyril puccio
** Last update Mon Jun  6 13:32:07 2016 cyril puccio
*/

#include                "42.h"

void                    print_signal_message(int status)
{
  int                   i;
  t_error               error[11] =
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

int			simple_exec2(t_cmd *cmd, t_list *list, char **env)
{
  pid_t			pid;
  
  if ((pid = fork()) == -1)
    fprintf(stderr, "%s\n", strerror(errno));
  else if (pid == 0)
    {
      execve(cmd->cmd[0], cmd->cmd, env);
      fprintf(stderr, "%s: %s\n", cmd->cmd[0], strerror(errno));
      my_exit(FAILURE);
    }
  list->value_exit = 0;
  return (push_exit_value(list, pid));
}
