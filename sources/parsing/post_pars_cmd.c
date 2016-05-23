/*
** post_pars_cmd.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Sun May 22 04:40:04 2016 boris saint-bonnet
** Last update Mon May 23 14:23:11 2016 boris saint-bonnet
*/

# include "42.h"

void		check_flag(t_cmd *tmp)
{
  char		*redirect;
  int		i;
  
  redirect = "><";
  i = -1;
  while (tmp->cmd[++i])
    {
      if (tmp->cmd[i][0] == redirect[0])
	{
	  (tmp->cmd[i][1] == redirect[0]) ?
	    (tmp->flag = DOUBLE_R) : (tmp->flag = SIMPLE_R);
	  break;
	}
      else if (tmp->cmd[i][0] == redirect[1])
	{
	tmp->flag = (tmp->cmd[i][1] == redirect[1]) ?
	  (DOUBLE_L) : (SIMPLE_L);
	break;
	}
      else
	tmp->flag = (EXE);
    }
}

char		**set_exec(t_cmd *cmd)
{
  int		i;

  i = -1;
  while (cmd->cmd[++i])
    {
      if (cmd->flag == SIMPLE_R)
        return (cmd->cmd = set_sr(cmd->cmd));
      /* if (cmd->flag == DOUBLE_R) */
      /* 	return (res = set_dr(cmd->cmd, tab_lenght(cmd->cmd))); */
      /* if (cmd->flag == SIMPLE_L) */
      /* 	return (res = set_sl(cmd->cmd, tab_lenght(cmd->cmd))); */
      /* if (cmd->flag == DOUBLE_L) */
      /* 	return (res = set_dl(cmd->cmd, tab_lenght(cmd->cmd) + 1)); */
    }
  return(cmd->cmd);
}

t_list		*post_parser(t_list *list)
{
  t_cmd		*tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (tmp->token != PIPE)
	check_flag(tmp);
      tmp = tmp->next;
    }
  tmp = list->head;
  while (tmp != NULL)
    {
      set_exec(tmp);
      tmp = tmp->next;
    }
  return (list);
}
