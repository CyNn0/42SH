/*
** simple_left.c for simple_left in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Thu May 26 01:33:04 2016 Hubert Leo
** Last update Sat May 28 14:04:35 2016 Gambini Lucas
*/

# include 	"42.h"

int		simple_left(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red		var;

  init_simpleleft(cmd->cmd, &var);
  var.is_builtin = builtin;
  if (exec_left(list, env, var) == FAILURE)
    check_go_on(cmd);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
