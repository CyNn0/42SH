/*
** setenv.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 25 04:06:44 2016 boris saint-bonnet
** Last update Sat Jun 04 15:40:44 2016 Philippe Lefevre
*/

#include	"42.h"

int	        setenv_checking(t_list *list, char **cmd)
{
  if (tab_lenght(cmd) > 3)
    {
      fprintf(stderr, "%s: Too many arguments.\n", cmd[0]);
      return (FAILURE);
    }
  else if (!cmd[1])
    {
      print_env(list->myEnv);
      return (FAILURE);
    }
  if (!((cmd[1][0] >= 'a' && cmd[1][0] <= 'z')
	|| (cmd[1][0] >= 'A' && cmd[1][0] <= 'Z')))
    {
      fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

int		builtin_setenv(t_list *list, char **cmd)
{
  t_node        *tmp;

  if ((setenv_checking(list, cmd)) == FAILURE)
    return (FAILURE);
  tmp = list->myEnv->head;
  while (tmp != NULL)
    {
      if ((strcmp(cmd[1], tmp->name)) == 0)
	{
	  tmp->data = (!cmd[2]) ? (strdup("")) : (strdup(cmd[2]));
	  return (SUCCESS);
	}
      tmp = tmp->next;
    }
  list = push_variable(list, cmd[1], cmd[2]);
  return (SUCCESS);
}
