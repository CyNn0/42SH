/*
** linkedlist.h for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Wed May 18 04:22:31 2016 boris saint-bonnet
** Last update Wed May 18 10:04:35 2016 boris saint-bonnet
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
# define ENV_PATH list->myEnv->path

typedef struct          s_node
{
  char  *name;
  char  *data;
  struct s_node *prev;
  struct s_node *next;
}                       t_node;


typedef struct		s_path
{
  struct s_node		*head;
  struct s_node		*tail;  
}			t_path;

typedef struct		s_env
{
  struct s_path		*path;
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
  struct s_env	*myEnv;
  struct s_cmd *head;
  struct s_cmd *tail;
}                       t_list;

t_list  *create_list();
t_list  *push(t_list *list, t_cmd *cmd);
t_list  *get_circle(t_list *list);
t_list  *del_link(t_list *list, t_cmd *cmd);

# endif /* !__LINKED_LIST_H__ */
