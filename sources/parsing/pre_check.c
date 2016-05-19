/*
** pre_check.c for  in /home/xx/Rendu/PSU/42SH/sources
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:54:23 2016 boris saint-bonnet
** Last update Thu May 19 23:47:42 2016 Lucas Gambini
*/

# include "42.h"

char	*pre_check(char *s)
{
  char	*ret;

  if ((ret = strdup(s)) == NULL)
    return (s);
  ret = check_rednpipe(ret, '<');
  ret = check_rednpipe(ret, '>');
  ret = check_rednpipe(ret, '|');
  ret = check_separator(ret);
  ret = check_and(ret);
  return (ret);
}
