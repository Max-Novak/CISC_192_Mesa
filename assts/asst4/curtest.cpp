/*-----------------------------------------------------------------
*	curtest.cpp	-	demo curses 
Sun Mar 22 11:03:23 PDT 2009
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <ncurses.h>
#include <iostream>
#include <iomanip>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
	initscr() ;
	standout() ;
	mvaddstr(0,8,"this is using standout") ;
	standend() ;
	attrset(A_STANDOUT) ;
	mvaddstr(2,8, "this is STANDOUT mode") ;
	attroff(A_STANDOUT) ;
	attron(A_REVERSE) ;
	mvaddstr(4,8, "this is REVERSE mode") ;
	attroff(A_REVERSE) ;
	attron(A_BOLD) ;
	mvaddstr(6,8, "this is BOLD mode") ;
	attroff(A_BOLD) ;
	attron(A_UNDERLINE) ;
	mvaddstr(8,8, "this is UNDERLINE mode") ;
	attroff(A_UNDERLINE) ;
	attron(A_DIM) ;
	mvaddstr(10,8, "this is DIM mode") ;
	attroff(A_DIM) ;
	attron(A_BLINK) ;
	mvaddstr(12,8, "this is BLINK mode") ;
	attroff(A_BLINK) ;
	attron(A_BOLD | A_UNDERLINE | A_BLINK) ;
	mvaddstr(14,8, "this is BOLD | UNDERLINE | BLINK mode") ;
	attrset(A_NORMAL) ;
	mvaddstr(16,8, "this is INVISIBLE[ ") ;
	attron(A_INVIS) ;
	addstr("this text is invisible" ) ;
	attroff(A_INVIS) ;
	addch(']') ;
	attron(A_REVERSE|A_BLINK) ;
	mvaddstr(18,8, "this is REVERSE | BLINK mode") ;
	attrset(A_NORMAL) ;
	mvaddstr(20,8, "this is NORMAL mode") ;
	attroff(A_NORMAL) ;

	refresh() ;
	getchar() ;
	endwin() ;
}
