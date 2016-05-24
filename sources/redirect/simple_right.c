/*
** simple_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 17:57:28 2016 boris saint-bonnet
** Last update Wed May 25 01:09:20 2016 boris saint-bonnet
*/

# include 	"42.h"

int		simple_right(t_cmd *cmd, t_path *path, char **env)
{
  t_right	var;
  int		fd;

  init_var(cmd->cmd, &var);
  if ((fd = open(var.name, __SIMPLE)) == -1)
    return (FAILURE);
  exec_right(fd, path, env, var);
  close(fd);
  return (SUCCESS);
}
