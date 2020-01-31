##
## Makefile for  in /home/MACKAO/delivery/PSU_2016/PSU_2016_my_sokoban
## 
## Made by Mackendy-pierre Anselin
## Login   <MACKAO@epitech.net>
## 
## Started on  Tue Dec 20 20:13:54 2016 Mackendy-pierre Anselin
## Last update Tue Dec 20 20:14:05 2016 Mackendy-pierre Anselin
##


NAME	=	my_sokoban

SRCS	=	src/open_map.c		\
		src/move.c		\
		src/check.c		\
		src/if_win.c		\
		src/other_check.c	\
		src/display.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-I include

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lncurses

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
