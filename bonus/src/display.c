/*
** display.c for  in /home/MACKAO/delivery/PSU_2016/PSU_2016_my_sokoban
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Mon Dec 19 20:10:44 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 10:31:22 2016 Mackendy-pierre Anselin
*/

#include	<ncurses.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"include/fonction.h"
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"my_point.h"

void	display_o(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt)
{
  int   i;

  i = 0;
  while (i < pnt->nbr_o)
    {
      if (buffer[pnt->px][pnt->p1] == buffer[pnt_o[i].x][pnt_o[i].y])
	buffer[pnt->px][pnt->p1] = 'O';
      i++;
    }
  if (buffer[pnt->px][pnt->p1] != 'O')
    buffer[pnt->px][pnt->p1] = ' ';
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	longline(char **buffer)
{
  int   tmp;
  int   cpt;
  int   line;

  line = 0;
  tmp = 0;
  cpt = 0;
  while (buffer[cpt] != '\0')
    {
      tmp = my_strlen(buffer[cpt]);
      if (tmp > line)
	line = tmp;
      cpt++;
    }
  return (cpt);
}

void	display(char **buffer, int x)
{
  int	long_line;
  int	width;
  int	length;
  int	row;
  int	col;

  width = 0;
  length = 0;
  long_line = longline(buffer);
  getmaxyx(stdscr, row, col);
  if (((LINES) > long_line))
    mvprintw((LINES / 2) / 2 + x, (COLS / 2) - long_line, buffer[x]);
  else
    mvprintw((row / 2), (col - 26), "Enlarge the window, please");
}
