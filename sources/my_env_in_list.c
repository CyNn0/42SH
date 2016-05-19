/*
** my_env_in_list.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Thu May 19 19:23:14 2016 boris saint-bonnet
** Last update Thu May 19 22:16:01 2016 boris saint-bonnet
*/

# include "42.h"

int	get_name(char *name)
{
  int	i;

  i = -1;
  while (name[++i])
    if (name[i] == '=')
      return (i);
  return (0);
}

t_list  *my_env_in_list(t_list *list, char **env)
{
  int   i;
  int   j;
  char  *name;
  char  *data;

  i = 0;
  if ((list = create_list(list)) == NULL)
    return (NULL);
  while (env[i])
    {
      j = get_name(env[i]);
      name = malloc((j + 1) * sizeof(char));
      if (name == NULL)
	return (NULL);
      name[j] = '\0';
      name = strncpy(name, env[i], j);
      data = strdup(env[i] + (j + 1));
      list = push_env(list, data, name);
      i++;
    }
  return (list);
}
