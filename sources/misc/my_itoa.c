/*
** my_itoa.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/misc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sat Jun 04 15:38:06 2016 Philippe Lefevre
** Last update Sat Jun 04 23:48:01 2016 Philippe Lefevre
*/

#include		"42.h"

char			*my_itoa(char *str)
{
  int			digit;

  digit = 0;
  while (digit < 10)
    {
      text[6] = digit + '0';
      puts(text);
    }
  return 0;
}
