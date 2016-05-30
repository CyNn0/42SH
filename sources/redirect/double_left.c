/*
** double_left.c for 42sh in C:\Users\gambin_l\42SH\sources\redirect
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Mon May 30 10:56:47 2016 Gambini Lucas
** Last update Mon May 30 16:59:06 2016 Philippe Lefevre
*/

#include 		"42.h"

int			double_left_exec(t_cmd *cmd, t_list *list,
					 char **env, int builtin)
{
  t_dbleft		*tmp;

  tmp = list->dbleftptr->head;
  while (tmp != NULL)
    {
      fprintf(stdin, "[%s]\n", tmp->line);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int             	double_left(t_cmd *cmd, t_list *list,
				    char **env, int builtin)
{
  t_red       		var;
  char			*buff;
  int			reset;

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
  double_left_exec(cmd, list, env, builtin);
  free_list_dbleft(list);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
