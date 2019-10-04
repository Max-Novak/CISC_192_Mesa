//#define XOPEN_SOURCE_EXTENDED 1
#include <stdio.h>
#include <ncurses.h>
#include <limits.h>

int main() 
{

	int lines ;
	int cols  ;
	int x, y ;
//	printf("lines: %d  cols: %d\n", lines,cols) ;
//	getchar() ;

//	setlocale(LC_CTYPE, "en_US.UTF-8") ;
	initscr() ;
	getmaxyx(stdscr, y,x) ; 
	curs_set(0) ;
	printw("windows lines: %d cols: %d", LINES, COLS) ;
		for(x = 0 ; x < COLS ; x+= 3)
		{
			move(0,x) ;
			vline('|',LINES) ;
		} // for y 
		for(y = 0 ; y < COLS ; y+= 3)
		{
			move(y,0) ;
			hline('-',COLS) ;
		}
	curs_set(0) ;






	refresh() ;
	getch() ;
	endwin() ;
	return(0) ;
}







