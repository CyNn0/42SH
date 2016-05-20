/*
** main.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:19:45 2016 boris saint-bonnet
** Last update Fri May 20 23:23:11 2016 boris saint-bonnet
*/

# include "42.h"

void	shell(char *env[])
{
  char		*buffer;
  t_list	*list;

  list = NULL;
  if ((list = my_env_in_list(list, env)) == NULL)
    return;
  print_prompt(list);
  path_to_list(list);
  while ((buffer = get_next_line(0)))
    {
      buffer = pre_check(buffer);
      if (buffer != NULL)
	printf("%s\n", buffer);
      /* list = get_cmd(list, buffer); */
      free(buffer);
      print_prompt(list);
    }
  free_fighter(list);
}

int	main(int ac, char *av[], char *env[])
{
  (void)ac;
  (void)av;
  shell(env);
  return (0);
}
