/*
** mouve.c for  in /home/MACKAO/delivery/my_sokoban
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Mon Dec 12 17:03:13 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 20:15:30 2016 Mackendy-pierre Anselin
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

int	init_game(char **av)
{
  int   ac;

  ac = 2;
  main(ac,av);
}

void	move_up(char **buffer, t_my_point *pnt, t_my_point_o *pnt_o)
{
 if (pnt->px - 1 != 0 && buffer[pnt->px - 1][pnt->p1] == ' ' ||
	   buffer[pnt->px - 1][pnt->p1] == 'O')
    {
      display_o(buffer, pnt_o, pnt);
      pnt->px = pnt->px - 1;
      buffer[pnt->px][pnt->p1] = 'P';
    }
  if (pnt->px - 2 != 0 &&
      buffer[pnt->px - 1][pnt->p1] == 'X' &&
	   buffer[pnt->px - 1][pnt->p1] != '#' &&
	   buffer[pnt->px - 2][pnt->p1] != 'X' &&
	   buffer[pnt->px - 2][pnt->p1] != '#')
    {
      display_o(buffer, pnt_o, pnt);
      pnt->px = pnt->px - 1;
      buffer[pnt->px][pnt->p1] = 'P';
      buffer[pnt->px - 1][pnt->p1] = 'X';
    }
}

void	move_down(char **buffer, t_my_point *pnt, t_my_point_o *pnt_o)
{
  if (pnt->px + 1 != pnt->px_max &&
      buffer[pnt->px + 1][pnt->p1] == ' ' ||
      buffer[pnt->px + 1][pnt->p1] == 'O')
    {
      display_o(buffer, pnt_o, pnt);
      pnt->px = pnt->px + 1;
      buffer[pnt->px][pnt->p1] = 'P';
    }
  else if (pnt->px + 2 != pnt->px_max &&
	   buffer[pnt->px + 1][pnt->p1] == 'X' &&
	   buffer[pnt->px + 1][pnt->p1] != '#' &&
	   buffer[pnt->px + 2][pnt->p1] != 'X' &&
	   buffer[pnt->px + 2][pnt->p1] != '#')
    {
      display_o(buffer, pnt_o, pnt);
      pnt->px = pnt->px + 1;
      buffer[pnt->px][pnt->p1] = 'P';
      buffer[pnt->px + 1][pnt->p1] = 'X';
    }
}

void	move_right(char **buffer, t_my_point *pnt, t_my_point_o *pnt_o)
{
  int	wide;

  wide = wide_y(buffer, pnt);
  if (pnt->p1 + 1 != pnt->wide &&
      buffer[pnt->px][pnt->p1 + 1] == ' ' ||
      buffer[pnt->px][pnt->p1 + 1] == 'O')
    {
      display_o(buffer, pnt_o, pnt);
      pnt->p1 = pnt->p1 + 1;
      buffer[pnt->px][pnt->p1] = 'P';
    }
  else if (pnt->p1 + 2 != wide &&
	   buffer[pnt->px][pnt->p1 + 1] == 'X' &&
	   buffer[pnt->px][pnt->p1 + 2] != '#'
	   && buffer[pnt->px][pnt->p1 + 2] != 'X' )
    {
      display_o(buffer, pnt_o, pnt);
      pnt->p1 = pnt->p1 + 1;
      buffer[pnt->px][pnt->p1] = 'P';
      buffer[pnt->px][pnt->p1 + 1] = 'X';
    }
}

void	move_left(char **buffer, t_my_point *pnt, t_my_point_o *pnt_o)
{
  if (pnt->p1 - 1 != 0 && (buffer[pnt->px][pnt->p1 - 1] == ' '
			   || buffer[pnt->px][pnt->p1 - 1] == 'O'))
    {
      display_o(buffer, pnt_o, pnt);
      pnt->p1 = pnt->p1 - 1;
      buffer[pnt->px][pnt->p1] = 'P';
    }
  else if (pnt->p1 - 2 != 0 && buffer[pnt->px][pnt->p1 - 1] == 'X' &&
	   buffer[pnt->px][pnt->p1 - 2] != '#'
	   && buffer[pnt->px][pnt->p1 - 2] != 'X')
    {
        display_o(buffer, pnt_o, pnt);
      pnt->p1 = pnt->p1 - 1;
      buffer[pnt->px][pnt->p1] = 'P';
      buffer[pnt->px][pnt->p1 - 1] = 'X';
    }
}
