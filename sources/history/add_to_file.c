/*
** add_to_file.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Tue May 31 18:46:34 2016 boris saint-bonnet
** Last update Tue May 31 19:40:23 2016 boris saint-bonnet
*/

#include		"42.h"

int		open_history(char *s)
{
  int		fd;

  if ((fd = open(".42history", __DOUBLE)) == -1)
    {
      fprintf("Error: loading history\n");
      return (FAILURE);
    }
  write(fd, s, strlen(s));
}
