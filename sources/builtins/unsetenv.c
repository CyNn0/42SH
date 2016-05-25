/*
** unsetenv.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Wed May 25 22:51:35 2016 boris saint-bonnet
** Last update Wed May 25 23:06:31 2016 boris saint-bonnet
*/

#include "42.h"

int		unsetenv_checking(t_list *list)
{
  if (list->myEnv->head == NULL)
    return (FAILURE);
  if (!(list->cmd[1]))
    {
      fprintf(stderr, "%s: Too few arguments\n", list->cmd[0]);
      return (FAILURE);
    }
  return (SUCCESS);
}

int		unsetenv(t_list *list, char **cmd)
{
  int		i;
  t_node	*tmp;
  
  i = -1;
  if (unsetenv_checking(list) == FAILURE)
    return (SUCCES);
  while (cmd[++i])
    {
      tmp = list->myEnv->head;
      if ((strcmp(cmd[i], tmp->name)) == 0)
	list = del_link(list, tmp->name);
    }
  return (SUCCES);
}
