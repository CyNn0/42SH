/*
** print_env.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Thu May 19 18:58:06 2016 boris saint-bonnet
** Last update Mon Jun  6 04:42:18 2016 boris saint-bonnet
*/

#include		"42.h"

int			print_env(t_env *list)
{
  t_node		*tmp;

  tmp = list->head;
  if (!list->head->data)
    return (FAILURE);
  if (list != NULL)
    {
      while (tmp != NULL)
	{
	  if (strcmp("?", tmp->name))
	    printf("%s=%s\n", tmp->name, tmp->data);
	  tmp = tmp->next;
	}
    }
  return (0);
}

int			print_prompt(t_list *list)
{
  char			*dirname;
  char			*ptr_user;
  char			*prompt;
  
  if (isatty(0) != 1)
    return (FAILURE);
  if ((dirname = get_current_dir_name()) == NULL)
    dirname = "PWD";
  if ((ptr_user = find_user(list, "USER")) == NULL)
    ptr_user = "USER";
  if ((prompt = malloc((strlen(ptr_user) + strlen(dirname) + strlen(GREEN) +
			strlen(DEFAULT) + strlen(CYAN) + 4) * sizeof(char))) == NULL)
    return (FAILURE);
  memset(prompt, '\0', (strlen(ptr_user) + strlen(dirname) + strlen(GREEN) +
			strlen(DEFAULT) + strlen(CYAN) + 4));
  sprintf(prompt, "%s%s:%s%s %s", GREEN, ptr_user, CYAN, dirname, DEFAULT);
  set_pwd(prompt);
  write(1, prompt, strlen(prompt));
  xfree(dirname);
  xfree(prompt);
  return (SUCCESS);
}
