/*
** main.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:19:45 2016 boris saint-bonnet
** Last update Thu May 19 22:21:44 2016 boris saint-bonnet
*/

# include "42.h"

void	shell(char *env[])
{
  char		*buffer;
  t_list	*list;

  list = NULL;
  list = my_env_in_list(list, env);
  print_prompt(list);
  while ((buffer = get_next_line(0)))
    {
      buffer = pre_check(buffer);
      printf("%s\n", buffer);
      free(buffer);
      print_env(list);
      print_prompt(list);
    }
}

int	main(int ac, char *av[], char *env[])
{
  (void)ac;
  (void)av;
  shell(env);
  return (0);
}
