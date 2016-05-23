/*
** my_env_in_list.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Thu May 19 19:23:14 2016 boris saint-bonnet
** Last update Mon May 23 17:14:50 2016 Gambini Lucas
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
	i++;
	printf("%d --> %s$\n", i, tmp->data);
	tmp = tmp->next;
      }
    return (i);
}

char		**extract_env(t_env *myEnv)
{
    char	**env;
    int		envlen;

    envlen = envlen(myEnv));
    if ((env = malloc(sizeof(char *) * envlen)) == NULL)
      return (NULL);
    return (env);
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
      if ((name = malloc((j + 1) * sizeof(char))) == NULL)
	return (NULL);
      name[j] = '\0';
      name = strncpy(name, env[i], j);
      data = strdup(env[i] + (j + 1));
      list = push_env(list, data, name);
	free(name);
	free(data);
      i++;
    }
  return (list);
}
