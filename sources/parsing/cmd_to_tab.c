/*
** cmd_to_tab.c for cmd_to_tab in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Sat May 21 08:49:15 2016 Lucas Gambini
** Last update Sat May 21 10:40:58 2016 Lucas Gambini
*/

# include "42.h"

int		count_seg_nbr(char *line, char sp1, char sp2, char sp3)
{
  int		i;
  int		flag;

  i = -1;
  flag = 0;
  while (line[++i])
    {
      if (line[i] == sp1 || line[i] == sp2 || line[i] == sp3)
	{
	  flag++;
	  while (line[i] == sp1 || line[i] == sp2 || line[i] == sp3)
	    i++;
	}
    }
  return (flag + 1);
}

int		count_seg_len(char *line, char sp1, char sp2, char sp3)
{
  int		len;
  int		i;

  len = 0;
  i = -1;
  while (line[++i] != sp1 && line[i] != sp2 && line[i] != sp3 && line[i])
    len++;
  return (len);
}

char		**cmd_to_tab(char *line, char sp1, char sp2, char sp3)
{
  char		**tab;
  int		i;
  int		y;
  int		x;

  i = 0;
  y = -1;
  if ((tab = malloc(sizeof(char*) *
		    (count_seg_nbr(line, sp1, sp2, sp3) + 1))) == NULL)
    return (NULL);
  while (line[i])
    {
      if ((tab[++y] = malloc(sizeof(char) * (count_seg_len(&line[i], sp1,
					     sp2, sp3) + 1))) == NULL)
	return (NULL);
      x = -1;
      while (line[i] != sp1 && line[i] != sp2 && line[i] != sp3 && line[i])
	tab[y][++x] = line[i++];
      tab[y][++x] = 0;
      while ((line[i] == sp1 || line[i] == sp2 || line[i] == sp3
	      || line[i] == ' ') && line[i])
	i++;
    }
  tab[++y] = NULL;
  return (tab);
}
