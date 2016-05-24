/*
** exec.h for exec in C:\Users\gambin_l\Shared\42SH\include
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Mon May 23 19:17:09 2016 Gambini Lucas
** Last update Tue May 24 13:04:51 2016 Gambini Lucas
*/

#ifndef			_EXEC_H_
# define		_EXEC_H_

# include		<signal.h>

int			check_built(t_cmd *cmd);

char			*exec_find_path(t_path *path, char *bin);

int			simple_exec(t_cmd *cmd, t_path *path, char **env);
int			double_right(t_cmd *cmd, t_path *path, char **env);
int			simple_right(t_cmd *cmd, t_path *path, char **env);

#endif			/* !_EXEC_H_ */
