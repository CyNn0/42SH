/*
** pre_check.c for  in /home/xx/Rendu/PSU/42SH/sources
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:54:23 2016 boris saint-bonnet
** Last update Sat May 21 01:29:06 2016 boris saint-bonnet
*/

# include "42.h"

char    *my_strcatc(char *path, char *command, int cond, int bool)
{
  char  *ret;
  int   i;
  int   j;
  
  if (path == NULL || command == NULL
      || (ret = malloc(sizeof(char) * (strlen(path) +
				       strlen(command) + 2))) == NULL)
    return (NULL);
  i = -1;
  while (path[++i] != '\0')
    ret[i] = path[i];
  if (cond == 1)
    ret[i++] = '/';
  if (cond == 2)
    ret[i++] = '=';
  if (cond == 3)
    ret[i++] = ' ';
  j = 0;
  while (command[j] != '\0')
    ret[i++] = command[j++];
  ret[i] = '\0';
  if (bool >= 0)
    free (path);
  return (ret);
}

char	*pre_check(char *s)
{
  char  *ret;

  ret = strdup(s);
  free(s);
  if (triple(ret) == -1)
    {
      free(ret);
      return (NULL);
    }
  ret = simples(ret, '&');
  ret = simples(ret, ';');
  ret = simples(ret, '<');
  ret = simples(ret, '>');
  ret = simples(ret, '|');
  ret = doubles(ret, '>');
  ret = doubles(ret, '<');
  ret = doubles(ret, '&');
  ret = doubles(ret, ';');
  ret = doubles(ret, '|');  
  return (ret);
}
