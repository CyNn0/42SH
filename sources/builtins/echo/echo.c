/*
** echo.c for echo in /home/hubert_i/rendu/2015/PSU/42SH/sources/builtin
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Mon May 23 17:29:37 2016 Hubert Leo
** Last update Thu May 26 08:32:16 2016 Gambini Lucas
*/

#include "42.h"

char		is_in_quotes(char *cmd)
{
  if (cmd == NULL || strlen(cmd) <= 2)
    return (0);
  if (cmd[0] == '"' && cmd[strlen(cmd) - 1] == '"')
    puts("ok");
  return (1);
}

t_list		*builtin_echo(t_list *list, char **cmd)
{
  t_echo	*echo;
  int		i;
  int		j;

  if ((echo = init_echo()) == NULL)
    return (list);
  j = (i = 1) - 1;
  while (cmd[i])
    {
      if (echo->check_flags == 1 && strlen(cmd[i]) >= 1 && cmd[i][0] == '-')
	check_options(echo, cmd[i]);
      else
	{
	  if (j > 0)
	    write(1, " ", 1);
	  echo->check_flags = 0;
      	  echo_print(echo, cmd[i], list->myEnv);
	  j++;
      	}
      i++;
    }
  if (echo->flag_n == 0)
    write(1, "\n", 1);
  return (list);
}
