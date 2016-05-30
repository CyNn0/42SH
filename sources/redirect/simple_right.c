/*
** simple_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 17:57:28 2016 boris saint-bonnet
** Last update Mon May 30 14:50:59 2016 Gambini Lucas
*/

#include 	"42.h"

int		simple_right(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red		var;
  int		fd;

  init_var(cmd->cmd, &var);
  var.is_builtin = builtin;
  if (strcmp(var.name, "42sh") == 0)
    return (FAILURE);
  if ((fd = open(var.name, __SIMPLE)) == -1)
    return (fprintf(stderr, "Error: %s: %s\n", strerror(errno),
		    var.name) * 0 + FAILURE);
  if (exec_right(fd, list, env, var) == FAILURE)
    check_go_on(cmd);
  close(fd);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
