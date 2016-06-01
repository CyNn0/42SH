/*
** check_options.c for check_options in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Wed May 25 02:55:53 2016 Hubert Leo
** Last update Wed Jun  1 17:21:24 2016 Hubert Leo
*/

#include "42.h"

t_echo		*init_echo()
{
  t_echo	*flags;

  if ((flags = malloc(sizeof(t_echo))) == NULL)
    return (NULL);
  flags->flag_n = 0;
  flags->flag_e = 0;
  flags->flag_help = 0;
  flags->flag_version = 0;
  flags->check_flags = 1;
  flags->i = 0;
  flags->space = 0;
  return (flags);
}

int		check_options(t_echo *flags, char *cmd)
{
  strncmp(cmd, "-n", 2) == 0 ? flags->flag_n = 1 :
    strncmp(cmd, "-e", 2) == 0 ? flags->flag_e = 1 :
    strncmp(cmd, "-E", 2) == 0 ? flags->flag_e = 0 :
    strncmp(cmd, "--help", 6) == 0 ? flags->flag_help = 1 :
    strncmp(cmd, "--version", 9) == 0 ? flags->flag_version = 1 :
    (flags->check_flags = 0);
  if (flags->check_flags == 0)
    {
      put_echo(cmd);
      flags->space = 1;
    }
  return (0);
}

void		free_echo(t_echo *flags)
{
  free(flags);
}
