/*-----------------------------------------------------------------
*	colordemo.c	-	curses color demo
Wed Nov 12 12:56:14 PST 2014 TEK
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include <termio.h>

#define WIDTH 30
#define HEIGHT 10

	int f, b,  R, G, B ;
	int setfb(char) ;
	//int modf(char ) ;
	char * choices[] = {
	"F1 = Set Foreground",
	"F2 = Set Background",
	"F3 = Modify RED content",
	"F4 = Modify GREEN content",
	"F5 = Modify BLUE content",
	"F8 = Quit program" } ;

	int n_choices = sizeof(choices) / sizeof(char *);

	void print_menu(WINDOW *menu_win, int highlight);

int main (int argc, char *argv[], char **env)
{
	#define FORGROUND  1
	#define BACKGROUND 1
	WINDOW * menu_win ;
	int highlight = 1 ;
	int choice = 0 ;
	int c ;
	initscr() ;
	clear() ;
	noecho() ;
	cbreak() ;
	int startx = (80 - WIDTH) / 2;
	int starty = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT,WIDTH, starty, startx) ;
	keypad(menu_win, TRUE) ;
	refresh() ;
	if (!has_colors())
	{
		endwin() ;
		puts("Endwin called") ;
		fprintf(stderr,"\ncolor not supported\n") ;
	//	exit(1) ;
	}
	start_color() ;
	init_pair(1,COLOR_YELLOW, COLOR_GREEN) ; // pair receives a number
	attron(COLOR_PAIR(1)) ;                // number used
	//	process() ;
	while(1)
	{
		c = wgetch(menu_win) ;
		switch(c)
		{
			case KEY_UP:
				if (highlight == 1)
					highlight = n_choices ;
				else
					--highlight ;
			break ;
			case KEY_DOWN:
				if (highlight == n_choices)
					highlight - 1 ;
				else
					++highlight ;
			break ;
			case 10:
				choice = highlight ;
			break ;
			default:
				mvprintw(24,0, "Character pressed is $03d, hopefully it will display as %c", c, c) ;
				refresh() ;
			break ;
		} ; //switch
	} // shell
	refresh() ;
	print_menu(menu_win, highlight) ;
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	refresh() ;
	clrtoeol() ;
	refresh() ;
		endwin() ;
		return(0) ;
} // main

	int fillwin()
	{
		register y, x ;
		move(0,0) ;
		for (y = 0 ; y < LINES ; y++)
			for (x = 0 ; x < COLS ; x++)
				addch(' ' ) ;
	} // fillwin

	int process()
	{
		int c ;
		while(1)
		{
			mvprintw(10,15,"Function Keys are:") ;
			mvprintw(13,15,"F1 = Set Foreground") ;
			mvprintw(14,15,"F2 = Set Background") ;
			mvprintw(15,15,"F3 = Modify RED content") ;
			mvprintw(16,15,"F4 = Modify GREEN content") ;
			mvprintw(18,15,"F5 = Modify BLUE content") ;
			mvprintw(10,15,"F8 = Quit program") ;
			refresh() ;
			c = getch() ;
			addch(c) ;
			refresh() ;
			switch(c)
			{
				case KEY_F(1): 
					setfb(FORGROUND) ;
					break ;
				case KEY_F(2): 
					setfb(BACKGROUND) ;
					break ;
				case KEY_F(3):
					setfb(COLOR_RED) ;
				break ;
				case KEY_F(4): 
					setfb(COLOR_GREEN) ; 
					break ;
				case KEY_F(5): 
					setfb(COLOR_BLUE) ;
					break ;
				case KEY_F(8): return ;
				break ;
				default:
					beep() ;
			} //switch
		} //while
	} // process
			
	int setfb(char setting)
	{
		fillwin() ;
		mvprintw(12,10, "Use KEY_LEFT 'h', KEY_RIGHT 'l'") ;
		mvprintw(13,10, "F1'g' to select") ;
		refresh() ;
		while(1)
		{
			switch(getch())
			{
				case 'h' :
				case KEY_LEFT : 	
					if (setting == FORGROUND)
						f = f == 0 ? COLORS - 1 : f - 1 ;
					else
						b = b == 0 ? COLORS - 1 : b - 1 ;
				break ;

				case 'l':
				case KEY_RIGHT : 
					if (setting == FORGROUND)
						f = f == 0 ? COLORS - 1 : f + 1 ;
					else
						b = b == 0 ? COLORS - 1 : b + 1 ;
				break ;

				default:
					beep() ;
			} // switch
			init_pair(1, f, b) ;
		} //while
		refresh() ;
	} // setfb

	int modf(char setting)
	{
		beep() ;
		beep() ;
		beep() ;
		if (!can_change_color())
		{
			beep() ;
			return ;
		}
		fillwin() ;
		mvprintw(12,10,"Use KEY_LEFT, LEY_RIGHT") ;
		mvprintw(13,10,"'g'F1 to select") ;
		refresh() ;
		while (1)
		{
			switch(getch())
			{
				case 'h':
				case KEY_LEFT : 
					if (setting == COLOR_RED)
						R = R == 0 ? 1000 : R - 1 ;
					else if(setting == COLOR_GREEN)
						G = G == 0 ? 1000 : G - 1 ;
					else
						B = B == 0 ? 1000: B - 1 ;
				break ;

				case 'l':
				case KEY_RIGHT : 
					if (setting == COLOR_RED)
						R = R == 1000 ? 0 : R + 1 ;
					else if(setting == COLOR_GREEN)
						G = G == 1000 ? 0 : G + 1 ;
					else
						B = B == 1000 ? 0: B + 1 ;
				break ;

				case 'g' :
				case KEY_F(1) : return ;  break ;
				default:
					beep() ;
				} // switch
				refresh() ;
		} // while
	}		// modf() ends

void print_menu(WINDOW *menu_win, int highlight)
{
   int x, y, i;

   x = 2;
   y = 2;
   box(menu_win, 0, 0);
   for(i = 0; i < n_choices; ++i)
   {  if(highlight == i + 1) /* High light the present choice */
      {  wattron(menu_win, A_REVERSE);
         mvwprintw(menu_win, y, x, "%s", choices[i]);
         wattroff(menu_win, A_REVERSE);
      }
      else
         mvwprintw(menu_win, y, x, "%s", choices[i]);
      ++y;
   }
	refresh() ;
   wrefresh(menu_win);
} // print_menu

