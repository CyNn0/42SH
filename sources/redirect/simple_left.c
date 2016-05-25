/*
** simple_left.c for simple_left in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Thu May 26 01:33:04 2016 Hubert Leo
** Last update Thu May 26 01:34:05 2016 Hubert Leo
*/

# include 	"42.h"

int		simple_left(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_right	var;
  int		fd;

  init_var(cmd->cmd, &var);
  var.is_builtin = builtin;
  if ((fd = open(cmd->cmd[0], __SIMPLE)) == -1)
    return (FAILURE);
  exec_left(fd, list, env, var);
  close(fd);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
