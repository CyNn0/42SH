/*
** double.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Fri May 20 07:30:47 2016 boris saint-bonnet
** Last update Fri Jun 03 13:11:21 2016 Philippe Lefevre
*/

#include	"42.h"

void		double_first(t_pars *var, char c)
{
  if (var->ret[0] == c && var->ret[1] && var->ret[1] == c &&
      var->ret[2] && var->ret[2] != ' ')
    {
      var->bef = my_strcut(var->ret, 0, 2, 0);
      var->aft = my_strcut(var->ret, 2, 0, 0);
      free(var->ret);
      var->ret = my_strcatc(var->bef, var->aft, 3, 0);
      free(var->aft);
    }
}

void		double_space_after(t_pars *var)
{
  if (var == NULL)
    return;
  var->bef = my_strcut(var->ret, 0, (var->i + 2), 0);
  var->aft = my_strcut(var->ret, (var->i + 2), 0, 0);
  free(var->ret);
  var->ret = my_strcatc(var->bef, var->aft, 3, 0);
  free(var->aft);
}

char		*doubles(char *s, char c)
{
  t_pars	var;

  var.ret = strdup(s);
  free(s);
  double_first(&var, c);
  while (check_finish(var.ret, c, 2) == -1)
    {
      var.i = -1;
      while (var.ret[++var.i])
	{
	  if (var.ret[var.i] == c && var.ret[var.i + 1] == c &&
	      var.ret[var.i - 1] != ' ')
	    {
	      var.bef = my_strcut(var.ret, 0, (var.i), 0);
	      var.aft = my_strcut(var.ret, (var.i), 0, 0);
	      free(var.ret);
	      var.ret = my_strcatc(var.bef, var.aft, 3, 0);
	      free(var.aft);
	    }
	  if (var.ret[var.i] == c && var.ret[var.i + 1] == c &&
	      var.ret[var.i + 2] != ' ')
	    double_space_after(&var);
	}
    }
  return (var.ret);
}
