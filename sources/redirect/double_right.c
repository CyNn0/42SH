/*
** double_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 18:34:11 2016 boris saint-bonnet
** Last update Mon May 30 10:58:19 2016 Gambini Lucas
*/

# include 	"42.h"

int             double_right(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red       	var;
  int           fd;

  init_double(cmd->cmd, &var);
  var.is_builtin = builtin;
  if ((fd = open(var.name, __DOUBLE)) == -1)
    return (FAILURE);
  exec_right(fd, list, env, var);
  close(fd);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
