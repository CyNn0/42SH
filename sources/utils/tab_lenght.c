/*
** tab_lenght.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Sun May 22 07:40:30 2016 boris saint-bonnet
** Last update Sun May 22 09:21:55 2016 boris saint-bonnet
*/

# include "42.h"

int	tab_lenght(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
