/*
** show_history.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Sat Jun  4 15:11:03 2016 boris saint-bonnet
** Last update Mon Jun  6 01:43:18 2016 boris saint-bonnet
*/

#include	"42.h"

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
	  if ((tab[i] = realloc(tab[i], sizeof(char) *
				   (strlen(tab[i]) + 2))) == NULL)
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
      file1d = realloc(file1d, sizeof(char) * (strlen(file1d) + 2));
      i++;
    }
  if ((file = my_linetab(file1d, 0, 0)) == NULL)
    return (NULL);
  xfree(file1d);
  return (file);
}
int		check_clear(char **cmd)
{
  int		fd;

  if (cmd[1] && (strcmp(cmd[1], "-c")) == 0)
    {
      if ((fd = open("tmp/.42history", __HISTC)) == -1)
	return (FAILURE);
      open_history(cmd[0]);
    }
  else
    {
      (void)fd;
      return (FAILURE);
    }
  return (SUCCESS);
}

int	        builtin_history(t_list *list, char **cmd)
{
  char		**hist;
  int		i;
  int		tmp;
  int		fd;
  
  if((fd = open("tmp/.42history", __HIST)) == -1)
    return (FAILURE);
  i = -1;
  list = list;
  if (check_clear(cmd) == SUCCESS)
    return (SUCCESS);
  hist = file_to_tab(fd);
  if (!cmd[1])
    while (hist[++i + 1])
      printf("%d %s\n", i, hist[i]);
  else if (cmd[1] && (strcmp(cmd[1], "-c")) != 0)
    {
      tmp = atoi(cmd[1]);
      i = (tab_lenght(hist) - tmp);
      while (hist[i] && hist[i + 1])
	{
	  printf("%d %s\n", i, hist[i]);
	  i++;
	}
    }
  free_tab(hist);
  return (SUCCESS);
}
