/*
** cd.c for cd in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 24 14:35:00 2016 Hubert Leo
** Last update Fri May 27 11:49:08 2016 Hubert Leo
*/

#include "42.h"

int	countword(char *str, char caract)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i])
    {
      while (str[i] == caract)
	i++;
      if (str[i])
	c++;
      while (str[i] != caract && str[i] != 0)
	i++;
    }
  return (c);
}

int	current(char *str, char caract)
{
  int	i;

  i = 0;
  while (str[i] != caract && str[i] != '\0')
    i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, char caract)
{
  int	i;
  int	l;
  int	t;
  char	**tab;

  i = 0;
  l = 0;
  tab = malloc((countword(str, caract) + 1) * sizeof(char*));
  while (str[i] == caract)
    i++;
  while (str[i] != 0)
    {
      tab[l] = malloc((current(&str[i], caract) + 1) * sizeof(char));
      t = 0;
      while (str[i] != caract && str[i] != '\0')
	tab[l][t++] = str[i++];
      tab[l++][t] = '\0';
      while (str[i] == caract)
	i++;
    }
  tab[l] = NULL;
  return (tab);
}

char	*get_fusion(char *str, char *str2)
{
  char	*result;
  int	counter;
  int	counter2;

  counter = 0;
  counter2 = 0;
  if ((result = malloc(strlen(str) + strlen(str2) + 1)) == NULL)
    return (NULL);
  while (str[counter] != 0)
    {
      result[counter] = str[counter];
      counter++;
    }
  while (str2[counter2] != 0)
    {
      result[counter] = str2[counter2];
      counter2++;
      counter++;
    }
  result[counter] = '\0';
  return (result);
}

void	my_puterror(char c)
{
  write(2, &c, 1);
}

int	my_error(char *com, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '%' && str[i + 1] == 's')
	{
	  my_error(str, com);
	  i += 2;
	}
      my_puterror(str[i]);
      i++;
    }
  return (0);
}

char		*search_env(t_node *env, char *search)
{
  while (env)
    {
      if (strncmp(env->name, search, strlen(env->name)) == 0)
	return(env->data);
      env = env->next;
    }
  return (NULL);
}

int	refresh_pwd(t_list *list, char **command)
{
  char	buffer[4048];
  char	*pwd;
  char	**str;
  int	i;
  t_node *env;
  (void)command;

  env = list->myEnv->head;
  i = -1;
  while (getcwd(buffer, ++i) == NULL);
  pwd = get_fusion("cd PWD ", getcwd(buffer, i));
  str = my_str_to_wordtab(pwd, ' ');
  builtin_setenv(list, str);
  return (0);
}

int	exec_cd(t_list *list, char **command)
{
  char	*pwd;
  char	**str;
  char	*home;
  t_node *env;

  env = list->myEnv->head;
  puts("eco");
  pwd = "\0";
  if (command[1] != NULL)
    {
      if (command[1][0] == '-')
	return (my_cd_moin(list));
      if ((pwd = my_cd_bis(list, command, pwd)) == 0)
	return (-1);
      str = my_str_to_wordtab(get_fusion("s OLDPWD ",
					 search_env(env, "PWD")), ' ');
      builtin_setenv(list, str);
      if (refresh_pwd(list, command) == -1)
	return (-1);
    }
  else
    {
      if ((home = search_env(env, "HOME")) == NULL || home[0] == '\0')
	return (my_error(NULL, "HOME not found.\n"));
      str = my_str_to_wordtab(get_fusion("cd ", home), ' ');
      exec_cd(list, str);
    }
  return (0);
}

char	*my_cd_bis(t_list *list, char **command, char *pwd)
{
  t_node *env;

  env = list->myEnv->head;
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
      if (pwd[strlen(pwd) - 1] != '/')
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

int	my_cd_moin(t_list *list)
{
  char	*pwd;
  char	*old_pwd;
  char	**command;
  t_node *env;

  env = list->myEnv->head;
  if ((search_env(env, "OLDPWD")) != NULL
      && (search_env(env, "PWD")) != NULL)
    {
      old_pwd = search_env(env, "OLDPWD");
      pwd = search_env(env, "PWD");
      if (chdir(old_pwd) == -1)
	my_error(old_pwd, "%s: No such file or directory.\n");
      command = my_str_to_wordtab(get_fusion("s PWD ", old_pwd), ' ');
      builtin_setenv(list, command);
      command = my_str_to_wordtab(get_fusion("s OLDPWD ", pwd), ' ');
      builtin_setenv(list, command);
    }
  else
    my_error(NULL, "No PWD or OLDPWD found.\n");
  return (0);
}
