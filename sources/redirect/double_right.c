/*
** double_right.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Mon May 23 18:34:11 2016 boris saint-bonnet
** Last update Mon May 23 18:42:44 2016 boris saint-bonnet
*/

# include "42.h"

int		double_right(t_cmd *cmd, t_path *path, char **env)
{
  t_right       var;

  var = parsing_sr(cmd->cmd);
  if ((fd = open(__DOUBLE)) == -1)
    return (FAILURE);
  dup2(fd, 1);
  simple_exec(cmd, path, env);
  dup2(fd, 1);
  return (SUCCES);
}
