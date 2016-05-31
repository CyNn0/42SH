/*
** check_variable.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Tue May 31 19:56:35 2016 boris saint-bonnet
** Last update Tue May 31 20:41:15 2016 boris saint-bonnet
*/

#include		"42.h"

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
  int			i;

  i = -1;
  if (check_variable(str) == FAILURE)
    return (str);
  tab = my_str_to_wordtab(str, ' ');
  while (tab[++i])
    if ((strncmp(tab[i], "$", 1)) == 0)
      tab[i] = strdup(set_variable(tab[i], list));
  return (tab_to_cmd(tab));
}
