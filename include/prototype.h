/*
** prototype.h for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 18 05:04:14 2016 boris saint-bonnet
** Last update Thu May 19 21:51:20 2016 boris saint-bonnet
*/

#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

/*
** PARSING
*/

char	*pre_check(char *s);
char    *my_strcut(char *s, int beg, int nb, int end);
char    *check_and(char *s);
char    *check_left_redirection(char *s);
char    *check_pipe(char *s);
char    *check_right_redirection(char *s);
char    *check_separator(char *s);

/*
** STRING
*/

int	my_strlen(char *s);
char	*my_strdup(char *src);
char	*my_strcatc(char *path, char *command);
char    *my_epurstr(char *str);
char *strdup(const char *chaine);
char *get_current_dir_name(void);

# endif /* !PROTOTYPE_H__ */
