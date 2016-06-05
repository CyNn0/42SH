/*
** builtin.h for builtin in /home/hubert_i/rendu/2015/PSU/42SH/sources/builtin
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Mon May 23 18:01:20 2016 Hubert Leo
** Last update Sun Jun 05 14:05:48 2016 Gambini Lucas
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
  char			flag_help;
  char			flag_version;
  char			check_flags;
  int			i;
  char			space;
}			t_echo;

/*
** FONCTIONS
*/

/* ECHO */

t_echo			*init_echo();
int			check_options(t_echo *flags, char *cmd);
void			free_echo(t_echo *flags);
void			put_echo(char *str);
int			echo_print(t_echo *flags, char *cmd);
char			is_in_quotes(char *cmd);
int			builtin_echo(t_list *list, char **cmd);
int			builtin_setenv(t_list *list, char **cmd);
int			builtin_unsetenv(t_list *list, char **cmd);
char			*get_varenv(char *cmd, int i, int to_space);
int			count_to_space(char *cmd, int i);

/* CD */

char			*my_cd_bis(t_list *list, char **command, char *pwd);
int			my_cd_moins(t_list *list);
int			builtin_cd(t_list *list, char **command);
int			refresh_pwd(t_list *list, char **command);
char			*search_env(t_node *env, char *search);
int			countword(char *str, char caract);
int			current(char *str, char caract);
char			**my_str_to_wordtab(char *str, char caract);
char			*get_fusion(char *str, char *str2);
int			my_error(char *com, char *str);

/* RC */

int			builtin_source(t_list *list, char **cmd);
int			builtin_alias(t_list *list, char **cmd);

#endif			/* !__BUILTIN_H_ */
