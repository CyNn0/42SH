/*
** cd.c for cd in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 24 14:35:00 2016 Hubert Leo
** Last update Sun Jun 05 04:23:17 2016 Philippe Lefevre
*/

#include 		"42.h"

char			*search_env(t_node *env, char *search)
{
  while (env)
    {
      if (strncmp(env->name, search, strlen(env->name)) == 0)
	return (env->data);
      env = env->next;
    }
  return (NULL);
}

int			refresh_pwd(t_list *list, char **command)
{
  char			buffer[4048];
  char			*pwd;
  char			**str;
  int			i;

  (void)command;
  i = -1;
  while (getcwd(buffer, ++i) == NULL);
  pwd = get_fusion("cd PWD ", getcwd(buffer, i));
  str = my_str_to_wordtab(pwd, ' ');
  builtin_setenv(list, str);
  return (0);
}

int			my_cd_moins(t_list *list)
{
  char			*pwd;
  char			*old_pwd;
  char			**command;
  t_node 		*env;

  env = list->myEnv->head;
  if ((search_env(env, "OLDPWD")) != NULL
      && (search_env(env, "PWD")) != NULL)
    {
      old_pwd = search_env(env, "OLDPWD");
      pwd = search_env(env, "PWD");
      if (chdir(old_pwd) == -1)
	fprintf(stderr, "%s: %s.\n", old_pwd, strerror(errno));
      command = my_str_to_wordtab(get_fusion("s PWD ", old_pwd), ' ');
      builtin_setenv(list, command);
      command = my_str_to_wordtab(get_fusion("s OLDPWD ", pwd), ' ');
      builtin_setenv(list, command);
    }
  else
    my_error(NULL, "No PWD or OLDPWD found.\n");
  return (0);
}

int			builtin_cd(t_list *list, char **command)
{
  char			*pwd;
  char			**str;
  char			*home;
  t_node 		*env;

  env = list->myEnv->head;
  pwd = "\0";
  if (command[1] != NULL)
    {
      if (command[1][0] == '-')
	return (my_cd_moins(list));
      if ((pwd = my_cd_bis(list, command, pwd)) == 0)
	return (FAILURE);
      str = my_str_to_wordtab(get_fusion("s OLDPWD ",
					 search_env(env, "PWD")), ' ');
      builtin_setenv(list, str);
      return ((refresh_pwd(list, command) == -1) ? (FAILURE) : (SUCCESS));
    }
  else
    {
      if ((home = search_env(env, "HOME")) == NULL || home[0] == '\0')
	return (my_error(NULL, "HOME not found.\n"));
      builtin_cd(list, my_str_to_wordtab(get_fusion("cd ", home), ' '));
    }
  return (SUCCESS);
}

char			*my_cd_bis(t_list *list, char **command, char *pwd)
{
  t_node 		*env;

  env = list->myEnv->head;
  if (command[1][0] == '/')
    {
      if (chdir(command[1]) == -1)
	{
	  fprintf(stderr, "%s: %s.\n", command[1], strerror(errno));
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
	  fprintf(stderr, "%s: %s.\n", command[1], strerror(errno));
	  return (0);
	}
    }
  return (pwd);
}
