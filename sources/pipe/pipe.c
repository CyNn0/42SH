/*
** s for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/pipe
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:04:26 2016 Philippe Lefevre
** Last update Fri May 27 08:01:29 2016 Philippe Lefevre
*/

#include		"42.h"

#include		<sys/wait.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<string.h>

t_pipe			*create_tab_linked_cmd(t_cmd *cmd)
{
  t_pipe		*tab;
  t_cmd			*tmp;
  int			nb_pipe;
  int			i;

  nb_pipe = 0;
  tmp = cmd;
  while (tmp != NULL)
    {
      if (tmp->token == PIPE)
	nb_pipe += 1;
      tmp = tmp->next;
    }
  if ((tab = malloc(sizeof(t_pipe) * (nb_pipe + 1))) == NULL)
    return (NULL);
  tab[0].nb_pipe = nb_pipe;
  printf("%d\n", tab[0].nb_pipe);
  i = -1;
  tmp = cmd;
  while (++i < nb_pipe)
    {
      tab[i].beg = tmp;
      while (tmp->token != 2)
	tmp = tmp->next;
      tab[i].end = tmp;
      if (tmp->next && tmp->token == 2)
	tmp = tmp->next;
      printf("=========\n");
    }
  return (tab);
}

int			parsing_pipe(t_cmd *cmd, t_path *path, char **env)
{
  return (SUCCESS);
}
