/*
** linkedlist.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 04:22:31 2016 boris saint-bonnet
** Last update Fri May 20 04:51:26 2016 Lucas Gambini
*/

# ifndef __LINKED_LIST_H__
# define __LINKED_LIST_H__

/*
** DEFINE
*/

# define EXE 1 /* Simple execution */
# define PIPE  2 /* pipe */
# define SIMPLE_R 3 /* Simple redirection droite */
# define SIMPLE_L 4 /* simple redirection gauche*/
# define DOUBLE_R 5 /* double redirection droite */
# define DOUBLE_L 6 /* double redirection gauche */

typedef struct          s_node
{
  char			*name;
  char			*data;
  struct s_node		*prev;
  struct s_node		*next;
}                       t_node;


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
  char			flag;
  struct s_cmd		*prev;
  struct s_cmd		*next;
}                       t_cmd;

typedef struct          s_list
{
  struct s_path		*path;
  struct s_env		*myEnv;
  struct s_cmd		*head;
  struct s_cmd		*tail;
}                       t_list;

t_list  *create_list(t_list *list);
t_list  *push(t_list *list, t_cmd *cmd);
t_list  *push_env(t_list *list, char *data, char *name);
t_list  *get_circle(t_list *list);
t_list  *my_env_in_list(t_list *list, char **env);
t_list  *del_link(t_list *list, t_cmd *cmd);
t_list  *push_path(t_list *list, char *data);
t_list	*path_to_list(t_list *list);
int	 print_env(t_list *list);
int	get_name(char *name);
int	print_path(t_list *list);
char	*find_user(t_list *list, char *name);
char    *find_path(t_list *list);
void    print_prompt(t_list *list);
void	free_fighter(t_list *list);

# endif /* !__LINKED_LIST_H__ */
