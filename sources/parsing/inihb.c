/*
** inihb.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Tue May 31 13:35:13 2016 boris saint-bonnet
** Last update Tue May 31 13:35:38 2016 boris saint-bonnet
*/

#include "42.h"

int	check_inihb(char *str)
{
  int	nb;

  nb = 0;
  while (*str)
    {
      if (*str == '"')
	nb++;
      str++;
    }
  return (nb == 2 ? SUCCESS : FAILURE);
}

char		*my_inihb(char *str)
{
  int		beg;
  int		i;

  i = -1;
  if (!str)
    return (NULL);
  if (check_inihb(str) == FAILURE)
    return (str);
  while (str[++i] != '"');
  beg = i;
  while (str[++i] != '"');
  return (my_strcut(str, (beg + 1), 0, (strlen(str) - i)));
}
