/*
** double_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 18:34:11 2016 boris saint-bonnet
** Last update Mon Jun 06 15:36:45 2016 Philippe Lefevre
*/

# include 	"42.h"

int             double_right(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red       	var;
  int           fd;

  init_double(cmd, &var);
  if (!(cmd->go_on))
    return (FAILURE);
  var.is_builtin = builtin;
  if ((fd = open(var.name, __DOUBLE)) == -1)
    return (fprintf(stderr, "%s: %s\n", var.name, strerror(errno)) * 0 + FAILURE);
  if (!var.cmd[0])
    return (SUCCESS);
  exec_right(fd, list, env, cmd);
  close(fd);
  xfree(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
