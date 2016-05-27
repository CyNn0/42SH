/*
** head.c for 42SH in /home/lefevr_h/Workspace/Github/42SH/sources
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Fri May 27 07:40:13 2016 Philippe Lefevre
** Last update Fri May 27 07:51:18 2016 Philippe Lefevre
*/

 #include		"42.h"

int			builtin_head(t_list *list, char **cmd)
{
  char			*line;
  int			len;
  int			fd;
  int			option;
  int			option_num;
  int			i;

  fd = 0;
  option = 1;
  option_num = 10;
  while ((line = get_next_line(fd)) != NULL && option_num > 0)
    {
      if (option == 0)
	{
	  len = strlen(line);

	}

    }
}
