/*
** set_exec.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Sun May 22 08:31:28 2016 boris saint-bonnet
** Last update Mon May 23 14:27:32 2016 boris saint-bonnet
*/

# include "42.h"

char		**set_sr(char **tab)
{
  int		i;
  int		j;
  char		**res;

  if ((res = malloc((tab_lenght(tab)) * sizeof(char *))) == NULL)
    return (NULL);
  i = -1;
  res[tab_lenght(tab) - 1] = NULL;
  while (tab[++i])
    {
      if (strcmp(tab[i], ">") == 0)
	{
	  res[0] = strdup(tab[++i]);
	  if ((tab_lenght(tab) - 1) == i)
	    j = 0;
	  else
	    j = i + 1;
	  i = 1;
	  break;
	}
    }
  while (tab[j] && strcmp(tab[j], ">") != 0)
    res[i++] = strdup(tab[j++]);
  free_tab(tab);
  return (res);
}

char		**set_dr(char **tab)
{
  int		i;
  int		j;
  char		**res;

  if ((res = malloc((tab_lenght(tab)) * sizeof(char *))) == NULL)
    return (NULL);
  i = -1;
  res[tab_lenght(tab) - 1] = NULL;
  while (tab[++i])
    {
      if (strcmp(tab[i], ">>") == 0)
	{
	  res[0] = strdup(tab[++i]);
	  if ((tab_lenght(tab) - 1) == i)
	    j = 0;
	  else
	    j = i + 1;
	  i = 1;
	  break;
	}
    }
  while (tab[j] && strcmp(tab[j], ">>") != 0)
    res[i++] = strdup(tab[j++]);
  free_tab(tab);
  return (res);
}
