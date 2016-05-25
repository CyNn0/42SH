/*
** builtins_scatter.c for 42sh in C:\Users\gambin_l\42SH\sources\parsing
**
** Made by Gambini Lucas
** Login   <Lucas Gambini@epitech.net>
**
** Started on  Wed May 25 11:40:09 2016 Gambini Lucas
** Last update Wed May 25 13:04:53 2016 Gambini Lucas
*/

# include 	"42.h"

int		builtin_scatter(t_list *list, t_cmd *cmd, int builtin)
{
  (void)list;
  (void)cmd;
  (builtin == 0) ? (printf("cd: %d\n", builtin))
    : ((builtin == 1) ? (printf("setenv: %d\n", builtin))
       : ((builtin == 2) ? (printf("unsetenv: %d\n", builtin))
	  : ((builtin == 3) ? (printf("echo: %d\n", builtin))
	     : ((printf("builtin not found\n"))))));
   return (SUCCESS);
}
