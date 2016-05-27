/*
** exec_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 20:22:56 2016 boris saint-bonnet
** Last update Fri May 27 12:01:22 2016 Gambini Lucas
*/

#include 		"42.h"

int			exec_left_builtin(int fd, t_red var, t_list *list)
{
  int			(*p[5])(t_list*, char**);
  int			ret;
  int			reset;

  reset = dup(1);
  p[0] = &builtin_cd;
  p[1] = &builtin_setenv;
  p[2] = &builtin_unsetenv;
  p[3] = &builtin_echo;
  dup2(fd, 1);
  ret = p[var.is_builtin](list, var.cmd);
  dup2(reset, 1);
  return (ret);
}

int                     exec_left(int fd, t_list *list,
				   char **env, t_red var)
{
  int                   status;
  pid_t                 pid;

  if (var.is_builtin >= 0)
    return (exec_left_builtin(fd, var, list));
  else
    {
      if (list->path->head->data != NULL)
	{
	  var.cmd[0] = exec_find_path(list->path, var.cmd[0]);
	  if ((pid = fork()) == -1)
	    fprintf(stderr, "Error: Fork Failed\n");
	  else if (pid == 0)
	    {
	      dup2(fd, 0);
	      status = execve(var.cmd[0], var.cmd, env);
	      my_exit(status);
	    }
	  else
	    xwaitpid(pid, 0, 0);
	  if (!(access(var.cmd[0], F_OK)) && !((access(var.cmd[0], X_OK))))
	    return (SUCCESS);
	}
    }
  return (FAILURE);
}
