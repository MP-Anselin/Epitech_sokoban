/*
** map.c for  in /home/MACKAO/delivery/my_sokoban
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Mon Dec 12 10:43:30 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 09:40:31 2016 Mackendy-pierre Anselin
*/

#include    <ncurses.h>
#include    <string.h>
#include    <stdlib.h>
#include    <stdio.h>
#include    "fonction.h"
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <fcntl.h>
#include    <unistd.h>
#include    "my_point.h"

int move_p(char **buffer, t_my_point *pnt, t_my_point_o *pnt_o, int check) {
    if (check == 'z' || check == KEY_UP)
        move_up(buffer, pnt, pnt_o);
    else if (check == 's' || check == KEY_DOWN)
        move_down(buffer, pnt, pnt_o);
    else if (check == 'd' || check == KEY_RIGHT)
        move_right(buffer, pnt, pnt_o);
    else if (check == 'a' || check == KEY_LEFT)
        move_left(buffer, pnt, pnt_o);
}

int check_move(char **buffer, t_my_point *pnt, t_my_point_o *pnt_o, char **av) {
    int check;
    int y;
    int row;

    keypad(initscr(), TRUE);
    check = 0;
    while (check != 'q' && check != 27) {
        y = 0;
        clear();
        while (buffer[y]) {
            if (check_q(buffer, pnt_o, pnt) == 1)
                return (0);
            display(buffer, y);
            y++;
        }
        refresh();
        check = getch();
        if (check == 32)
            return (init_game(av));
        move_p(buffer, pnt, pnt_o, check);
    }
    endwin();
    return (1);
}

int nbr_column(char **av) {
    FILE *fp;
    char *line;
    size_t len;
    ssize_t read;
    int column;

    column = 0;
    fp = fopen(av[1], "r");
    line = NULL;
    len = 0;
    while ((read = getline(&line, &len, fp)) != -1)
        column++;
    fclose(fp);
    return (column);
}

char **my_buffer(char **av, char **buffer, size_t len, int x) {
    FILE *fp;
    char *line;
    ssize_t read;

    line = NULL;
    fp = fopen(av[1], "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        buffer[x] = malloc(sizeof(char) * (read + 1));
        init_buffer(buffer, line, x);
        x++;
    }
    buffer[x] = NULL;
    fclose(fp);
    if (line)
        free(line);
    return (buffer);
}

int main(int ac, char **av) {
    t_my_point *pnt;
    t_my_point_o *pnt_o;
    char **buffer;
    int check_error;

    if (first_error(av[1], ac) == 1)
        return (84);
    pnt = malloc(sizeof(t_my_point * ));
    noecho();
    buffer = init_my_buffer(av);
    if (error(buffer) == 1)
        return (84);
    pnt->nbr_o = the_nbr_o(buffer);
    pnt_o = malloc(sizeof(t_my_point_o * ) * pnt->nbr_o);
    if (pnt == NULL || pnt_o == NULL)
        return (84);
    pnt_o = check_o(buffer, pnt_o, pnt->nbr_o);
    pnt->px_max = check_px_max(buffer);
    pnt->px = check_px(buffer);
    pnt->p1 = check_p(buffer);
    if (check_move(buffer, pnt, pnt_o, av) == 0)
        return (0);
    return (1);
}
