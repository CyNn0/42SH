/*
** print_path.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Fri May 20 02:33:55 2016 boris saint-bonnet
** Last update Fri May 20 02:38:03 2016 boris saint-bonnet
*/

# include "42.h"

int    print_path(t_list *list)
{
  t_node        *tmp;

  tmp = list->path->head;
  if (list != NULL)
    {
      while (tmp != NULL)
	{
	  printf("%s\n", tmp->data);
	  tmp = tmp->next;
	}
    }
  return (0);
}
