/*
** get_cmd.c for get_cmd in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 20 06:28:24 2016 Lucas Gambini
** Last update Sat May 21 00:31:05 2016 Lucas Gambini
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
  return ((int)line[0]);
}

char		**cmd_to_tab(char *line)
{
  char		**tab;
  int		i;

  i = -1;
  printf("%d\n", count_seg_nbr(line));
  if ((tab = malloc(sizeof(char*) * (count_seg_nbr(line) + 1))) == NULL)
    return (NULL);
  while (line[++i])
    {

    }
  (void)tab;
  return (tab);
}

t_list		*get_cmd(t_list *list, char *line)
{
  char		**tab;

  tab = cmd_to_tab(line);
  (void)tab;
  printf("%s\n", line);
  return (list);
}
