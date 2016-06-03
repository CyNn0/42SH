/*
** print_env.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Thu May 19 18:58:06 2016 boris saint-bonnet
** Last update Fri Jun 03 21:51:18 2016 Philippe Lefevre
*/

#include		"42.h"

int			print_env(t_env *list)
{
  t_node		*tmp;

  tmp = list->head;
  if (list != NULL)
    {
      while (tmp != NULL)
	{
	  printf("%s=%s\n", tmp->name, tmp->data);
	  tmp = tmp->next;
	}
    }
  return (0);
}

int			print_prompt(t_list *list)
{
  char			*dirname;
<<<<<<< HEAD
  char			*ptr_user;
=======
>>>>>>> 015b0394476dcc59e98a1f47f418abae650a0e52

  if (isatty(1) != 1)
    return (FAILURE);
  dirname = get_current_dir_name();
  ptr_user = find_user(list, "USER");
  write(1, GREEN, strlen(CYAN));
  if (ptr_user != NULL)
    {
      write(1, ptr_user, strlen(ptr_user));
      write(1, ":", 1);
  }
  write(1, CYAN, strlen(CYAN));
  write(1, dirname, strlen(dirname));
  write(1, " ", 1);
  write(1, DEFAULT, strlen(DEFAULT));
  free(dirname);
<<<<<<< HEAD
=======
  return (0);
>>>>>>> 015b0394476dcc59e98a1f47f418abae650a0e52
  return (SUCCESS);
}
