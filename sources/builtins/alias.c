/*
** alias.c for 42sh in C:\Users\gambin_l\42SH\sources\builtins
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Sun Jun 05 14:04:29 2016 Gambini Lucas
** Last update Mon Jun  6 19:40:28 2016 boris saint-bonnet
*/

# include		"42.h"

char			*just_concate(char *base, char *add)
{
  char			*ret;
  int			i;
  int			j;

  if (base == NULL || add == NULL)
    return (NULL);
  if ((ret = malloc(sizeof(char)
		    * (strlen(base) + strlen(add) + 2))) == NULL)
    return (NULL);
  i = -1;
  while (base[++i] != '\0')
    ret[i] = base[i];
  ret[i++] = ' ';
  j = 0;
  while (add[j] != '\0')
    ret[i++] = add[j++];
  ret[i] = '\0';
  return (ret);
}

int			check_line(char **cmd)
{
  int			i;

  i = -1;
  if (!cmd || !cmd[1])
    return (FAILURE);
  while (cmd[1][++i])
    {
      if (cmd[1][i] == '=' || cmd[1][i] == '\"')
	return (FAILURE);
    }
  return (SUCCESS);
}

char			*get_data_rc(char **cmd)
{
  int			i;
  char			*ret;

  i = 1;
  ret = NULL;
  while (cmd[++i])
    {
      if (!ret)
	ret = strdup(cmd[i]);
      else
	ret = just_concate(ret, cmd[i]);
    }
  return (ret);
}

int			builtin_alias(t_list *list, char **cmd)
{
  (void)list;
  if (check_line(cmd) == FAILURE)
    return (SUCCESS);
  list->myRc = push_bash(list->myRc, get_data_rc(cmd), cmd[1]);
  return (SUCCESS);
}
