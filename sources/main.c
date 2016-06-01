/*
** main.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:19:45 2016 boris saint-bonnet
** Last update Wed Jun 01 03:09:12 2016 Philippe Lefevre
*/

#include		"42.h"

int			shell(char *env[])
{
  char			*buffer;
  t_list		*list;
  int			value_exit;

  list = NULL;
  if ((list = my_env_in_list(list, env)) == NULL)
    return (FAILURE);
  path_to_list(list);
  list->do_exit = 0;
  list->value_exit = 0;
  while (!(list->do_exit) && !(print_prompt(list))
	 && (buffer = get_next_line(0)))
    {
      open_history(buffer);
      list = add_history(list, buffer);
      if ((list = get_cmd(list, pre_check(buffer, list))) == NULL)
	continue;
      exec_scatter(list);
      list = free_cmd(list);
    }
  value_exit = list->value_exit;
  free_fighter(list);
  return (value_exit);
}

int			main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  return (shell(env));
}
