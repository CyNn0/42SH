/*
** main.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:19:45 2016 boris saint-bonnet
<<<<<<< HEAD
** Last update Fri Jun 03 15:04:21 2016 Gambini Lucas
=======
** Last update Fri Jun 03 14:11:10 2016 Philippe Lefevre
>>>>>>> a9e193cb7e0317775e0c908b8a38bcffad9702ef
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
      /* open_history(buffer); */
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
/*
void			parse_arg(int ac, char **av, char **env)
{
  pid_t			pid;
  char *cmd[] = { "/bin/chmod", "-r", "./42sh", 0};

  (void)ac;
  if ((pid = fork()) == -1)
    fprintf(stderr, "Error: %s\n", strerror(errno));
  else if (pid == 0)
    {
      execve(cmd[0], &cmd[0], env);
      fprintf(stderr, "%s: Command not found.\n", cmd[0]);
      return (FAILURE);
    }
  else
    xwaitpid(pid, 0, 0);
  return (SUCCESS);
}
*/
int			main(int ac, char **av, char **env)
{
  /*if (parse_arg(ac, av, env) == FAILURE)
    return (FAILURE);*/
  (void)ac;
  (void)av;
  return (shell(env));
}
