/*
** print.c for print in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Wed May 25 02:51:51 2016 Hubert Leo
** Last update	Wed Jun 01 15:00:24 2016 Hubert Leo
*/

#include "42.h"

void		put_echo(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    write(1, &str[i], 1);
}

void		print_e(char flag)
{
  flag == 'a' ? write(1, "\a", 1) :
    flag == 'b' ? write(1, "\b", 1) :
    flag == 't' ? write(1, "\t", 1) :
    flag == 'n' ? write(1, "\n", 1) :
    flag == 'v' ? write(1, "\v", 1) :
    flag == 'f' ? write(1, "\f", 1) :
    flag == 'r' ? write(1, "\r", 1) :
    (1);
}

int		echo_print(t_echo *flags, char *cmd)
{
  int		i;
  char		indooble;

  indooble = (i = -1) + 1;
  flags->space == 1 ? write(1, " ", 1) : 0;
  while (cmd[++i])
    {
      if (cmd[i] == '"' && indooble == 0)
	indooble = 1;
      else if (cmd[i] == '"' && indooble == 1)
	indooble = 0;
      else
	{
	  if (flags->flag_e == 1 && cmd[i] && cmd[i + 1]
	      && cmd[i] == '\\')
	    {
	      print_e(cmd[i + 1]);
	      i++;
	    }
	  else
	    indooble == 1 ? write(1, &cmd[i], 1)
	      : indooble == 0 && cmd[i] != '\\' ? write(1, &cmd[i], 1) : 0;
	}
    }
  return (0);
}
