/*
** get_cmd.c for get_cmd in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 20 06:28:24 2016 Lucas Gambini
** Last update Sat Jun 04 23:20:39 2016 Philippe Lefevre
*/

#include		"42.h"

char			get_token(char *seg, char *line)
{
  int			i;

  i = -1;
  while (strncmp(seg, &line[++i], (int)strlen(seg)) != 0);
  i += (int)strlen(seg);
  if (line[i] == 0 || line[i + 1] == 0)
    return (EXE);
  if (line[i + 1] == '|' && line[i + 2] != '|')
    return (PIPE);
  else if (line[i + 1] == '|' && line[i + 2] == '|')
    return (DOUBLE_PIPE);
  if (line[i + 1] == '&' && line[i + 2] != '&')
    return (SIMPLE_AND);
  else if (line[i + 1] == '&' && line[i + 2] == '&')
    return (DOUBLE_AND);
  return (1);
}

t_list			*set_cmd(t_list *list, char **tab, char *line)
{
  int			i;
  char			**cmdtab;
  char			*glob;

  i = -1;
  while (tab[++i])
    {
      if (check_bquotes(tab[i]) == SUCCESS)
	tab[i] = strdup(my_bquotes(tab[i]));
      if ((glob = globbing(tab[i])) == NULL)
	return (list);
      if ((cmdtab = cmd_to_tab(glob, ' ', ' ', ' ')) == NULL
	  || ((list = push_cmd(list, cmdtab))) == NULL)
	return (list);
      free(glob);
      list->tail->token = get_token(tab[i], line);
      list->tail->flag = 0;
      list->tail->go_on = 1;
      if (list->tail->prev)
	(list->tail->prev->token == DOUBLE_PIPE) ? (list->tail->go_on = 0)
	  : (list->tail->go_on = 1);
      free(tab[i]);
    }
  free(tab);
  return (list);
}

t_list			*get_cmd(t_list *list, char *line)
{
  char			**tab;

  if (line == NULL || (tab = cmd_to_tab(line, '|', ';', '&')) == NULL)
    return (list);
  tab = clean_tab(tab);
  list = set_cmd(list, tab, line);
  list = post_parser(list);
  free(line);
  return (list);
}
