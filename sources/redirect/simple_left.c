/*
** simple_left.c for simple_left in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Thu May 26 01:33:04 2016 Hubert Leo
** Last update Tue May 31 10:25:12 2016 Gambini Lucas
*/

# include 	"42.h"

int		simple_left(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red		var;
  int		fd;
  int		reset;

  init_simpleleft(cmd->cmd, &var);
  var.is_builtin = builtin;
  if ((fd = open(var.name, O_RDONLY)) == -1)
    return (fprintf(stderr, "Error: %s: %s\n", strerror(errno),
		    var.name) * 0 + FAILURE);
  reset = dup(0);
  cmd->pipefd = dup(fd);
  dup2(fd, 0);
  if (exec_left(list, env, var) == FAILURE)
    check_go_on(cmd);
  dup2(reset, 0);
  close(fd);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
