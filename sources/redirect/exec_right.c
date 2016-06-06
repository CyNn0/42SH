/*
** exec_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 20:22:56 2016 boris saint-bonnet
** Last update Mon Jun 06 06:14:37 2016 Philippe Lefevre
*/

#include 		"42.h"

int			exec_right_builtin(int fd, t_red var, t_list *list)
{
  int			(*p[5])(t_list*, char**);
  int			ret;
  int			reset;

  p[0] = &builtin_cd;
  p[1] = &builtin_setenv;
  p[2] = &builtin_unsetenv;
  p[3] = &builtin_echo;
  reset = dup(1);
  dup2(fd, 1);
  ret = p[var.is_builtin](list, var.cmd);
  dup2(reset, 1);
  return (ret);
}

int                     exec_right(int fd, t_list *list,
				   char **env, t_cmd *cmd)
{
  int                   status;
  int			reset;

  reset = dup(1);
  dup2(fd, 1);
  status = simple_exec(cmd, list, env, -20);
  dup2(reset, 1);
  return (status);
}
