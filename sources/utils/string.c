/*
** string.c for  in /home/xx/Rendu/PSU/42SH/sources
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Thu May 19 23:24:51 2016 boris saint-bonnet
** Last update Fri May 20 07:47:11 2016 boris saint-bonnet
*/

# include "42.h"

char            *my_epurstr(char *str)
{
  int           i;
  int           j;
  char          *epured;

  i = 0;
  j = 0;
  if ((epured = malloc(sizeof(epured) * strlen(str))) == NULL)
    return (NULL);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  epured[j++] = ' ';
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
      epured[j++] = str[i++];
    }
  epured[j] = '\0';
  if (epured[j - 1] == ' ')
    epured[j - 1] = '\0';
  return (epured);
}
