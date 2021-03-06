/*
** interface.c for  in /home/MACKAO/delivery/PSU_2016/PSU_2016_my_sokoban/BONUS/src
** 
** Made by Mackendy-pierre Anselin
** Login   <MACKAO@epitech.net>
** 
** Started on  Tue Dec 20 16:41:30 2016 Mackendy-pierre Anselin
** Last update Tue Dec 20 17:53:52 2016 Mackendy-pierre Anselin
*/

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] = {
  "1 player",
  "2 players",
  "Exit",
};

int n_choices = sizeof(choices) / sizeof(char *);

void	print_menu(WINDOW *menu_win, int highlight)
{
  int x, y, i;

  x = 2;
  y = 2;
  box(menu_win, 0, 0);
  for(i = 0; i < n_choices; ++i)
    {if(highlight == i + 1)
	{wattron(menu_win, A_REVERSE);
	  mvwprintw(menu_win, y, x, "%s", choices[i]);
	  wattroff(menu_win, A_REVERSE);
	}
      else
	mvwprintw(menu_win, y, x, "%s", choices[i]);
      ++y;
    }
  wrefresh(menu_win);
}

int	main()
{
  WINDOW	*menu_win;
  int	highlight = 1;
  int	choice = 0;
  int	c;
  
}
