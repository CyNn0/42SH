/*
** my_env_in_list.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Thu May 19 19:23:14 2016 boris saint-bonnet
** Last update Sun Jun 05 05:15:07 2016 Philippe Lefevre
*/

#include	"42.h"

int		get_name(char *name)
{
  int		i;

  i = -1;
  while (name[++i])
    if (name[i] == '=')
      return (i);
  return (SUCCESS);
}

int		envlen(t_env *myEnv)
{
    int		i;
    t_node	*tmp;

    i = 0;
    if (!myEnv->head || !myEnv->tail)
      return (0);
    tmp = myEnv->head;
    while (tmp)
      {
	if (strcmp("?", tmp->name))
	  i++;
	tmp = tmp->next;
      }
    return (i);
}

char		**extract_env(t_env *myEnv)
{
    char	**env;
    t_node	*tmp;
    int		len;
    int		i;

    len = envlen(myEnv);
    i = -1;
    tmp = myEnv->head->next;
    if ((env = malloc(sizeof(char *) * (len + 1))) == NULL)
      return (NULL);
    env[len] = NULL;
    while (++i < len)
      {
	env[i] = my_strcatenv(tmp->name, tmp->data);
	tmp = tmp->next;
      }
    return (env);
}

t_list		*my_env_in_list(t_list *list, char **env)
{
  int		i;
  int		j;
  char		*name;
  char		*data;

  i = 0;
  if ((list = create_list(list)) == NULL)
    return (NULL);
  name = strdup("?");
  data = strdup("0");
  list = push_env(list, data, name);
  xfree(name);
  xfree(data);
  while (env[i])
    {
      j = get_name(env[i]);
      if ((name = malloc((j + 1) * sizeof(char))) == NULL)
	return (NULL);
      name[j] = '\0';
      name = strncpy(name, env[i], j);
      data = strdup(env[i] + (j + 1));
      list = push_env(list, data, name);
      xfree(name);
      xfree(data);
      i++;
    }
  return (list);
}
