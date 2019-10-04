/*------------------------------------------------------------
*	curhg.c		-	curses-based hourglass timer, 
*		reminiscent of the one Chief Guardian Turbo had 
*		in the "Trust No One" episode of Reboot.
* Written 6/6/00, TEK.
* compile: gcc -o crhg crhg.c -lcurses
NOTE: This must be run on your system console, the school
LAN can't keep up with Curses and will drop chars, munge
colors, and generaly barflesnerg().
Note: Tue Feb 25 18:44:20 PST 2003
It's not the LAN, it's EWAN, Putty runs it fine.  EWAN
keeps dropping characters.
------------------------------------------------------------*/
#include <signal.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define SLEEPVAL 1
int main(int argc, char *argv[], char **env)
{
	void die(int) ;
	int y1, x1, y2, x2,  i, j , c ;
	const int topy = 1 , topx = 21 ;

	/*---------------------------
	*	start Curses.
	---------------------------*/
	initscr() ;
	/*-------------------
	*	frame
	-------------------*/
	for (x1 = 19, y1 = 0; x1 < 46 ; x1++)
	{
		move(y1, x1) ;
		addch('_') ;
		move(24, x1) ;
		addch('_') ;
		refresh() ;
	}
	for (x1 = 19, y1 = topy ; y1 < 24 ; y1++, x1 = x1 == 19 ? 44 : 19 )
	{
		move(y1, 19) ;
		addch('|') ;
		move(y1, 45) ;
		addch('|') ;
		refresh() ;
	}
	/*-------------------
	*	top half
	-------------------*/
	for (x1 = topx, c = 23 , y1 = topy  ; y1 < 15 ; y1++ , x1++, c -=2)
	{
		move(y1,x1) ; 
		for (j = 0 ; j < c ; j++)
		{
			addch('=') ;
			refresh() ;
		}
	}
	sleep(SLEEPVAL) ;
	/*-------------------
	*	bottom half
	-------------------*/
	for (x1 = topx, y1 = topy, c = 23, y2 = 23, x2 = topx ; 
		y2 > 11 ;
		y1++, x1++, y2--, x2++, c-= 2)
	{
		/*---------
		*	make top line blink
		----------*/
		move(y1,x1) ; 
		wattron(stdscr,A_BLINK ) ; 
		for (j = 0 ; j < c ; j++)
		{
			addch('=') ;
		refresh() ;
		}
		sleep(SLEEPVAL) ;
		/*----------
		*	plot new line on bottom, blinking
		----------*/
		move (y2,x2) ;
		wattron(stdscr,A_BLINK) ; 
		for(j = 0 ; j < c ; j++)
			addch('=') ;
		refresh() ;
		/*-------------
		*	erase old top line
		--------------*/
		move(y1,x1) ; 
		wattrset(stdscr,A_NORMAL ) ; 
		for (j = 0 ; j < c ; j++)
			addch(' ') ;
		refresh() ;
		sleep(SLEEPVAL) ;
		/*-------------
		*	make bottom line stop blinking
		--------------*/
		move (y2,x2) ;
		wattrset(stdscr,A_NORMAL ) ; 
		for(j = 0 ; j < c ; j++)
			addch('=') ;
		refresh() ;
	}
	die(0) ;
} /* main ends */

void die(int arg)
{
	signal (SIGINT, SIG_IGN) ;
	mvcur(0, COLS -1, LINES - 1, 0 ) ;
	endwin() ;
	exit(arg) ;
}
