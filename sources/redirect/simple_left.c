/*
** simple_left.c for simple_left in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Thu May 26 01:33:04 2016 Hubert Leo
** Last update Thu May 26 14:40:09 2016 boris saint-bonnet
*/

# include 	"42.h"

int		simple_left(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red		var;
  int		fd;

  init_simpleleft(cmd->cmd, &var);
  var.is_builtin = builtin;
  if ((fd = open(cmd->cmd[0], __SIMPLE)) == -1)
    return (FAILURE);
  if (exec_left(fd, list, env, var) == FAILURE)
    check_go_on(cmd);
  close(fd);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
