/*-----------------------------------------------------------------
*	colortest.c - gookin p138
explore different graphic chars
Fri Apr  6 12:33:03 PDT 2018
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

int main ()
{
	int a ;
	initscr() ;
	start_color() ;
	printw("Colors initialized\n") ;
	printw("%d colors available\n", COLORS) ;
	printw("%d color pairs,",COLOR_PAIRS) ;
	refresh() ;
	getch() ;


	refresh() ;
	getch() ; 
	endwin() ;
	return(0) ;
} // main ends
