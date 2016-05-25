/*
** exec.h for exec in C:\Users\gambin_l\Shared\42SH\include
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Mon May 23 19:17:09 2016 Gambini Lucas
** Last update Wed May 25 15:37:02 2016 Gambini Lucas
*/

#ifndef                 _EXEC_H_
# define                _EXEC_H_

# include               <signal.h>

int                     check_built(t_list *list, t_cmd *cmd);
char                    *exec_find_path(t_path *path, char *bin);
int                     simple_exec(t_cmd *cmd, t_list *list,
				    char **env, int builtin);
int                     exec_right(int fd, t_list *list,
                                   char **env, t_right var);

#endif                  /* !_EXEC_H_ */
