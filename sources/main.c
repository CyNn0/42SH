/*
** main.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:19:45 2016 boris saint-bonnet
** Last update Tue May 24 09:22:07 2016 Gambini Lucas
*/

#include		"42.h"

int			shell(char *env[])
{
  char			*buffer;
  t_list		*list;

  list = NULL;
  if ((list = my_env_in_list(list, env)) == NULL)
    return (FAILURE);
  print_prompt(list);
  path_to_list(list);
  while ((buffer = get_next_line(0)))
    {
      if ((list = get_cmd(list, pre_check(buffer))) == NULL)
	{
	  print_prompt(list);
	  continue;
	}
      exec_scatter(list);
      list = free_cmd(list);
      print_prompt(list);
    }
  free_fighter(list);
  return (SUCCESS);
}

int			main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  return (shell(env));
}
