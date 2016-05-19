/*
** main.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:19:45 2016 boris saint-bonnet
** Last update Thu May 19 04:21:19 2016 Lucas Gambini
*/

# include "42.h"

void	shell(char *env[])
{
  char	*buffer;

  (void)env; /* TMP */
  write(1, "$> ", 3);
  while ((buffer = get_next_line(0)))
    {
      printf("%s\n", pre_check(buffer));
      free(buffer);
      write(1, "$> ", 3);
    }
}

int	main(int ac, char *av[], char *env[])
{
  (void)ac;
  (void)av;
  shell(env);
  return (0);
}
