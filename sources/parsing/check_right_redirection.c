/*
** check_right_redirection.c for  in /home/xx/Rendu/PSU/42SH/sources
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:46:54 2016 boris saint-bonnet
** Last update Thu May 19 16:39:19 2016 Lucas Gambini
*/

# include "42.h"

char	*dep_right_redirection4(char *ret, int i)
{
  char	*bef;
  char	*aft;

  bef = my_strcut(ret, 0, (i + 5), 0);
  aft = my_strcut(ret, (i + 5), 0, 0);
  ret = my_strcatc(bef, aft);
  free(bef);
  free(aft);
  return (ret);
}

char	*dep_right_redirection3(char *ret, int i)
{
  char	*bef;
  char	*aft;

  bef = my_strcut(ret, 0, (i + 2), 0);
  aft = my_strcut(ret, (i + 2), 0, 0);
  ret = my_strcatc(bef, aft);
  free(bef);
  free(aft);
  return (ret);
}

char	*dep_right_redirection2(char *s, char *ret, int i)
{
  char  *bef;
  char  *aft;

  if (ret != NULL)
    {
      bef = my_strcut(ret, 0, (i + 2), 0);
      aft = my_strcut(ret, (i + 2), 0, 0);
    }
  else
    {
      bef = my_strcut(s, 0, (i + 1), 0);
      aft = my_strcut(s, (i + 1), 0, 0);
    }
  ret = my_strcatc(bef, aft);
  free(bef);
  free(aft);
  return (ret);
}

char	*dep_right_redirection1(char *s, char *ret, int i)
{
  char	*bef;
  char	*aft;

  bef = my_strcut(s, 0, i, 0);
  aft = my_strcut(s, i, 0, 0);
  ret = my_strcatc(bef, aft);
  free(bef);
  free(aft);
  return (ret);
}

char    *check_right_redirection(char *s)
{
  int   i;
  char  *ret;

  i = -1;
  ret = NULL;
  while (s[++i] != '\0')
    {
      if (s[i] == '>' && s[i - 1] != '>' && s[i + 1] != '>' && s[i - 1] != ' ')
	ret = dep_right_redirection1(s, ret, i);
      if (s[i] == '>' && s[i - 1] != '>' && s[i + 1] != '>' && s[i + 1] != ' ')
	ret = dep_right_redirection2(s, ret, i);
      if (s[i] == '>' && s[i + 1] == '>' && s[i - 1] != ' ')
	ret = dep_right_redirection3(ret, i);
      if (s[i] == '>' && s[i + 1] == '>' && s[i + 1] != ' ')
	ret = dep_right_redirection4(ret, i);
    }
  return ((ret == NULL) ? (s) : (ret));
}
