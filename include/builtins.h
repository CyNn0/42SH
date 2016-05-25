/*
** builtin.h for builtin in /home/hubert_i/rendu/2015/PSU/42SH/sources/builtin
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Mon May 23 18:01:20 2016 Hubert Leo
** Last update Wed May 25 03:02:34 2016 Hubert Leo
*/

#ifndef		__BUILTIN__
# define	__BUILTIN__

/*
** INCLUDES
*/


/*
** STRUCTURES
*/

typedef struct	s_echo
{
  char		flag_n;
  char 		flag_e;
  char		flag_E;
  char		flag_help;
  char		flag_version;
  char		check_flags;
}		t_echo;


/*
** FONCTIONS
*/

t_echo		*init_echo();
int		check_options(t_echo *flags, char *cmd);
void		free_echo(t_echo *flags);
void		put_echo(char *str);
int		print_varenv(char *cmd, int i, t_env *env);
int		echo_print(t_echo *flags, char *cmd, t_env *env);
char		is_in_quotes(char *cmd);
int		exec_echo(t_cmd *cmd, t_env *env);
char		*get_varenv(char *cmd, int i, int to_space);
int		count_to_space(char *cmd, int i);

#endif /* !__BUILTIN__ */
