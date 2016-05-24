/*
** simple_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 17:57:28 2016 boris saint-bonnet
** Last update Tue May 24 17:49:38 2016 Gambini Lucas
*/

# include 	"42.h"

int		tab_lenght(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i]);
  return (i);
}

void		init_var(char **cmd, t_right *var)
{
  int		i;
  int		j;

  i = -1;
  j = 1;
  if ((var->cmd = malloc((tab_lenght(cmd)) * sizeof(char*))) == NULL)
    my_exit(42);
  var->cmd[tab_lenght(cmd) - 1] = NULL;
  while (cmd[++i])
    {
      if ((strcmp(cmd[i], ">")) == 0)
	{
	  var->name = strdup(cmd[++i]);
	  if (i == 1)
	    {
	      var->cmd[0] = strdup(cmd[++i]);
	      while (cmd[++i] && strcmp(cmd[i], ">") != 0)
		var->cmd[j++] = strdup(cmd[i]);
	      break;
	    }
	  else
	    {
	      i = 1;
	      var->cmd[0] = strdup(cmd[0]);
	      while (cmd[i] && strcmp(cmd[i], ">") != 0)
		var->cmd[j++] = strdup(cmd[i++]);
	      break;
	    }
	}
    }
}

int		simple_right(t_cmd *cmd, t_path *path, char **env)
{
  t_right	var;
  int		fd;

  init_var(cmd->cmd, &var);
  if ((fd = open(var.name, __SIMPLE)) == -1)
    return (FAILURE);
  exec_right(fd, path, env, var);
  close(fd);
  return (SUCCESS);
}
