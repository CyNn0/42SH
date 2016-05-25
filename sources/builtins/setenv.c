/*
** setenv.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Wed May 25 04:06:44 2016 boris saint-bonnet
** Last update Wed May 25 23:18:09 2016 boris saint-bonnet
*/

#include "42.h"

int	        setenv_checking(t_list *list, char **cmd)
{
  if (cmd[2])
    {
      fprintf(stderr, "%s: Too many arguments.\n", cmd[0]);
      return (FAILURE);
    }
  else if (!cmd[1])
    {
      print_env(list->myEnv);
      return (SUCCESS);
    }
  return (SUCCESS);
}

t_list		*my_setenv(t_list *list, char **cmd)
{
  t_node        *tmp;

  if ((setenv_checking(list, cmd)) == FAILURE)
    return (list);
  tmp = list->myEnv->head;
  if (strlen(cmd[0]) == 0)
    {
      list = push_variable(list, "", cmd[1]);
      return (list);
    }
  while (tmp != NULL)
    {
      if ((strncmp(cmd[0], tmp->name, strlen(cmd[0])) == 0))
	{
	  tmp->data = (cmd[1] == NULL) ? (strdup("")) : (strdup(cmd[1]));
	  return (list);
	}
      tmp = tmp->next;
    }
  return (list = push_variable(list, cmd[0], cmd[1]));
}
