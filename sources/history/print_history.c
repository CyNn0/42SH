/*
** print_history.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Mon Jun  6 07:31:04 2016 boris saint-bonnet
** Last update Mon Jun  6 07:45:14 2016 boris saint-bonnet
*/

#include		"42.h"

int			print_history(char **tab)
{
  int			i;

  i = -1;
  while (tab[++i][1])
    printf("%d %s\n", (i + 1), tab[i]);
  return (SUCCESS);
}

int			printx_history(char **tab, int nb)
{
  int			i;
  if (nb >= tab_lenght(tab))
    print_history(tab);
  else
    {
      i = (tab_lenght(tab) - (nb + 1));
      printf(" i :%d\n", i);
      while (tab[i][1])
	{
	  printf("%d %s\n", (i + 1), tab[i]);
	  i++;
	}
    }
  return (SUCCESS);
}
