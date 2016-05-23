/*
** main.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:19:45 2016 boris saint-bonnet
** Last update Sun May 22 10:08:18 2016 boris saint-bonnet
*/

# include "42.h"

int	shell(char *env[])
{
  char		*buffer;
  t_list	*list;

  list = NULL;
  if ((list = my_env_in_list(list, env)) == NULL)
    return (-1);
  print_prompt(list);
  path_to_list(list);
  while ((buffer = get_next_line(0)))
    {
      if ((list = get_cmd(list, pre_check(buffer))) == NULL)
	return (-1);
      /* INSERER EXEC ICI */
      list = free_cmd(list);
      print_prompt(list);
    }
  free_fighter(list);
  return (0);
}

int	main(int ac, char *av[], char *env[])
{
  (void)ac;
  (void)av;
  return (shell(env));
}
