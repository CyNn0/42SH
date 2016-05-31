/*
** inihb.c for H:\home\xx\Rendu\PSU\42SH in H:\home\xx\Rendu\PSU\42SH
**
** Made by
** Login   <Boris@epitech.net>
**
** Started on  Tue May 31 10:10:36 2016
** Last update Tue May 31 10:29:22 2016 Boris
*/

int	check_inihb(char *str)
{
  int	nb;

  nb = 0;
  while (*str)
    {
      if (*str == '"')
	nb+;
      str++;
    }
  return (nb == 2 ? SUCCESS : FAILURE);
}

char		*my_inihb(char *str)
{
  int		beg;
  int		i;

  i = -1;
  if (!str)
    return (NULL);
  if (check_inihb(str) == FAILURE)
    return (str);
  while (str[++i] != '"');
  beg = i;
  while (str[++i] != '"');
  return (my_strcut(str, (beg + 1), 0, (strlen(str) - i)));
}
