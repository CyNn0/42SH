/*
** simple_right.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Mon May 23 17:57:28 2016 boris saint-bonnet
** Last update Mon May 23 21:51:07 2016 boris saint-bonnet
*/

# include "42.h"

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
  j = 0;
  if ((var->flag = malloc((tab_lenght(cmd) -1) * sizeof(char*))) == NULL)
    {
      my_exit(42);
    }
  var->flag[tab_lenght(cmd) - 2] = NULL;
  while (cmd[++i])
    {
      if ((strcmp(cmd[i], ">")) == 0)
	{
	  var->name = strdup(cmd[++i]);
	  if (i == 1)
	    {
	      var->cmd = strdup(cmd[++i]);
	      while (cmd[++i] && strcmp(cmd[i], ">") != 0)
		var->flag[j++] = strdup(cmd[i]);
	      break;
	    }
	  else
	    {
	      i = 1;
	      var->cmd = strdup(cmd[0]);
	      while (cmd[i] && strcmp(cmd[i], ">") != 0)
		var->flag[j++] = strdup(cmd[i++]);
	      break;
	    }
	}
    }
}

int		simple_right(t_cmd *cmd, t_path *path, char **env)
{
  t_right	var;
  int		fd;
  int		i;

  i = -1;
  init_var(cmd->cmd, &var);
  printf("name: %s, cmd: %s, flag: %s\n", var.name, var.cmd, var.flag[0]);
  if ((fd = open(var.name, __SIMPLE)) == -1)
    return (FAILURE);
  dup2(fd, 1);
  exec_right(cmd, path, env, var);
  close(fd);
  return (SUCCESS);
}
