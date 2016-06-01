/*
** double_left.c for 42sh in C:\Users\gambin_l\42SH\sources\redirect
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Mon May 30 10:56:47 2016 Gambini Lucas
** Last update Wed Jun 01 15:50:28 2016 Gambini Lucas
*/

#include 		"42.h"

char			*my_concate(char *base, char *add)
{
  char			*ret;
  int			i;
  int			j;

  if (base == NULL || add == NULL)
    return (NULL);
  if ((ret = malloc(sizeof(char)
		    * (strlen(base) + strlen(add) + 2))) == NULL)
    return (NULL);
  i = -1;
  while (base[++i] != '\0')
    ret[i] = base[i];
  ret[i++] = '\n';
  j = 0;
  while (add[j] != '\0')
    ret[i++] = add[j++];
  ret[i] = '\0';
  return (ret);
}

char			*get_buffer(t_red var)
{
  char			*buff;
  char			*res;

  res = NULL;
  printf("%s\n", var.name);
  while (write(1, "? ", 2) && (buff = get_next_line(0)))
    {
      if (strcmp(buff, var.name) == 0)
	break;
      if (!res)
	res = strdup(buff);
      else
	res = my_concate(res, buff);
      free(buff);
    }
  return (res);
}

int			open_file(char *buff)
{
  int			fd;

  if ((fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, __RIGHT)) == -1)
    return (fprintf(stderr, "Error: %s: %s\n", strerror(errno),
		    ".tmp") * 0 + FAILURE);
    if (buff)
      write(fd, buff, strlen(buff));
    else
      return (FAILURE);
    close(fd);
    if ((fd = open(".tmp", O_RDONLY)) == -1)
      return (fprintf(stderr, "Error: %s: %s\n", strerror(errno),
		      ".tmp") * 0 + FAILURE);
      return (fd);
}

int			delete_tmp(char **env)
{
    char		*del[3];
    int			pid;

    del[0] = "/bin/rm";
    del[1] = ".tmp";
    del[2] = NULL;
    if ((pid = fork()) == -1)
      fprintf(stderr, "Error: Fork Failed\n");
    else if (pid == 0)
      {
        execve(del[0], del, env);
        my_exit(-1);
      }
    else
      xwaitpid(pid, 0, 0);
    return (SUCCESS);
}

int             	double_left(t_cmd *cmd, t_list *list,
				    char **env, int builtin)
{
  t_red       		var;
  char			*buff;
  int			fd;
  int			reset;

  init_double_left(cmd->cmd, &var);
  var.is_builtin = builtin;
  buff = get_buffer(var);
    if ((fd = open_file(buff)) == -1)
      return (FAILURE);
  reset = dup(0);
  dup2(fd, 0);
    show_tab(var.cmd);
  if (exec_left(list, env, var) == FAILURE)
    check_go_on(cmd);
  dup2(reset, 0);
  close(fd);
  delete_tmp(env);
  free(var.name);
  free_tab(var.cmd);
  return (SUCCESS);
}
