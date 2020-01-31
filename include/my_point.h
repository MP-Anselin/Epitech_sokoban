/*
** point_OO.h for  in /home/MACKAO/delivery/my_sokoban/include
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Wed Dec 14 09:39:02 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 10:36:47 2016 Mackendy-pierre Anselin
*/

#ifndef	_MY_POINT_H_
#define	_MY_POINT_H_

typedef  struct s_my_point
{
  int   first_o;
  int   second_o;
  int   first;
  int   second;
  int	px_max;
  int	nbr_o;
  int	px;
  int	p1;
  int	wide;
}	t_my_point;

typedef  struct s_my_point_o
{
  int	x;
  int	y;
}	t_my_point_o;

typedef  struct s_my_check_error
{
  int   line;
  int   nbr_o;
  int   nbr_wall;
  int   nbr_x;
  int	nbr_p;
}	t_my_check_error;

#endif	/* !MY_POINT_H_ */
