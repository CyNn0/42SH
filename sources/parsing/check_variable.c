/*
** check_variable.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Tue May 31 19:56:35 2016 boris saint-bonnet
** Last update Sat Jun  4 05:24:32 2016 boris saint-bonnet
*/

#include		"42.h"

int		check_finish_v(char *s, char c)
{
  int		i;
  int		ok;

  i = -1;
  ok = 0;
  while (s[++i])
    if (s[i] == c && (i - 1 > 0) && s[i - 1] != c &&
	s[i + 1] && s[i + 1] != c)
      if (s[i - 1] != ' ')
	ok++;
  if (ok == 0)
    return (0);
  return (-1);
}

char		*simples_v(char *s, char c)
{
  t_pars        var;

  var.ret = strdup(s);
  xfree(s);
  simple_first(&var, c);
  while ((check_finish_v(var.ret, c) == -1))
    {
      var.i = -1;
      while (var.ret[++var.i])
	{
	  if (var.ret[var.i] == c && var.ret[var.i + 1] != c &&
	      var.ret[var.i - 1] != c && var.ret[var.i - 1] != ' ')
	    {
	      var.bef = my_strcut(var.ret, 0, (var.i), 0);
	      var.aft = my_strcut(var.ret, (var.i), 0, 0);
	      xfree(var.ret);
	      var.ret = my_strcatc(var.bef, var.aft, 3, 0);
	      xfree(var.aft);
	    }
	}
    }
  return (var.ret);
}

int			check_variable(char *str)
{
  while (*str)
    {
      if (*str == '$')
	return (SUCCESS);
      str++;
    }
  return (FAILURE);
}

char			*set_variable(char *str, t_list *list)
{
  t_node		*tmp;

  tmp = list->myEnv->head;
  if (strlen(str) > 1)
    while (tmp != NULL)
      {
	if ((strcmp(tmp->name, str + 1)) == 0)
	  return (tmp->data);
	tmp = tmp->next;
      }
  else
    return (str);
  fprintf(stderr, "%s: Undefined variable.\n", str + 1);
  return (str);
}

char			*replace_variable(char *str, t_list *list)
{
  char			**tab;
  char			*tmp;
  int			i;

  i = -1;
  
  if (check_variable(str) == FAILURE)
    return (str);
  tmp = simples_v(str, '$');
  tab = my_str_to_wordtab(tmp, ' ');
  while (tab[++i])
    if ((strncmp(tab[i], "$", 1)) == 0)
      tab[i] = strdup(set_variable(tab[i], list));
  return (tab_to_cmd(tab));
}
