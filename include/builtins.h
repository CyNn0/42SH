/*
** builtin.h for builtin in /home/hubert_i/rendu/2015/PSU/42SH/sources/builtin
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Mon May 23 18:01:20 2016 Hubert Leo
** Last update Thu May 26 08:32:55 2016 Gambini Lucas
*/

#ifndef			_BUILTIN_H_
# define		_BUILTIN_H_

/*
** INCLUDES
*/

/*
** STRUCTURES
*/

typedef struct		s_echo
{
  char			flag_n;
  char 			flag_e;
  char			flag_E;
  char			flag_help;
  char			flag_version;
  char			check_flags;
}			t_echo;


/*
** FONCTIONS
*/

t_echo			*init_echo();
int			check_options(t_echo *flags, char *cmd);
void			free_echo(t_echo *flags);
void			put_echo(char *str);
int			print_varenv(char *cmd, int i, t_env *env);
int			echo_print(t_echo *flags, char *cmd, t_env *env);
char			is_in_quotes(char *cmd);
t_list			*builtin_echo(t_list *list, char **cmd);
t_list			*builtin_setenv(t_list *list, char **cmd);
t_list			*builtin_unsetenv(t_list *list, char **cmd);
char			*get_varenv(char *cmd, int i, int to_space);
int			count_to_space(char *cmd, int i);

#endif /* !__BUILTIN__ */
