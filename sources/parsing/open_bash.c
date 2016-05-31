/*
** open_bash.c for open_bash in /home/puccio_c/rendu/minishell/my_42SH
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Wed May 25 13:14:15 2016 cyril puccio
** Last update Tue May 31 17:34:00 2016 boris saint-bonnet
*/

# include	"42.h"

int             check_quotes(char *str)
{
  int           i;
  int           nb;

  nb = 0;
  i = -1;
  while (str[++i])
    if (str[i] == '\'' || str[i] == '\"')
      nb++;
  return (nb == 2 ? nb : -1);
}

int		pars_bash(char *map, t_bash *bash)
{
  char		*name;
  char		*data;
  int		i;

  i = -1;
  name = "\0";
  data = "\0";
  if (strcmp("alias", my_strcut(map, 0, 5, 0)) == 0)
    {
      map += 6;
      while (map[++i] != '=' && map[i]);
      name = my_strcut(map, 0, i, 0);
      i++;
      if (map[i] && check_quotes(map) == 2
	  && (map[i] == '\'' || map[i] == '\"'))
	data = my_strcut(map, i + 1, strlen(map) - i - 2, 0);
    }
  else
    return (FAILURE);
  bash = push_bash(bash, data, name);
  return (SUCCESS);
}

char		*is_used(t_node *node, char *data)
{
  char		*str;

  str = NULL;
  while (node->name && node->next != NULL)
    {
      if (strcmp(node->name, data) == 0)
	return (str = node->data);
      node = node->next;
    }
  return (str);
}

char		*check_loop(t_bash *bash, char *cmd)
{
  t_node	*exe;
  t_bash	*tmp;
  char		*data;

  tmp = bash;
  exe = tmp->head;
  data = NULL;
  while (exe != NULL && exe->name && cmd)
    {
      if (strcmp(exe->name, cmd) == 0 && exe->p == false)
	{
	  exe->p = true;
	  data = is_used(tmp->head, exe->data);
	  (data == NULL ? data = exe->data : 0);
	  while (exe->prev != NULL)
	    exe = exe->prev;
	  tmp->head = exe;
	}
      exe = exe->next;
    }
  return (data == NULL ? cmd : data);
}

char		*open_bash(char *arg, char *cmd)
{
  t_bash	bash;
  int           fd;
  int		i;
  char          *s;
  char		**tab;

  tab = NULL;
  bash.head = NULL;
  bash.tail = NULL;
  i = 0;
  if ((fd = open(arg, O_RDONLY)) == -1)
    return (cmd);
  tab = my_str_to_wordtab(cmd, ' ');
  while ((s = get_next_line(fd)))
    pars_bash(s, &bash);
  while (tab[i] && (tab[i] = check_loop(&bash, tab[i])) != NULL)
    i++;
  if (tab != NULL)
    return (tab_to_cmd(tab));
  return (cmd);
}
