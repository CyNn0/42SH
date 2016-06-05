/*
** swap_alias.c for 42SH in C:\Users\gambin_l\42SH\sources\parsing
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Sun Jun 05 19:03:07 2016 Gambini Lucas
** Last update Mon Jun  6 00:07:05 2016 Lucas Gambini
*/

# include		"42.h"

char			**prepare_tab(char **alias, char **cmd)
{
  int			len;
  int			i;
  int			j;
  char			**ret;

  i = -1;
  j = 0;
  len = tab_lenght(alias) + tab_lenght(cmd);
  ret = xmalloc(sizeof(char*) * len);
  while (alias[++i])
    ret[i] = strdup(alias[i]);
  while (cmd[++j])
    ret[i++] = strdup(cmd[j]);
  ret[len - 1] = NULL;
  return (ret);
}

t_cmd			*swap_alias(t_cmd *cmd, t_bash *bash)
{
  t_node		*tmp;
  char			**tab;

  tab = NULL;
  tmp = bash->head;
  while (tmp)
    {
      if (strcmp(tmp->name, cmd->cmd[0]) == 0)
	tab = prepare_tab(cmd_to_tab(tmp->data, ' ', ' ', ' '), cmd->cmd);
      tmp = tmp->next;
    }
  if (tab)
    {
      free_tab(cmd->cmd);
      cmd->cmd = tab;
    }
  return (cmd);
}
