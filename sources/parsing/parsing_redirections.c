/*
** parsing_redirections.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Mon May 23 16:49:33 2016 boris saint-bonnet
** Last update Mon May 23 18:58:42 2016 boris saint-bonnet
*/

# include "42.h"

t_right		parsing_sr(char **cmd)
{
  t_right	var;
  int		i;

  i = -1;
  while (cmd[++i])
    {
      if ((strcmp(cmd[i], ">")) == 0)
	var.name = strdup(cmd[++i]);
      if (i == 1)
	{
	  var.cmd = strdup(cmd->cmd[2]);
	  var.flag = 3;
	  break;
	}
      else
	{
	  var.cmd = strdup(cmd->cmd[0]);
	  var.flag = 1;
	  break;
	}
    }
  return (var);
}

t_right		parsing_dr(char **cmd)
{
  t_right	var;
  int		i;

  i = -1;
  while (cmd[++i])
    {
      if ((strcmp(cmd[i], ">>")) == 0)
	var.name = strdup(cmd[++i]);
      if (i == 1)
	{
	  var.cmd = strdup(cmd->cmd[2]);
	  var.flag = 3;
	  break;
	}
      else
	{
	  var.cmd = strdup(cmd->cmd[0]);
	  var.flag = 1;
	  break;
	}
      return (var);
    }
}
