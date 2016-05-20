/*
** my_strcut.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 05:01:52 2016 boris saint-bonnet
** Last update Fri May 20 06:52:00 2016 boris saint-bonnet
*/

#include "42.h"

char    *my_strcut(char *s, int beg, int nb, int end)
{
  int   i;
  char  *ret;

  i = 0;
  if (nb > 0)
    {
      if ((ret = malloc(sizeof(char) * nb + 2)) == NULL)
	return (NULL);
      ret = memset(ret, 0, nb + 2);
      while ((s[beg + end]) != '\0' && i != nb)
	ret[i++] = s[beg++];
    }
  else
    {
      if ((ret = malloc(sizeof(char) * strlen(s) - beg + 1)) == NULL)
	return (NULL);
      while ((s[beg + end]) != '\0')
	ret[i++] = s[beg++];
    }
  ret[i] = '\0';
  return (ret);
}
