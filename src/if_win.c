/*
** if_win.c for  in /home/MACKAO/delivery/my_sokoban
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Wed Dec 14 17:18:21 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 09:40:03 2016 Mackendy-pierre Anselin
*/

#include	<ncurses.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"fonction.h"
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"my_point.h"

t_my_point_o	*check_o(char **buffer, t_my_point_o *pnt_o, int nbr_o)
{
  int   i;
  int   x;
  int	count;

  i = 0;
  x = 0;
  count = 0;
  while (buffer[x])
    {
      while (buffer[x][i] != '\0')
	{
	  if (buffer[x][i] == 'O')
	    {
	      pnt_o[count].y = i;
	      pnt_o[count].x = x;
	      count++;
	    }
	  i++;
	}
      i = 0;
      i++;
      x++;
    }
  return (pnt_o);
}

int	the_nbr_o(char **buffer)
{
  int   i;
  int   x;
  int	nbr_o;

  i = 0;
  x = 0;
  nbr_o = 0;
  while (buffer[x])
    {
      while (buffer[x][i] != '\0')
	{
	  if (buffer[x][i] == 'O')
	    nbr_o++;
	  i++;
	}
      if (buffer[x][i] == '\0')
	i = 0;	
      x++;
    }
  return (nbr_o);
}

int	if_win(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (i < pnt->nbr_o)
    {
      if (buffer[pnt_o[i].x][pnt_o[i].y] == 'X')
	count++;
      i++;
    }
  if (count == pnt->nbr_o)
    {
      free(pnt_o);
      return (1);
    }
  return (0);
}

int	check_q(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt)
{
  if (if_win(buffer, pnt_o, pnt) == 1)
    {
      endwin();
      return (1);
    }
  return (0);
}
