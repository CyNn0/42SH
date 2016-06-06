/*
** pars_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Tue May 24 21:31:11 2016 boris saint-bonnet
** Last update Mon Jun  6 19:37:26 2016 cyril puccio
*/

# include		"42.h"

int			dep_init_var(char **cmd, t_red *var, int *i, int *j)
{
  if (*i == 1)
    {
      if (cmd[*i + 1] != NULL)
	var->cmd[0] = strdup(cmd[++(*i)]);
      while (cmd[++(*i)] && strcmp(cmd[*i], ">") != 0)
	var->cmd[(*j)++] = strdup(cmd[*i]);
      var->cmd[*j] = NULL;
      return (FAILURE);
    }
  else
    {
      *i = 1;
      var->cmd[0] = strdup(cmd[0]);
      while (cmd[*i] && strcmp(cmd[*i], ">") != 0)
	var->cmd[(*j)++] = strdup(cmd[(*i)++]);
      var->cmd[*j] = NULL;
      return (FAILURE);
    }
  return (SUCCESS);
}

int                     error_right(t_cmd *cmd, t_red *var, int i)
{
  if (i == 0)
    {
      fprintf(stderr, "Invalid null command.\n");
      var->cmd = NULL;
      cmd->go_on = 0;
      return (FAILURE);
    }
  else if (!(cmd->cmd[i + 1]))
    {
      fprintf(stderr, "Missing name for redirect.\n");
      var->name = NULL;
      cmd->go_on = 0;
      return (FAILURE);
    }
  return (SUCCESS);
}

void			init_var(t_cmd *cmd, t_red *var)
{
  char			**swap;
  int			i;
  int			j;

  i = -1;
  j = 1;
  if ((var->cmd = malloc((tab_lenght(cmd->cmd)) * sizeof(char*))) == NULL)
    my_exit(42);
  var->cmd[tab_lenght(cmd->cmd) - 1] = NULL;
  while (cmd->cmd[++i])
    {
      if ((strcmp(cmd->cmd[i], ">")) == 0)
	{
	  if (error_right(cmd, var, i) == FAILURE)
            return;
	  var->name = strdup(cmd->cmd[++i]);
	  if (dep_init_var(cmd->cmd, var, &i, &j) == FAILURE)
	    break;
	}
    }
  swap = cmd->cmd;
  cmd->cmd = var->cmd;
  var->cmd = swap;
}

int			dep_init_db_var(char **cmd, t_red *var, int *i, int *j)
{
  if (*i == 1)
    {
      if (cmd[++(*i)])
	var->cmd[0] = strdup(cmd[*i]);
      else
	return (FAILURE);
      while (cmd[++(*i)] && strcmp(cmd[*i], ">>") != 0)
	var->cmd[(*j)++] = strdup(cmd[*i]);
      var->cmd[(*j)] = NULL;
      return (FAILURE);
    }
  else
    {
      *i = 1;
      var->cmd[0] = strdup(cmd[0]);
      while (cmd[*i] && strcmp(cmd[*i], ">>") != 0)
	var->cmd[(*j)++] = strdup(cmd[(*i)++]);
      var->cmd[*j] = NULL;
      return (FAILURE);
    }
  return (SUCCESS);
}

void            	init_double(t_cmd *cmd, t_red *var)
{
  char			**swap;
  int           	i;
  int           	j;

  i = -1;
  j = 1;
  if ((var->cmd = malloc((tab_lenght(cmd->cmd)) * sizeof(char*))) == NULL)
    my_exit(42);
  var->cmd[tab_lenght(cmd->cmd) - 1] = NULL;
  while (cmd->cmd[++i])
    {
      if ((strcmp(cmd->cmd[i], ">>")) == 0)
	{
	  if (error_right(cmd, var, i) == FAILURE)
            return;
	  var->name = strdup(cmd->cmd[++i]);
	  if (dep_init_db_var(cmd->cmd, var, &i, &j) == FAILURE)
	    break;
	}
    }
  swap = cmd->cmd;
  cmd->cmd = var->cmd;
  var->cmd = swap;
}
