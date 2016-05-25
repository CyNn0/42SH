/*
** linkedlist.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:22:31 2016 boris saint-bonnet
** Last update Wed May 25 12:16:47 2016 Philippe Lefevre
*/

#ifndef			_LINKED_LIST_H__
# define		_LINKED_LIST_H__

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
  bool			p;
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
  int			fdin;
  int			fdout;
  char			**cmd;
  char			token;
  char			flag;
  bool			go_on;
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

typedef struct          s_list
{
  struct s_path		*path;
  struct s_env		*myEnv;
  struct s_history	*myHist;
  struct s_cmd		*head;
  struct s_cmd		*tail;
  int			do_exit;
  int			value_exit;
}                       t_list;

typedef struct		s_right
{
  char			*name;
  char			**cmd;
}			t_right;

t_right			parsing_sr(char **cmd);
t_right			parsing_dr(char **cmd);
t_list			*create_list(t_list *list);
t_list			*push(t_list *list, t_cmd *cmd);
t_list			*push_env(t_list *list, char *data, char *name);
t_list			*push_variable(t_list *list, char *name, char *data);
t_list			*get_circle(t_list *list);
t_list			*my_env_in_list(t_list *list, char **env);
t_list			*del_link(t_list *list, t_cmd *cmd);
t_list			*push_path(t_list *list, char *data);
t_list			*path_to_list(t_list *list);
t_list			my_setenv(t_list *list, t_cmd *cmd);
int			setenv_checking(t_list *list);
int			simple_right(t_cmd *cmd, t_path *path, char **env);
int			double_right(t_cmd *cmd, t_path *path, char **env);
int			print_env(t_env *list);
int			get_name(char *name);
int			print_path(t_list *list);
char			*find_user(t_list *list, char *name);
char			*find_path(t_list *list);
void			simple_first(t_pars *var, char c);
void			double_first(t_pars *var, char c);
void			init_double(char **cmd, t_right *var);
void			init_var(char **cmd, t_right *var);
void			print_prompt(t_list *list);
void			free_fighter(t_list *list);
t_list			*get_cmd(t_list *cmd, char *line);
t_list			*push_cmd(t_list *list, char **cmd);
void			show_cmd_list(t_list *list);
t_list			*free_cmd(t_list *list);
t_list			*post_parser(t_list *list);
char			**extract_env(t_env *myEnv);
int			exec_scatter(t_list *list);
int			normal_scatter(t_cmd *cmd, char **env, t_path *path);
t_list			*add_history(t_list *list, char *line);
void			my_exit(int status);
int			builtin_exit(t_list *list, char *str);

#endif			/* !__LINKED_LIST_H__ */
