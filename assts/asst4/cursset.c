/*-----------------------------------------------------------------
*	curset.c - gookin p138
Fri Apr  6 12:33:03 PDT 2018
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

int main ()
{
	int y, x, maxy, maxx ;
	initscr() ;
/* first, turn the cursor off */
	curs_set(0) ;
	addstr(" <- The cursor has been turned off") ;
	move(0,0) ;
	refresh() ;
	getch() ;
	
	/* second, turn the cursor on */
	curs_set(1) ;
	addstr("\n <- The cursor now on") ;
	move(1,0) ;
	refresh() ;
	getch() ;

	/* third, turn the cursor very on */
	curs_set(2) ;
	addstr("\n <- The cursor is now very on") ;
	move(2,0) ;
	refresh() ;
	getch() ;

	endwin() ;
	return(0) ;
} // main ends
