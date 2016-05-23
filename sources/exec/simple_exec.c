/*
** exec.c for exec in /home/puccio_c/rendu/minishell/42SH/sources/exec
**
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
**
** Started on  Mon May 23 13:05:23 2016 cyril puccio
** Last update Mon May 23 19:27:12 2016 Gambini Lucas
*/

# include "42.h"

int		simple_exec(t_cmd *cmd, t_path *path, char **env)
{
  pid_t		pid;
  char		*pass;
  int		status;
  t_node	*tmp;

  tmp = path->head;
  if ((pid = fork()) == 0 && access(cmd->cmd[0], X_OK) == 0)
    while (tmp != NULL)
      {
	pass = strcat(tmp->data, "/");
	pass = strcat(pass, cmd->cmd[0]);
	if (execve(pass, cmd->cmd, env) == -1)
	  return (-1);
	free(pass);
	tmp = tmp->next;
      }
  else
    waitpid(pid, &status, WSTOPPED);
  printf("%s: Command not found\n", cmd->cmd[0]);
  return (-1);
}
