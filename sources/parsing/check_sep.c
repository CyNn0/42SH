/*
** check_sep.c for  in /home/xx/Rendu/PSU/42SH/sources
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:46:54 2016 boris saint-bonnet
** Last update Fri May 20 01:24:38 2016 Lucas Gambini
*/

# include "42.h"

char	*dep_4(char *s, char *ret, int i, char sep)
{
  char	*bef;
  char	*aft;

  (void)sep;
  if (ret != NULL)
    {
      bef = my_strcut(ret, 0, (i + 5), 0);
      aft = my_strcut(ret, (i + 5), 0, 0);
    }
  else
    {
      bef = my_strcut(s, 0, (i + 2), 0);
      aft = my_strcut(s, (i + 4), 0, 0);
    }
  ret = my_strcatc(bef, aft);
  free(bef);
  free(aft);
  return (ret);
}

char	*dep_3(char *ret, int i)
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

char	*dep_2(char *s, char *ret, int i)
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

char	*dep_1(char *s, char *ret, int i)
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

char    *check_sep(char *s, char sep)
{
  int   i;
  char  *ret;

  i = -1;
  ret = NULL;
  while (s[++i] != '\0')
    {
      if (s[i] == sep && s[i - 1] != sep && s[i + 1] != sep && s[i - 1] != ' ')
	ret = dep_1(s, ret, i);
      if (s[i] == sep && s[i - 1] != sep && s[i + 1] != sep && s[i + 1] != ' ')
	ret = dep_2(s, ret, i);
      if (s[i] == sep && s[i + 1] == sep && s[i - 1] != ' ')
	ret = dep_3(ret, i);
      if (s[i] == sep && s[i + 1] == sep && s[i + 1] != ' ')
	ret = dep_4(s, ret, i, sep);
    }
  return ((ret == NULL) ? (s) : (ret));
}
