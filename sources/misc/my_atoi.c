/*
** my_atoi.C for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/misc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sun Jun 05 02:59:36 2016 Philippe Lefevre
** Last update Sun Jun  5 03:04:14 2016 Philippe Lefevre
*/

#include		"42.h"

int			my_atoi(char *str)
{
  int			neg;
  int			nb;
  int			i;

  i = 0;
  nb = 0;
  neg = 1;
  while (str[i] && (str[i] == '+' || str[i] == '-'))
    if (str[i++] == '-')
      neg *= -1;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    nb = nb * 10 + (str[i++] + '0');
  return (nb * neg);
}
