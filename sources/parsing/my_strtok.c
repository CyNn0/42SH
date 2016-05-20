/*
** my_strtok.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Fri May 20 02:55:24 2016 boris saint-bonnet
** Last update Fri May 20 03:08:11 2016 boris saint-bonnet
*/

# include "42.h"

int     my_strcspn(char *str, char *srch)
{
  char  c;
  char  *p;
  char  *s;
  s = str;
  c = *s;
  while (c != 0)
    {
      p = srch;
      while (*p != 0)
	{
	  if (c == *p)
	    return (s - str);
	  p++;
	}
      s++;
      c = *s;
    }
  return (s - str);
}

int     my_strspn(char *p, char *s)
{
  int   i;
  int   j;
  i = 0;
  j = 0;
  while (p[i])
    {
      while (s[j])
	{
	  if (s[j] == p[i])
	    break;
	  j++;
	}
      if (!s[j])
	break;
      i++;
    }
  return (i);
}

char    *my_strtok(char *str, char *delim)
{
  static char   *p = 0;
  if (str)
    p = str;
  else if (!p)
    return 0;
  str = p + my_strspn(p, delim);
  p = str + my_strcspn(str, delim);
  if (p == str)
    return (p = 0);
  p = *p ? *p = 0, p + 1 : 0;
  return (str);
}
