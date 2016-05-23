/*
** exec.h for exec in C:\Users\gambin_l\Documents\Virtual Machines\Shared\42SH\include
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Mon May 23 19:17:09 2016 Gambini Lucas
** Last update Mon May 23 20:37:27 2016 Philippe Lefevre
*/

# ifndef __EXEC__
#define __EXEC__

# include	<signal.h>

char		*exec_find_path(t_path *path, char *bin);

int		simple_exec(t_cmd *cmd, t_path *path, char **env);
int		double_right(t_cmd *cmd, t_path *path, char **env);
int		simple_right(t_cmd *cmd, t_path *path, char **env);

# endif /* __EXEC__ */
