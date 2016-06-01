/*
** dep_cd.c for 42SH in C:\Users\gambin_l\42SH\sources\builtins\cd
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Fri May 27 14:23:26 2016 Gambini Lucas
** Last update Wed Jun 01 03:49:30 2016 Philippe Lefevre
*/

#include		"42.h"

int			countword(char *str, char caract)
{
  int			i;
  int			c;

  i = 0;
  c = 0;
  while (str[i])
    {
      while (str[i] == caract)
	i++;
      if (str[i])
	c++;
      while (str[i] != caract && str[i] != 0)
	i++;
    }
  return (c);
}

int			current(char *str, char caract)
{
  int			i;

  i = 0;
  while (str[i] != caract && str[i] != '\0')
    i++;
  return (i);
}

char			**my_str_to_wordtab(char *str, char caract)
{
  int			i;
  int			l;
  int			t;
  char			**tab;

  i = 0;
  l = 0;
  tab = malloc((countword(str, caract) + 1) * sizeof(char*));
  while (str[i] == caract)
    i++;
  while (str[i] != 0)
    {
      tab[l] = malloc((current(&str[i], caract) + 1) * sizeof(char));
      t = 0;
      while (str[i] != caract && str[i] != '\0')
	tab[l][t++] = str[i++];
      tab[l++][t] = '\0';
      while (str[i] == caract)
	i++;
    }
  tab[l] = NULL;
  return (tab);
}

char			*get_fusion(char *str, char *str2)
{
  char			*result;
  int			counter;
  int			counter2;

  counter = 0;
  counter2 = 0;
  if ((result = malloc(strlen(str) + strlen(str2) + 1)) == NULL)
    return (NULL);
  while (str[counter] != 0)
    {
      result[counter] = str[counter];
      counter++;
    }
  while (str2[counter2] != 0)
    {
      result[counter] = str2[counter2];
      counter2++;
      counter++;
    }
  result[counter] = '\0';
  return (result);
}

int			my_error(char *com, char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '%' && str[i + 1] == 's')
	{
	  my_error(str, com);
	  i += 2;
	}
      write(2, &str[i], 1);
      i++;
    }
  return (0);
}
