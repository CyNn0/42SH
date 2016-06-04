/*
** pre_check.c for  in /home/xx/Rendu/PSU/42SH/sources
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:54:23 2016 boris saint-bonnet
** Last update Sat Jun  4 14:40:51 2016 boris saint-bonnet
*/

#include	"42.h"

char		*my_strcatc(char *path, char *command, int cond, int bool)
{
  char		*ret;
  int		i;
  int		j;

  if (path == NULL || command == NULL
      || (ret = malloc(sizeof(char) *
		       (strlen(path) + strlen(command) + 2))) == NULL)
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

char		*clean_str(char *str)
{
  int		i;
  int		j;
  char		*ret;

  i = 0;
  j = -1;
  if ((ret = malloc(sizeof(char) * ((int)strlen(str) + 1))) == NULL)
    {
      free(str);
      return (NULL);
    }
  while (i < (int)strlen(str) && (str[i] == ' ' || str[i] == '\t'))
    i++;
  i--;
  while (str[++i])
    {
      if (str[i] != ' ' && str[i] != '\t')
        ret[++j] = str[i];
      else if ((str[i] == '\t' && str[i + 1] != '\t' && str[i + 1] != ' ') ||
               (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\t'))
        ret[++j] = ' ';
    }
  ret[++j] = '\0';
  free(str);
  return (ret);
}

char		*pre_check(char *s, t_list *list)
{
  char		*ret;

  ret = strdup(s);
  free(s);
  if (check_error(ret) == FAILURE)
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
  ret = replace_variable(ret, list);
  printf("%s\n", ret);
  return (clean_str(ret));
}
