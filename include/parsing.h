/*
** parsing.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Fri May 20 07:33:52 2016 boris saint-bonnet
** Last update Sat May 21 08:51:06 2016 Lucas Gambini
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
char	**cmd_to_tab(char *line);

# endif /* __PARSING_H__ */
