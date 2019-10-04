/*-----------------------------------------------------------------
*	linechars.c - gookin p138
explore different graphic chars
Fri Apr  6 12:33:03 PDT 2018
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

int main ()
{
	int y, x, lchar, maxy, maxx ;
	initscr() ;
	getmaxyx(stdscr,maxy, maxx) ;
	lchar = 33 ;
	for (y = x = 0 ; y < maxy; y++ , x+=2)
	{	
		move(y,x) ;
		hline(lchar,maxx-x) ;
		vline(lchar,maxy-y) ;
		lchar++ ;
	}
	refresh() ;
	getchar() ; 
	endwin() ;
	return(0) ;
} // main ends
