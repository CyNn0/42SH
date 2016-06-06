/*
** main.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:19:45 2016 boris saint-bonnet
** Last update Mon Jun  6 20:33:28 2016 Lucas Gambini
*/

#include		"42.h"

void			get_sigint(int sig)
{
  (void)sig;
  write(1, "\n", 1);
  dprintf(0, "%s", get_pwd());
}

void			init_shell(t_list *list)
{
  path_to_list(list);
  list->do_exit = 0;
  list->value_exit = 0;
  signal(SIGINT, get_sigint);
  builtin_source(list, NULL);
  print_prompt(list);
}

int			shell(char *env[])
{
  char			*buffer;
  t_list		*list;
  int			value_exit;

  list = NULL;
  if ((list = my_env_in_list(list, env)) == NULL)
    return (FAILURE);
  init_shell(list);
  /*open_history(list);*/
  while (!(list->do_exit) && (buffer = get_next_line(0)))
    {
      list = add_history(list, buffer);
      if ((list = get_cmd(list, pre_check(buffer, list))) == NULL)
	continue;
      exec_scatter(list);
      if (!(list->do_exit))
	print_prompt(list);
      list = free_cmd(list);
    }
  value_exit = list->value_exit;
  /*save_history(list);*/
  free_fighter(list);
  return (value_exit);
}

int			main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  return (shell(env));
}
