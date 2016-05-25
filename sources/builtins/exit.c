/*
** exit.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/builtins
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed May 25 11:24:01 2016 Philippe Lefevre
** Last update Wed May 25 12:28:39 2016 Philippe Lefevre
*/

#include		"42.h"

int			builtin_exit(t_list *list, char *str)
{
  char			*cmd;
  int			i;

  i = 0;
  cmd = strtok(str, " ");
  list->do_exit = 1;
  while ((cmd = strtok(NULL, " ")) != NULL)
    {
      list->value_exit = atoi(cmd);
      printf("(%d)\n", list->value_exit);
      i++;
    }
  if (i > 1)
    list->do_exit =
  fprintf(stderr, "exit: too many argumentsexit: too many arguments\n");
  else
    return (SUCCESS);
  list->value_exit = 0;
  return (FAILURE);
}
