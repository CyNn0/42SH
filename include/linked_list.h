/*
** linkedlist.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:22:31 2016 boris saint-bonnet
** Last update Mon Jun 06 21:26:07 2016 Philippe Lefevre
*/

#ifndef			_LINKED_LIST_H_
# define		_LINKED_LIST_H_

/*
** DEFINE
*/

# define EXE 1 /* Simple execution */
# define PIPE 2 /* pipe */
# define DOUBLE_PIPE 3 /* double pipes */
# define SIMPLE_AND 4 /* & simple */
# define DOUBLE_AND 5 /* & double */
# define SIMPLE_R 6 /* Simple redirection droite */
# define SIMPLE_L 7 /* simple redirection gauche*/
# define DOUBLE_R 8 /* double redirection droite */
# define DOUBLE_L 9 /* double redirection gauche */

typedef int    bool;

# define false 0
# define true (!false);

typedef struct          s_node
{
  char			*name;
  char			*data;
  int			value_exit;
  int			p;
  char			god;
  struct s_node		*prev;
  struct s_node		*next;
}                       t_node;

typedef struct		s_pars
{
  int			i;
  char			*bef;
  char			*aft;
  char			*ret;
}			t_pars;

typedef struct		s_path
{
  struct s_node		*head;
  struct s_node		*tail;
}			t_path;

typedef struct		s_env
{
  struct s_node		*head;
  struct s_node		*tail;
}			t_env;

typedef struct          s_cmd
{
  int			*fd;
  char			**cmd;
  char			token;
  char			flag;
  bool			go_on;
  bool			is_exec;
  int			is_builtin;
  struct s_cmd		*prev;
  struct s_cmd		*next;
}                       t_cmd;

typedef struct		s_hist
{
  char			*s;
  struct s_hist		*next;
  struct s_hist		*prev;
}			t_hist;

typedef struct		s_history
{
  struct s_hist		*head;
  struct s_hist		*tail;
}			t_history;

typedef struct          s_bash
{
  struct s_node         *head;
  struct s_node         *tail;
}                       t_bash;

typedef struct          s_list
{
  struct s_path		*path;
  struct s_env		*myEnv;
  struct s_history	*myHist;
  struct s_bash		*myRc;
  struct s_cmd		*head;
  struct s_cmd		*tail;
  int			do_exit;
  int			value_exit;
  int			pipe_failure;
  int			history;
  char			*path_history;
}                       t_list;

typedef struct		s_red
{
  char			*name;
  char			**cmd;
  int			is_builtin;
}			t_red;

t_cmd                   *ret_cmd(t_cmd *cmd, char **tab);
t_red			parsing_sr(char **cmd);
t_red			parsing_dr(char **cmd);
t_list			*create_list(t_list *list);
t_list			*push(t_list *list, t_cmd *cmd);
t_list			*push_env(t_list *list, char *data, char *name);
t_list			*push_variable(t_list *list, char *name, char *data);
t_list			*get_circle(t_list *list);
t_list			*my_env_in_list(t_list *list, char **env);
t_list			*del_link(t_list *list, char *name);
t_list			*push_path(t_list *list, char *data);
t_list			*path_to_list(t_list *list);
t_list			*my_setenv(t_list *list, char **cmd);
t_list			*free_cmd(t_list *list);
t_list			*post_parser(t_list *list);
t_list			*get_cmd(t_list *cmd, char *line);
t_list			*push_cmd(t_list *list, char **cmd);
t_list			*add_history(t_list *list, char *line, int status);
t_list			*dbleft_buffer(t_list *list, char *buff);
t_bash			*push_bash(t_bash *list, char *data, char *name);
void			free_path(t_list *list);
void			free_node(t_node *tmp);
int			setenv_checking(t_list *list, char **cmd);
int			simple_right(t_cmd *cmd, t_list *list,
				     char **env, int builtin);
int			double_right(t_cmd *cmd, t_list *list,
				     char **env, int builtin);
int             	double_left(t_cmd *cmd, t_list *list,
				    char **env, int builtin);
int			simple_left(t_cmd *cmd, t_list *list,
				    char **env, int builtin);
int			print_env(t_env *list);
int			get_name(char *name);
int			print_path(t_list *list);
int			print_prompt(t_list *list);
char			*find_user(t_list *list, char *name);
char			*find_path(t_list *list);
char			*pre_check(char *s, t_list *list);
void			simple_first(t_pars *var, char c);
void			double_first(t_pars *var, char c);
void			init_double(t_cmd *cmd, t_red *var);
void			init_double_left(t_cmd *cmd, t_red *var);
void			init_var(t_cmd *cmd, t_red *var);
void			free_fighter(t_list *list);
void			show_cmd_list(t_list *list);
char			**extract_env(t_env *myEnv);
int			exec_scatter(t_list *list);
int			my_exit(int status);
int			builtin_exit(t_list *list, char **cmd);
int			scatter_pipe(t_cmd *cmd, t_list *list, char **env);
int			simple_exec_builtin(t_list *list, t_cmd *cmd,
					    int	builtin);
void			free_list_dbleft(t_list *list);
int			normal_scatter(t_cmd *cmd, char **env,
				       t_list *list, int builtin);
int			builtin_env(t_list *list, char **cmd);
int                     builtin_history(t_list *list, char **cmd);
int			bash_in_list(t_list *list);

#endif			/* !__LINKED_LIST_H__ */
