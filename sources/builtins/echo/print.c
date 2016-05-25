/*
** print.c for print in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Wed May 25 02:51:51 2016 Hubert Leo
** Last update Wed May 25 03:08:10 2016 Hubert Leo
*/

#include "42.h"

void		put_echo(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    write(1, &str[i], 1);
}

int		print_varenv(char *cmd, int i, t_env *env)
{
  t_node	*tmp;
  char		*search;
  int		to_space;

  to_space = count_to_space(cmd, i);
  if ((search = get_varenv(cmd, i, to_space)) == NULL)
    return (FAILURE);
  tmp = env->head;
   while (tmp)
    {
      if (strncmp(tmp->name, search, strlen(tmp->name)) == 0)
	put_echo(tmp->data);
      tmp = tmp->next;
    }
   free(search);
   return (to_space - 1);
}

int		echo_print(t_echo *flags, char *cmd, t_env *env)
{
  int		i;
  /* char		in_double; */

  /* in_double = is_in_quotes(cmd); */
  (void)flags;
  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == '$')
      	i = print_varenv(cmd, i + 1, env);
      else
      	write(1, &cmd[i], 1);
      i++;
    }
  return (0);
}
