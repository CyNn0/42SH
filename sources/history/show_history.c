/*
** show_history.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Sat Jun  4 15:11:03 2016 boris saint-bonnet
** Last update Sat Jun  4 15:33:37 2016 boris saint-bonnet
*/

#include "42.h"

int             line_counters(char *str)
{
  int           i;
  int           count;

  i = -1;
  count = 1;
  while (str[++i])
    if (str[i] == '\n')
      count++;
  return (count);
}

char            **my_linetab(char *str, int i, int j)
{
  int           k;
  char          **tab;

  tab = malloc(sizeof(char *) * (line_counters(str) + 1));
  i = 0;
  j = 0;
  while (i < line_counters(str))
    {
      if ((tab[i] = malloc(sizeof(char) * 2)) == NULL)
	return (NULL);
      k = 0;
      while (str[j] && str[j] != '\n')
	{
	  tab[i][k] = str[j];
	  tab[i][k++ + 1] = 0;
	  if ((tab[i] = my_realloc(tab[i], sizeof(char) *
				   (my_strlen(tab[i]) + 2))) == NULL)
	    return (NULL);
	  j++;
	}
      tab[i++][k] = 0;
      j++;
    }
  tab[i] = 0;
  return (tab);
}

char             **file_to_tab(int fd)
{
  char          c;
  char          *file1d;
  int           i;
  char          **file;

  if ((file1d = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  i = 0;
  while (read(fd, &c, 1) > 0)
    {
      file1d[i] = c;
      file1d[i + 1] = 0;
      file1d = my_realloc(file1d, sizeof(char) * (my_strlen(file1d) + 2));
      i++;
    }
  if ((file = my_linetab(file1d, 0, 0)) == NULL)
    return (NULL);
  free(file1d);
  return (file);
}

int		my_history(t_list *list, char **cmd)
{
  char		**hist;
  int		i;
  int		tmp;
  
  if((hist = file_to_tab(list->history)) == NULL)
    return (FAILURE);
  i = -1;
  if (!cmd[1])
    while (hist[++i])
      printf("%d %s\n", i, tab[i]);
  else if (cmd[1])
    {
      tmp = atoi(cmd[1]);
      i = tab_lenght - tmp;
      while (tab[i])
	{
	  printf("%d %s\n", i, tab[i]);
	  i++;
	}
    }
  free_tab(hist);
  return (SUCCESS);
}
