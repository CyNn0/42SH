/*
** simple_left.c for simple_left in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Thu May 26 01:33:04 2016 Hubert Leo
** Last update Mon Jun 06 15:06:00 2016 Philippe Lefevre
*/

# include 	"42.h"

int		simple_left(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red		var;
  int		fd;
  int		reset;

  (void)builtin;
  init_simpleleft(cmd, &var);
  if (!(cmd->go_on))
    return (FAILURE);
  if (cmd->prev && cmd->prev->token == PIPE)
    return (FAILURE + 0 * fprintf(stderr, "Ambiguous output redirect.\n"));
  var.is_builtin = builtin;
  if ((fd = open(var.name, O_RDONLY)) == -1)
    return (fprintf(stderr, "%s: %s\n",
		    var.name, strerror(errno)) * 0 + FAILURE);
  if (!var.cmd[0])
    return (SUCCESS);
  reset = dup(0);
  dup2(fd, 0);
  if (exec_left(list, env, cmd) == FAILURE)
    check_go_on(cmd);
  dup2(reset, 0);
  close(fd);
  xfree(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
