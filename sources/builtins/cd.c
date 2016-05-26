/*
** cd.c for cd in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 24 14:35:00 2016 Léo Hubert
** Last update Thu Apr 14 13:30:51 2016 Léo Hubert
*/

#include "my.h"

int	refresh_pwd(t_env *env, char **command)
{
  char	buffer[4048];
  char	*pwd;
  char	**str;
  int	i;
  (void)command;

  i = -1;
  while (getcwd(buffer, ++i) == NULL);
  pwd = get_fusion("cd PWD ", getcwd(buffer, i));
  str = my_str_to_wordtab(pwd, ' ');
  my_set(env, str);
  return (0);
}

int	my_cd(t_env *env, char **command)
{
  char	*pwd;
  char	**str;
  char	*home;

  pwd = "\0";
  if (command[1] != NULL)
    {
      if (command[1][0] == '-')
	return (my_cd_moin(env));
      if ((pwd = my_cd_bis(env, command, pwd)) == 0)
	return (-1);
      str = my_str_to_wordtab(get_fusion("s OLDPWD ",
					 search_env(env, "PWD")), ' ');
      my_set(env, str);
      if (refresh_pwd(env, command) == -1)
	return (-1);
    }
  else
    {
      if ((home = search_env(env, "HOME")) == NULL || home[0] == '\0')
	return (my_error(NULL, "HOME not found.\n"));
      str = my_str_to_wordtab(get_fusion("cd ", home), ' ');
      my_cd(env, str);
    }
  return (0);
}

char	*my_cd_bis(t_env *env, char **command, char *pwd)
{
  if (command[1][0] == '/')
    {
      if (chdir(command[1]) == -1)
	{
	  my_error(command[1], "%s: No such file or directory.\n");
	  return (0);
	}
      pwd = command[1];
    }
  else
    {
      pwd = search_env(env, "PWD");
      if (pwd[my_strlen(pwd) - 1] != '/')
	pwd = get_fusion(pwd, "/");
      pwd = get_fusion(pwd, command[1]);
      if (chdir(pwd) == -1)
	{
	  my_error(command[1], "%s: No such file or directory.\n");
	  return (0);
	}
    }
  return (pwd);
}

int	my_cd_moin(t_env *env)
{
  char	*pwd;
  char	*old_pwd;
  char	**command;

  if ((search_env(env, "OLDPWD")) != NULL
      && (search_env(env, "PWD")) != NULL)
    {
      old_pwd = search_env(env, "OLDPWD");
      pwd = search_env(env, "PWD");
      if (chdir(old_pwd) == -1)
	my_error(old_pwd, "%s: No such file or directory.\n");
      command = my_str_to_wordtab(get_fusion("s PWD ", old_pwd), ' ');
      my_set(env, command);
      command = my_str_to_wordtab(get_fusion("s OLDPWD ", pwd), ' ');
      my_set(env, command);
    }
  else
    my_error(NULL, "No PWD or OLDPWD found.\n");
  return (0);
}
