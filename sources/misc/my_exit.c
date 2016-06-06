/*
** exit.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources/misc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon May 23 19:57:19 2016 Philippe Lefevre
** Last update Mon Jun  6 19:43:33 2016 boris saint-bonnet
*/

#include		"42.h"

int			my_exit(int status)
{
  exit(status);
  return (FAILURE);
}
