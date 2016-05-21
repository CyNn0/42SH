/*
** cmd_to_tab.c for cmd_to_tab in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Sat May 21 08:49:15 2016 Lucas Gambini
** Last update Sat May 21 08:51:29 2016 Lucas Gambini
*/

# include "42.h"

int		count_seg_nbr(char *line)
{
  int		i;
  int		flag;

  i = -1;
  flag = 0;
  while (line[++i])
    {
      if (line[i] == '|' || line[i] == ';' || line[i] == '&')
	{
	  flag++;
	  while (line[i] == '|' || line[i] == ';' || line[i] == '&')
	    i++;
	}
    }
  return (flag + 1);
}

int		count_seg_len(char *line)
{
  int		len;
  int		i;

  len = 0;
  i = -1;
  while (line[++i] != '|' && line[i] != ';' && line[i] != '&' && line[i])
    len++;
  return (len);
}

char		**cmd_to_tab(char *line)
{
  char		**tab;
  int		i;
  int		y;
  int		x;

  i = 0;
  x = -1;
  y = -1;
  if ((tab = malloc(sizeof(char*) * (count_seg_nbr(line) + 1))) == NULL)
    return (NULL);
  while (line[i])
    {
      if ((tab[++y] = malloc(sizeof(char) *
			     (count_seg_len(&line[i]) + 1))) == NULL)
	return (NULL);
      x = -1;
      while (line[i] != '|' && line[i] != ';' && line[i] != '&' && line[i])
	tab[y][++x] = line[i++];
      tab[y][++x] = 0;
      while ((line[i] == '|' || line[i] == ';' || line[i] == '&'
	      || line[i] == ' ') && line[i])
	i++;
    }
  tab[++y] = NULL;
  return (tab);
}
