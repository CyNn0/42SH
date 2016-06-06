/*
** simple_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 17:57:28 2016 boris saint-bonnet
** Last update Mon Jun  6 19:24:43 2016 cyril puccio
*/

#include 	"42.h"

int		simple_right(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red		var;
  int		fd;

  (void)builtin;
  init_var(cmd, &var);
  if (!(cmd->go_on))
    return (FAILURE);
  if (cmd->token == PIPE)
    return (FAILURE + 0 * fprintf(stderr, "Ambiguous output redirect.\n"));
  if (var.cmd == NULL || var.name == NULL)
    return (FAILURE);
  if ((fd = open(var.name, __SIMPLE)) == -1)
    return (fprintf(stderr, "%s: %s\n",
		    var.name, strerror(errno)) * 0 + FAILURE);
  if (!env[0] || !cmd->cmd[0])
    return (SUCCESS);
  if (exec_right(fd, list, env, cmd) == FAILURE)
    check_go_on(cmd);
  close(fd);
  xfree(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
