/*--------------------------------------------------------------------
* bounce.c - a screen exerciser * Exercise: copy, compile,
and run this code.

IMPORTANT:
*	to compile: cc -o wordrain wordrain.c -lncurses

*	After running the program, can you guess how it works?
--------------------------------------------------------------------*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>	/* srand() */
#include <unistd.h>	/* sleep() */
#include <time.h>	/* time() used by srand() */
#include <curses.h>
int die(void) ;
int main(void)
{
	size_t size;
	int LENGTH, LINES, COLS, y, x, deltay, deltax, lastx, lasty ;
	char ch, deltaH, deltaV;

	COLS = atoi(getenv("COLUMNS")) ;
	LINES = atoi(getenv("LINES")) ;
	int stackx[LENGTH] ;	
	int stacky[LENGTH] ;	
	LINES = atoi(getenv("LINES")) ;
//	if (LINES < 25) LINES = 24 ;
//	if (cols < 25) cols = 80 ;
	srand(time((unsigned int) NULL));	/* initialize rand() 		*/
	(void) system("clear") ;		/* clear terminal screen      */
	(void) initscr() ;			/* start curses               */
	y = x = 0 ;
	deltay = deltax = 5 ;
	while (1)
	{
		lastx = x ;
		lasty = y ;
		x += deltaH ;
		y += deltaV ;
		if (x > COLS || x < 0 ) deltaH *= -1 ;
		if (y > LINES || y < 0) deltaV *= -1 ;
		move(y,x) ;putchar('@') ; 
		addch('@') ;
		lasty = y ;
		y = y + deltay ; 
		if (y >= LINES || y < 0)
		{
			deltay = deltay * -1 ;
			y = y + deltay ;
		}
		lastx = x ;
		x = x + deltax ; 
		if (x >= COLS || x < 0)
		{
			deltax = deltax * -1 ;
			x = x + deltax ;
		}
		
		move(lasty, lastx) ;
		addch(' ') ;
		refresh() ;
		move(y,x) ; /* move somewhere      */
		addch('@') ;			/* print it                   */
		{
			refresh() ;			/* display result             */
			usleep(3000) ;		/* pause....                  */
		//	sleep(.25) ;		/* pause....                  */
			move(y,x) ;
			//addch(' ') ;
			refresh() ;
		//	sleep(2) ;		/* pause....                  */
		}
		/*sleep() ; */		/* pause....                  */
	} /* while */
	die() ;						/* shut down curses           */
} /* main() ends */
	
int die(void )
{
		signal (SIGINT, SIG_IGN) ;
//		mvcur(0, COLS -1, LINES - 1, 0 ) ;
		endwin() ;
		exit(0) ;
} /* die() ends */
