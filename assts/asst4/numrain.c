/*--------------------------------------------------------------------
*	numrain.c	-	a wallpaper generator.
*	Exercise: copy, compile, and run this code.

IMPORTANT:
*	to compile: cc -o wordrain wordrain.c -lncurses

*	After running the program, can you guess how it works?
* Built from wordrain Wed May 16 21:31:36 PDT 2018
*	Theoni Elizabeth Harrisburg, M.S.
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
	char d[] =   {  "     11               1111 66666 11               111 55               555 00"
				 "     555 444 444             00 88 77 789" 
				 "     012 345 678 901 234             567 890 12" } ;
	size_t size;
	int LINES, cols ;
	char ch;

	srand(time( NULL));	/* initialize rand() 		*/
	(void) system("clear") ;		/* clear terminal screen      */
	(void) initscr() ;			/* start curses               */
	while (1)
	{
	LINES = atoi(getenv("LINES")) ;
	cols = atoi(getenv("COLUMNS")) ;
	if (LINES < 25) LINES = 24 ;
	if (cols < 25) cols = 80 ;
//	LINES-- ; cols-- ;	
//	cols=80 ;
	size = sizeof(d) ;			/* keep track of source array	*/
		move(rand() % LINES,rand() % cols) ; /* move somewhere      */
		ch = d[rand() % (size - 1) ];	/* select random letter  */
		addch(ch) ;			/* print it                   */
		{
			refresh() ;			/* display result             */
			usleep(1800) ;		/* pause....                  */
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
