/*
** my_itoa.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/misc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sat Jun 04 15:38:06 2016 Philippe Lefevre
** Last update Sun Jun 05 01:14:59 2016 Philippe Lefevre
*/

#include		"42.h"

char			*my_itoa(int status)
{
  char			*data;
  int			digit;
  int			i;

  digit = 1;
  i = -1;
  if (status > 9)
    digit = 2;
  else if (status > 99)
    digit = 3;
  if ((data = malloc(digit + 1)) == NULL)
    return (NULL);
  while (++i < digit)
    {
      data[i] = (status % 10);
      status /= 10;
    }
  data[i] = '\0';
  return (data);
}
