/*--------------------------------------------------------------------
*	bounce.c	-	a gibberish generator.
*	Exercise: copy, compile, and run this code.

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
	/*----------------------------------------------------------------
	*	You can modify d[] to alter the frequency of the letters, and
	*	thereby gerrymander your gibberish.
	*	Spaces appear here because we don't want the screen to just
	*	seethe like a garbage bucket in summer, we want to see real
	*	movement!
	----------------------------------------------------------------*/
	char d[] =   {  "                     @@@@@@" } ;
	size_t size;
	int LINES, cols, row, col ;
	char ch;

	LINES = atoi(getenv("LINES")) ;
	cols = atoi(getenv("COLUMNS")) ;
	if (LINES < 25) LINES = 24 ;
	if (cols < 25) cols = 80 ;
//	LINES-- ; cols-- ;	
//	cols=80 ;
	size = sizeof(d) ;			/* keep track of source array	*/
	srand(time(0));	/* initialize rand() 		*/
	(void) system("clear") ;		/* clear terminal screen      */
	(void) initscr() ;			/* start curses               */
	while (1)
	{
		//move(rand() % LINES,rand() % cols) ; /* move somewhere      */
		row = rand() % LINES ;  
		col = rand() % cols ; /* move somewhere      */
		ch = d[rand() % (size - 1) ];	/* select random letter  */
		move(row, col) ; /* move somewhere      */

		addch(ch) ;			/* print it                   */
		refresh() ;			/* display result             */
		usleep(950) ;		/* pause....                  */
		move(row, col) ; /* move somewhere      */
		//addch(' ') ;
		refresh() ;
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
