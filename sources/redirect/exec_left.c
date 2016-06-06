/*
** exec_right.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Mon May 23 20:22:56 2016 boris saint-bonnet
** Last update Mon Jun 06 14:27:40 2016 Philippe Lefevre
*/

#include 		"42.h"

int                     exec_left(t_list *list,
				   char **env, t_cmd *cmd)
{
  int                   status;

  status = simple_exec(cmd, list, env, -20);
  return (status);
}
