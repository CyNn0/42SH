/*
** check_and.c for  in /home/xx/Rendu/PSU/42SH/sources
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Wed May 18 04:53:00 2016 boris saint-bonnet
** Last update Wed May 18 06:40:19 2016 boris saint-bonnet
*/

# include "42.h"

char    *check_and(char *s)
{
  int   i;
  char  *bef;
  char  *aft;
  char  *ret;

  i = -1;
  ret = NULL;
  while (s[++i] != '\0')
    {
      if (s[i] == '&' && s[i - 1] != '&' && s[i + 1] != '&' && s[i - 1] != ' ')
	{
	  bef = my_strcut(s, 0, i, 0);
	  aft = my_strcut(s, i, 0, 0);
	  ret = my_strcatc(bef, aft);
	}
      if (s[i] == '&' && s[i - 1] != '&' && s[i + 1] != '&' && s[i + 1] != ' ')
	{
	  bef = my_strcut(ret, 0, (i + 2), 0);
	  aft = my_strcut(ret, (i + 2), 0, 0);
	  ret = my_strcatc(bef, aft);
	}
      if (s[i] == '&' && s[i + 1] == '&' && s[i - 1] != ' ')
	{
	  bef = my_strcut(ret, 0, (i + 2), 0);
	  aft = my_strcut(ret, (i + 2), 0, 0);
	  ret = my_strcatc(bef, aft);
	}
      if (s[i] == '&' && s[i + 1] == '&' && s[i + 1] != ' ')
	{
	  bef = my_strcut(ret, 0, (i + 5), 0);
	  aft = my_strcut(ret, (i + 5), 0, 0);
	  ret = my_strcatc(bef, aft);
	}
    }
  if (ret == NULL)
    return (s);
  return (ret);
}
