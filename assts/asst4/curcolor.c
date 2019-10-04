/*
 * Curses color support demo
 */

#include <ncurses.h>

int f, b, R, G, B ;

int setfb(char );
#define FOREGROUND 1
#define BACKGROUND 0

int main (int argc, char *argv[])
{
  initscr() ;
  keypad(stdscr, TRUE) ;
  cbreak() ;
  noecho() ;
  scrollok(stdscr, TRUE) ;
//  if (!has_colors()) { endwin() ; fprintf(stderr,"\ncolor not supported\n") ; exit(1) ; }
  start_color() ;
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_YELLOW);
  attron(COLOR_PAIR(2)) ;
  process() ;
  endwin() ;
  return(0) ;
} // End main()

fillwin()
{
  register int y, x ;

  move(0,0) ;
  for (y = 0 ; y < LINES; y++)
    for (x = 0 ; x < COLS ; x++)
      addch(' ') ;
} // End fillwin() 

process()
{
  while(1) {
    fillwin() ;
    mvprintw(10,15,"Function keys are:") ;
    mvprintw(12,15,"F1 = Set Foreground") ;
    mvprintw(13,15,"F2 = Set Background") ;
    mvprintw(14,15,"F3 = Modify RED Content") ;
    mvprintw(15,15,"F4 = Modify GREEN Content") ;
    mvprintw(16,15,"F5 = Modify BLUE Content") ;
    mvprintw(18,15,"F8 = Quit Program") ;
	 refresh() ;
	 switch(getch()) {
	 		case KEY_F(1):
				setfb(FOREGROUND);
				break ;
	 		case KEY_F(2):
				setfb(BACKGROUND);
				break ;
	 		case KEY_F(3):
				//modf(COLOR_RED);
				setfb(COLOR_RED);
				break ;
	 		case KEY_F(4):
				//modf(COLOR_GREEN);
				setfb(COLOR_GREEN);
				break ;
	 		case KEY_F(5):
				//modf(COLOR_BLUE);
				setfb(COLOR_BLUE);
				break ;
	 		case KEY_F(8):
				return ;
				break ;
			default:
				beep() ;
		} // End switch() 
	} // End while
} // End process

/*
 * set foreground
 */

setfb(char setting)
{
	fillwin() ;
	mvprintw(12,10,"setfb()Use KEY_LEFT, KEY_RIGHT") ;
	mvprintw(13,10,"F1 to select") ;
	refresh() ;
	while(1) {
		switch(getch()) {
			case KEY_LEFT:
				if(setting == FOREGROUND)
					f = f == 0 ? COLORS -1 : f-1 ;
				else
					b = b == 0 ? COLORS -1 : b-1 ;
			break ;
			case KEY_RIGHT:
				if(setting == FOREGROUND)
					f = f == 0 ? COLORS -1 : f+1 ;
				else
					b = b == 0 ? COLORS -1 : b+1 ;
			break ;
			case KEY_F(1):
				return ;
			default:
				beep() ;
		} // End switch
		init_pair(1,f,b) ;
	} // End while() 
} // End setfb() 
	
modf(int setting) {
	if (!can_change_color()) {
		beep() ;
		return ;
	}

	fillwin() ;
	mvprintw(12,10,"modf() Use KEY_LEFT, KEY_RIGHT") ;
	mvprintw(13,10,"F1 to select") ;
	refresh() ;
	while(1) {
		switch(getch()) {
			case KEY_LEFT:
				if(setting == COLOR_RED)
					R = R == 0 ? 1000 : R - 1 ;
				else
					G = G == 0 ? 1000 : G - 1 ;
			break ;
			case KEY_RIGHT:
				if(setting == COLOR_RED)
					R = R == 0 ? 1000 : R + 1 ;
				else if (setting == COLOR_GREEN)
					G = G == 0 ? 1000 : G + 1 ;
				else
					B = B == 0 ? 1000 : B + 1 ;
			break ;
			case KEY_F(1):
				return ;
			break ;
			default:
				beep() ;
			break ;
		} // End switch
		init_color(f,R,G,B) ;
	} // End while
} // end modf()

	
