/*
** exec_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 20:22:56 2016 boris saint-bonnet
** Last update Mon Jun 06 14:23:16 2016 Philippe Lefevre
*/

#include 		"42.h"

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
