/*
** check_error.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Fri May 20 07:31:51 2016 boris saint-bonnet
** Last update Mon May 23 18:15:18 2016 Gambini Lucas
*/

# include "42.h"

int     check_finish(char *s, char c, int nb)
{
  int   i;
  int   ok;

  i = -1;
  ok = 0;
  if (nb == 1)
    {
      while (s[++i])
	if (s[i] == c && s[i - 1] && s[i + 1] != c &&
	    s[i - 1] && s[i - 1] != c)
	  if (s[i + 1] != ' ' || s[i - 1] != ' ')
	    ok++;
    }
  if (nb == 2)
    {
      while (s[++i])
	if (s[i] == c && s[i + 1] && s[i + 1] == c && s[i - 1])
	  if (s[i - 1] != ' ' || s[i + 2] != ' ')
	    ok++;
    }
  if (ok == 0)
    return (0);
  return (-1);
}

int     triple(char *s)
{
  int   i;
  int   j;
  char  *sep;

  i = -1;
  sep = strdup("&|<>;");
  while (s[++i])
    {
      j = 0;
      while (j < 6)
	{
	  if (s[i] == sep[j] && s[i + 1] == sep[j] && s[i + 2] == sep[j])
	    {
	      free(sep);
	      return (-1);
	    }
	  j++;
	}
    }
  free(sep);
  return (0);
}

int	check_error(char *s)
{
  if (s[0] != '&')
    if (triple(s) == -1 || s[0] == '|')
      {
	write (2, "Invalid null command.\n", strlen("Invalid null command.\n"));
	return (FAILURE);
      }
  return (SUCCESS);
}
