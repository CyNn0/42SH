/*
** pre_check.c for  in /home/xx/Rendu/PSU/42SH/sources
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Wed May 18 04:54:23 2016 boris saint-bonnet
** Last update Wed May 18 06:43:33 2016 boris saint-bonnet
*/

# include "42.h"

char	*pre_check(char *s)
{
  char	*ret;

  ret = my_strdup(s);
  ret = check_right_redirection(ret);
  ret = check_left_redirection(ret);
  ret = check_separator(ret);
  ret = check_pipe(ret);
  ret = check_and(ret);
  printf("%s\n", ret);
  return (ret);
}
