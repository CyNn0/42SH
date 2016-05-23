/*
** parsing_redirections.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Mon May 23 16:49:33 2016 boris saint-bonnet
** Last update Mon May 23 17:03:50 2016 boris saint-bonnet
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
	var.name = ++i;
      if (i == 1)
	{
	  var.cmd = 2;
	  var.flag = 3;
	}
      else
	{
	  var.cmd = 0;
	  var.flag = 1;
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
	var.name = ++i;
      if (i == 1)
	{
	  var.cmd = 2;
	  var.flag = 3;
	}
      else
	{
	  var.cmd = 0;
	  var.flag = 1;
	}
    }
  return (var);
}
