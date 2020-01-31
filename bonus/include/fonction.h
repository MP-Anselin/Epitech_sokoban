/*
** fonction.h for  in /home/MACKAO/delivery/my_sokoban
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Tue Dec 13 15:31:56 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 10:50:10 2016 Mackendy-pierre Anselin
*/

#ifndef FONCTION_H_
# define FONCTION_H_
#include "my_point.h"

t_my_point_o	*check_o(char **buffer, t_my_point_o *pnt_o, int nbr_o);
void	display(char **buffer, int x);
int     longline(char **buffer);
int	move_p(char **buffer, t_my_point  *pnt,
	       t_my_point_o *pnt_o, int check);
int	main(int ac, char **av);
int	the_nbr_o(char **buffer);
int	check_px(char **buffer);
int	check_p(char **buffer);
int	nbr_column(char **av);
char	*init_buffer(char **buffer, char *line, int x);
char	**my_buffer(char **av, char **buffer, size_t len, int x);
void	move_up(char **buffer, t_my_point  *pnt, t_my_point_o  *pnt_o);
void	move_down(char **buffer, t_my_point  *pnt, t_my_point_o  *pnt_o);
void	move_right(char **buffer, t_my_point  *pnt, t_my_point_o  *pnt_o);
void	move_left(char **buffer, t_my_point  *pnt, t_my_point_o  *pnt_o);
char	**init_my_buffer(char **av);
int	init_game(char **av);
int	check_q(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt);
void	display_o(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt);
int	check_px_max(char **buffer);
int	nbr_p(char **buffer);
void	check_sec_o(char **buffer, t_my_point *point, int x, int i);
int	if_win(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt);
int	check_move(char **buffer, t_my_point *pnt,
		   t_my_point_o *pnt_o, char **av);
void	check_letf(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt);
void	check_right(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt);
void	check_down(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt);
void	check_up(char **buffer, t_my_point_o *pnt_o, t_my_point *pnt);
int     error(char **buffer);
int     check_error(char **buffer, t_my_check_error *error, int count);
int	first_error(char *av, int ac);
int	wide_y(char **buffer, t_my_point *pnt);

#endif /* !FONCTION_H_ */
