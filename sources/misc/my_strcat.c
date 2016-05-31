/*
** my_strcat.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Tue May 31 17:29:49 2016 boris saint-bonnet
** Last update Tue May 31 17:30:58 2016 boris saint-bonnet
*/

#include		"42.h"

char			*my_strcat(char *dest, char *src)
{
  char			*result;
  int			len;
  int			i;

  i = 0;
  len = 0;
  if ((result = malloc(strlen(dest) + strlen(src) + 1)) == NULL)
    my_exit(FAILURE);
  while (dest[i])
    {
      result[i] = dest[i];
      i++;
    }
  while (src[len])
    {
      result[len + i] = src[len];
      len++;
    }
  result[len + i] = '\0';
  return (result);
}
