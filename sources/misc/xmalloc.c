/*
** xmalloc.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/misc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sun Jun 05 01:41:07 2016 Philippe Lefevre
** Last update Sun Jun 05 01:50:22 2016 Philippe Lefevre
*/

#include		"42.h"

void			*xmalloc(size_t size)
{
  void			*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      my_exit(FAILURE);
    }
  return (ptr);
}
