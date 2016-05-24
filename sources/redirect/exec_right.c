/*
** exec_right.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Mon May 23 20:22:56 2016 boris saint-bonnet
** Last update Mon May 23 21:47:35 2016 boris saint-bonnet
*/

#include "42.h"

int                     exec_right(t_cmd *cmd, t_path *path, char **env, t_right var)
{
  int                   status;
  pid_t                 pid;

  if (path->head->data != NULL)
    {
      var.cmd = exec_find_path(path, var.cmd);
      if ((pid = fork()) == -1)
	fprintf(stderr, "Error: Fork Failed\n");
      else if (pid == 0)
	{
	  status = execve(var.cmd, var.flag, env);
	  my_exit(status);
	}
      else
	xwaitpid(pid, 0, 0);
      if (!(access(var.cmd, F_OK)) && !((access(var.cmd, X_OK))))
	return (SUCCESS);
    }
  return (FAILURE);
}
