/*
** double_left.c for 42sh in C:\Users\gambin_l\42SH\sources\redirect
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Mon May 30 10:56:47 2016 Gambini Lucas
** Last update Mon May 30 12:15:56 2016 Gambini Lucas
*/

# include 		"42.h"

int             	double_left(t_cmd *cmd, t_list *list,
				    char **env, int builtin)
{
  t_red       		var;
  char			*buff;

  init_double_left(cmd->cmd, &var);
  var.is_builtin = builtin;
  write(1, "? ", 2);
  while ((buff = get_next_line(0)))
    {
      if (strcmp(buff, var.name) == 0)
	break;
      else
	list = dbleft_buffer(list, buff);
      free(buff);
      write(1, "? ", 2);
    }
  /* FONCTION D'EXEC ICI */
  (void)list;
  (void)env;
  /* OLIVE */
  free_list_dbleft(list);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
