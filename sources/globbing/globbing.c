/*
** globbing.c for  in /home/hubert_i/rendu/2015/PSU/42SH
**
** Made by Hubert Leo
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Jun  4 01:57:24 2016 Hubert Leo
** Last update Sat Jun 04 02:44:39 2016 Philippe Lefevre
*/

#include "42.h"

int		need_globbing(char *src)
{
  int		i;

  i = -1;
  while (src[++i])
    {
      if (src[i] == '*')
	return (1);
    }
  return (0);
}

char		*get_globbing(char *src)
{
  glob_t	globbuf;
  char		*result;
  int		i;

  globbuf.gl_offs = 0;
  result = "\0";
  i = 0;
  if (glob(src, GLOB_DOOFFS | GLOB_NOMATCH, NULL, &globbuf) != 0)
    return (NULL);
  while (globbuf.gl_pathv[i])
    {
      if (i != 0)
	result = get_fusion(result, " ");
      result = get_fusion(result, globbuf.gl_pathv[i]);
      i++;
    }
  free(src);
  i = 0;
  while (globbuf.gl_pathv[i])
    free(globbuf.gl_pathv[i++]);
  return (result);
}

char		*globbing(char *src)
{
  char		**args;
  char		*result;
  char		*tmp;
  int		i;

  if (src == NULL || (args = my_str_to_wordtab(src, ' ')) == NULL)
    return (NULL);
  result = "\0";
  i = 0;
  while (args[i])
    {
      if (i != 0)
	result = get_fusion(result, " ");
      if (need_globbing(args[i]) == 1)
      	{
      	  if ((tmp = get_globbing(args[i])) == NULL)
	    {
	      fprintf(stderr, "%s: No match.\n", args[i - 1]);
	      return (NULL);
	    }
	  result = get_fusion(result, tmp);
      	}
      else
	result = get_fusion(result, args[i]);
      i++;
    }
  free(args);
  if (result[0] == '\0')
    return (src);
  else
    return (result);
}
