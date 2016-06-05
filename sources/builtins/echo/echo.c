/*
** echo.c for echo in /home/hubert_i/rendu/2015/PSU/42SH/sources/builtin
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Mon May 23 17:29:37 2016 Hubert Leo
** Last update	Wed Jun 01 16:11:00 2016 Hubert Leo
*/

#include "42.h"

char		*preparsing_echo(t_echo *echo, char **cmd)
{
  char		*result;
  int		i;

  result = "\0";
  i = 0;
  if (cmd[echo->i + 1] != NULL)
    echo->i++;
  else
    return (NULL);
  while (cmd[echo->i])
    {
      if (i != 0)
	result = get_fusion(result, " ");
      result = get_fusion(result, cmd[echo->i]);
      echo->i++;
      i++;
    }
  return (result);
}

int		builtin_echo(t_list *list, char **cmd)
{
  t_echo	*echo;
  char		*printable;
  int		i;

  (void)list;
  if ((echo = init_echo()) == NULL)
    return (FAILURE);
  i = 1;
  while (cmd[i])
    {
      if (echo->check_flags == 1 && strlen(cmd[i]) >= 1 && cmd[i][0] == '-')
        {
	  check_options(echo, cmd[i]);
	  echo->i = i;
        }
      else
	{
	  echo->check_flags = 0;
	  if ((printable = preparsing_echo(echo, cmd)) != NULL)
	    {
	      echo_print(echo, printable);
	      xfree(printable);
	    }
	  break;
      	}
      i++;
    }
  if (echo->flag_n == 0)
    write(1, "\n", 1);
  return (SUCCESS);
}
