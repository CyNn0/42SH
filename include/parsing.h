/*
** parsing.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Fri May 20 07:33:52 2016 boris saint-bonnet
** Last update Tue May 31 14:44:04 2016 cyril puccio
*/

#ifndef			_PARSING_H_
# define		_PARSING_H_

int 			check_finish(char *s, char c, int nb);
int 			triple(char *s);
int 			check_bquotes(char *str);
int 			check_error(char *s);
char			*my_strcatc(char *path, char *command, int cond,
				    int bool);
char			*my_strcatenv(char *path, char *command);
char			*my_bquotes(char *str);
char			*doubles(char *s, char c);
char			*simples(char *s, char c);
void			simple_space_after(t_pars *var);

char			**cmd_to_tab(char *line, char sp1, char sp2, char sp3);
char			**clean_tab(char **tab);
void			show_tab(char **tab);
void			free_tab(char **tab);
char			*open_bash(char *arg, char *cmd);

#endif			/* _PARSING_H_ */
