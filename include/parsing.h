/*
** parsing.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Fri May 20 07:33:52 2016 boris saint-bonnet
** Last update Sun May 22 06:31:16 2016 boris saint-bonnet
*/

# ifndef __PARSING_H__
# define __PARSING_H__

int     check_finish(char *s, char c, int nb);
int     triple(char *s);
int	check_bquotes(char *str);
char    *my_strcatc(char *path, char *command, int cond, int bool);
char	*my_bquotes(char *str);
char    *doubles(char *s, char c);
char    *simples(char *s, char c);
void    simple_space_after(t_pars *var);
void    check_flag(t_cmd *tmp);
char	**cmd_to_tab(char *line, char sp1, char sp2, char sp3);
char	**clean_tab(char **tab);
void	show_tab(char **tab);
void	free_tab(char **tab);
t_list	*post_parser(t_list *list);

# endif /* __PARSING_H__ */
