/*
** check.c for  in /home/MACKAO/delivery/my_sokoban
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Tue Dec 13 11:14:50 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 10:56:55 2016 Mackendy-pierre Anselin
*/

#include	<ncurses.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"my_point.h"
#include	"fonction.h"

int	check_px_max(char **buffer)
{
  int   x;
  int   i;

  x = 0;
  i  = 0;
  while (buffer[x])
    {
      if (buffer[x][i] == '\0')
	{
	  x++;
	  i = 0;
	}
      i++;
    }
  x = x - 1;
  return (x);
}

int	check_px(char **buffer)
{
  int   p1;
  int   px;

  p1 = 0;
  px = 0;
  while (buffer[px][p1] != 'P')
    {
      if (buffer[px][p1] == '\n')
	{
	  px++;
	  p1 = 0;
	}
      p1++;
    }
  return (px);
}

int	check_p(char **buffer)
{
  int   p1;
  int   px;

  p1 = 0;
  px = 0;
  while (buffer[px][p1] != 'P')
    {
      if (buffer[px][p1] == '\n')
	{
	  p1 = 0;
	  px++;
	}
      p1++;
    }
  return (p1);
}

char	**init_my_buffer(char **av)
{
  size_t	len;
  int	x;
  char	**buffer;
  int	column;

  x = 0;
  len = 0;
  column = nbr_column(av);
  buffer = malloc(sizeof(char*) * (column + 1));
  buffer = my_buffer(av, buffer, len, x);
  return (buffer);
}

char	*init_buffer(char **buffer, char *line, int x)
{
  int	i;

  i = 0;
  while (line[i] != '\0')
    {
      buffer[x][i] = line[i];
      i++;
    }
  buffer[x][i] = '\0';
  return (buffer[x]);
}
