/*-----------------------------------------------------------------
*	acslist.c - gookin p138
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
	for (a = 0 ; a < 127; a++ )
	{	
		printw("\t%2X:", a) ;
		addch(A_ALTCHARSET | a) ;
	}
	refresh() ;
	getch() ; 
	endwin() ;
	return(0) ;
} // main ends
