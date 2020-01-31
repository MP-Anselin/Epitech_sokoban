/*
** other_check.c for  in /home/MACKAO/delivery/PSU_2016_my_/PSU_2016_my_sokoban
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Thu Dec 15 15:40:51 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 20:15:55 2016 Mackendy-pierre Anselin
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

int	wide_y(char **buffer, t_my_point *pnt)
{
  int	count;

  count = 0;
  while (buffer[pnt->px][count])
    count++;
  return (count);
}

int	first_error(char *av, int ac)
{
  FILE	*fp;

  if (ac != 2)
    return (1);
  fp = fopen(av, "r");
  if (fp == NULL)
      return (1);
  fclose(fp);
  return (0);
}

int	init_error(t_my_check_error *error, char **buffer)
{
  int	y;
  int	i;
  int	position;

  i = 0;
  y = 0;
  position = 0;
  while (buffer[y])
    {
      if (buffer[y][0] == 'P' || buffer[y][0] == 'X')
	position++;
      y++;
    }
  if (error->line < 2 || error->nbr_p != 1 || error->nbr_o != error->nbr_x ||
      error->nbr_o == 0 || error->nbr_x == 0 || error->nbr_wall == 0
      || position != 0)
    return (1);
  return (0);
}

int	check_error(char **buffer, t_my_check_error *error, int count)
{
  int	y;

  y = 0;
  while (buffer[y])
    {
      count = 0;
      while (buffer[y][count] != '\0')
	{
	  if (buffer[y][count] == 'O')
	    error->nbr_o++;
	  if (buffer[y][count] == 'X')	
	    error->nbr_x++;
	  if (buffer[y][count] == 'P')
	    error->nbr_p++;
	  if (buffer[y][count] == '#')
	    error->nbr_wall++;
	  if (buffer[y][count] == '\n')
	    error->line++;
	  count++;
	}
      y++;
    }
  if (init_error(error, buffer) == 1)
    return (1);
  return (0);
}

int	error(char **buffer)
{
  t_my_check_error	*error;
  int	count;

  count = 0;
  error = malloc(sizeof(t_my_check_error));
  if (error == NULL)
    return (1);
  error->line = 0;
  error->nbr_o = 0;
  error->nbr_x = 0;
  error->nbr_p = 0;
  error->nbr_wall = 0;
  if (check_error(buffer, error, count) == 1)
    return (1);
  return (0);
}
