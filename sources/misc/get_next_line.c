/*
** get_next_line.c for get_next_line in /home/puccio_c/rendu/minishell/PSU_2015_minishell2/lib/my/src
**
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
**
** Started on  Wed Apr 27 14:48:02 2016 cyril puccio
** Last update Sun Jun 05 05:12:18 2016 Philippe Lefevre
*/

#include	"42.h"

static int      my_lenstr(char *s)
{
  int           i;

  i = -1;
  while (s[++i]);
  return (i);
}

static char     *my_sstrncpy(char *d, char *s, int n)
{
  while (*s && n-- > 0)
    *d++ = *s++;
  (n == 0) ? *d = '\0' : 0;
  return (d);
}

static void     *my_malloc(unsigned int size)
{
  void          *p;

  return (((p = malloc(size)) == 0) ? NULL : p);
}

static char     *add_to_line(char *line, int cur, char *buff, int *start)
{
  char          *new;
  int           old;

  old = (line) ? my_lenstr(line) : 0;
  if ((new = my_malloc((old + cur + 1) * sizeof(*new))) == NULL)
    return (NULL);
  my_sstrncpy(new, line ? line : "", old);
  my_sstrncpy(new + old, buff + *start, cur);
  new[old + cur] = 0;
  if (line)
    free(line);
  *start += cur + 1;
  return (new);
}

char            *get_next_line(const int fd)
{
  static char   buff[READ_SIZE + 1];
  static int    ret = 0;
  static int    start;
  int           cur;
  char          *line;

  line = 0;
  cur = 0;
  while (1)
    {
      if (start >= ret)
        {
          start = 0;
          if (!(ret = read(fd, buff, READ_SIZE)))
            return (line);
          if (ret == -1)
	    return (NULL);
          cur = 0;
        }
      if (buff[start + cur] == '\n')
        return (line = add_to_line(line, cur, buff, &start));
      if (start + cur == ret - 1)
        line = add_to_line(line, cur + 1, buff, &start);
      cur++;
    }
}
