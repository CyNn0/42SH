/*
** exec_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 20:22:56 2016 boris saint-bonnet
** Last update Tue May 24 17:54:53 2016 Gambini Lucas
*/

#include 		"42.h"

int                     exec_right(int fd, t_path *path,
				   char **env, t_right var)
{
  int                   status;
  pid_t                 pid;

  if (path->head->data != NULL)
    {
      var.cmd[0] = exec_find_path(path, var.cmd[0]);
      if ((pid = fork()) == -1)
	fprintf(stderr, "Error: Fork Failed\n");
      else if (pid == 0)
	{
	  dup2(fd, 1);
	  status = execve(var.cmd[0], var.cmd, env);
	  my_exit(status);
	}
      else
	xwaitpid(pid, 0, 0);
      if (!(access(var.cmd[0], F_OK)) && !((access(var.cmd[0], X_OK))))
	return (SUCCESS);
    }
  return (FAILURE);
}
