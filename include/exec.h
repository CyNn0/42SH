/*
** exec.h for exec in C:\Users\gambin_l\Shared\42SH\include
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Mon May 23 19:17:09 2016 Gambini Lucas
** Last update Mon Jun 06 17:48:40 2016 Gambini Lucas
*/

#ifndef                 _EXEC_H_
# define                _EXEC_H_
# include		"42.h"

int                     check_built(t_list *list, t_cmd *cmd);
char                    *exec_find_path(t_path *path, char *bin);
int                     simple_exec(t_cmd *cmd, t_list *list,
				    char **env, int builtin);
int                     exec_right(int fd, t_list *list,
                                   char **env, t_cmd *cmd);
int                     exec_left(t_list *list,
				  char **env, t_cmd *cmd);
int			check_go_on(t_cmd *cmd);
void            	init_simpleleft(t_cmd *cmd, t_red *var);
int                     simple_exec2(t_cmd *cmd, t_list *list, char **env);

#endif                  /* !_EXEC_H_ */
