/*
** list_cmd.c for list_cmd in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Fri May 20 06:45:22 2016 Lucas Gambini
** Last update Fri May 20 06:52:25 2016 Lucas Gambini
*/

# include "42.h"

t_list		*push_path(t_list *list, char **cmd)
{
  t_cmd        *cmd;

  if ((cmd = malloc(sizeof(*cmd))) == NULL)
    return (NULL);
  if (data == NULL)
    return (list);
  cmd->cmd = cmd;
  cmd->next = NULL;
  if (list->path->tail == NULL)
    {
      cmd->prev = NULL;
      list->head = cmd;
      list->tail = cmd;
    }
  else
    {
      list->tail->next = cmd;
      cmd->prev = list->tail;
      list->tail = cmd;
    }
  return (list);
}
