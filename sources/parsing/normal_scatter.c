/*
** normal_scatter.c for 42SH in C:\Users\gambin_l\Documents\Virtual Machines\Shared\42SH\sources\parsing
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Wed May 25 08:38:41 2016 Gambini Lucas
** Last update Wed May 25 17:17:42 2016 Philippe Lefevre
*/

# include	"42.h"

int		normal_scatter(t_cmd *cmd, char **env, t_path *path)
{
  (cmd->flag == SIMPLE_R) ? (simple_right(cmd, path, env))
    : ((cmd->flag == SIMPLE_L) ? (printf("SIMPLE_L\n"))
       : ((cmd->flag == DOUBLE_R) ? (double_right(cmd, path, env))
	  : ((cmd->flag == DOUBLE_L) ? (printf("DOUBLE_L\n"))
	     : ((simple_exec(cmd, path, env))))));
  return (SUCCESS);
}
