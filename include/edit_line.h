/*
** edit_line.h for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Sun Jun  5 04:03:18 2016 boris saint-bonnet
** Last update Mon Jun  6 03:07:01 2016 boris saint-bonnet
*/

#ifndef			__EDIT_H__
# define		__EDIT_H__

/*
**			LINKED_LIST
*/

typedef struct		s_char
{
  char			c;
  struct s_char		*prev;
  struct s_char		*tail;
}			t_char;

typedef struct          s_capacity
{
  char                  *str_clear;
  char                  *str_down;
  char                  *str_up;
  char                  *str_left;
  char                  *str_right;
  char                  *str_ce;
  char                  *str_cd;
}                       t_capacity;

typedef struct		s_pos
{
  int			startx;
  int			starty;
  int			currx;
  int			curry
}			t_pos;

typedef struct		s_line
{
  int			fd;
  struct s_capacity	capacity;
  struct s_char		*head;
  struct s_pos		cursor;
}			t_line;

#endif		/* !__EDIT_H__ */
