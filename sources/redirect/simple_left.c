/*
** simple_left.c for simple_left in /home/hubert_i/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Thu May 26 01:33:04 2016 Hubert Leo
** Last update Sat May 28 11:43:09 2016 Gambini Lucas
*/

# include 	"42.h"

int		read_input_file(struct stat buf, int fd, t_red *var)
{
  char		*buff;

  if ((buff = malloc(sizeof(char) * (buf.st_size + 1))) == NULL)
    return (FAILURE);
  if (read(fd, buff, buf.st_size) == -1)
    return (FAILURE);
  buff[buf.st_size] = 0;
  var->buff_lred = strdup(buff);
  free(buff);
  return (SUCCESS);
}

int		simple_left(t_cmd *cmd, t_list *list, char **env, int builtin)
{
  t_red		var;
  int		fd;
  struct stat	buf;

  init_simpleleft(cmd->cmd, &var);
  if ((fd = open(var.name, O_RDONLY)) == -1)
    return (FAILURE);
  var.is_builtin = builtin;
  if (fstat(fd, &buf) == -1)
    return (FAILURE);
  if (read_input_file(buf, fd, &var) == FAILURE)
    return (FAILURE);
  if (exec_left(list, env, var) == FAILURE)
    check_go_on(cmd);
  close(fd);
  free(var.name);
  free(var.buff_lred);
  free_tab(var.cmd);
  return (SUCCESS);
}
