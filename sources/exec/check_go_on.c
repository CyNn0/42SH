/*
** check_go_on.c for 42sh in C:\Users\gambin_l\42SH\sources\exec
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Thu May 26 11:45:23 2016 Gambini Lucas
** Last update Thu May 26 11:45:46 2016 Gambini Lucas
*/

# include		"42.h"

int			check_go_on(t_cmd *cmd)
{
  if (cmd->next)
    {
      (cmd->token == DOUBLE_PIPE) ? (cmd->next->go_on = 1)
	: (cmd->next->go_on = 0);
      (cmd->token == DOUBLE_AND) ? (cmd->next->go_on = 0)
	: (cmd->next->go_on = 1);
    }
  return (SUCCESS);
}
