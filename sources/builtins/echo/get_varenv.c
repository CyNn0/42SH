/*
** get_varenv.c for get_varenv in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Wed May 25 02:54:35 2016 Hubert Leo
** Last update Wed May 25 03:02:11 2016 Hubert Leo
*/

#include "42.h"

int		count_to_space(char *cmd, int i)
{
  while (cmd[i])
    {
      if (cmd[i] == ' ' || cmd[i] == '\t')
	return (i);
      i++;
    }
  return (i);
}

char		*get_varenv(char *cmd, int i, int to_space)
{
  char		*search;
  int		j;

  if ((search = malloc(to_space + 1)) == NULL)
    return (NULL);
  j = 0;
  while (i < to_space)
    {
      search[j] = cmd[i];
      j++;
      i++;
    }
  search[j] = '\0';
  return (search);
}
