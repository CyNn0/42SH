/*
** get_cmd.c for get_cmd in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 20 06:28:24 2016 Lucas Gambini
** Last update Sat May 21 23:50:40 2016 Lucas Gambini
*/

# include "42.h"

/*char		get_flag(char *seg)
{
  int		i;
  char		flag;

  i = -1;
  flag = 0;
  while (seg[++i])
    {
      (seg[i] == '|') ? ()
	  : ();
    }
}*/

t_list		*set_cmd(t_list *list, char **tab)
{
  int		i;
  char		**cmdtab;

  i = -1;
  while (tab[++i])
    {
      if ((cmdtab = cmd_to_tab(tab[i], ' ', ' ', ' ')) == NULL
	  || ((list = push_cmd(list, cmdtab))) == NULL)
	return (list);
      /*list->tail->flag = get_flag(tab[i]);*/
      free(tab[i]);
    }
  free(tab);
  return (list);
}

t_list		*get_cmd(t_list *list, char *line)
{
  char		**tab;

  if (line == NULL || (tab = cmd_to_tab(line, '|', ';', '&')) == NULL)
    return (NULL);
  tab = clean_tab(tab);
  list = set_cmd(list, tab);
  show_cmd_list(list);
  free(line);
  return (list);
}
