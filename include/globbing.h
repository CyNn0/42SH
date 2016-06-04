/*
** globbing.h for globbing in /home/hubert_i/rendu/2015/PSU/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Jun  4 01:59:27 2016 Hubert Leo
** Last update Sat Jun  4 02:02:46 2016 Hubert Leo
*/

#ifndef			_GLOBBING_H_
# define		_GLOBBIN_H_

/*
** INCLUDES
*/

# include <glob.h>

/*
** FONCTIONS
*/

int		need_globbing(char *src);
char		*get_globbing(char *src);
char		*globbing(char *src);

#endif			/* !__GLOBBING_H_ */
