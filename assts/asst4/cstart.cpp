/*--------------------------------------------------------------------
*	cstart.cpp	-	starter framework for curses exerciese
*	a gibberish generator.
*	First lab exercise: copy, compile, and run this code,
*	fixing errors as they occur.  Get familiar with cc.
*	to compile: cc -o wordrain wordrain.c -lncurses
*	After running the program, can you guess how it works?
	EXPORT LINES AND COLUMNS!! OR SEGFAULT.
--------------------------------------------------------------------*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <time.h>
int die(void) ;
#undef MESA 1
int LINES, COLUMNS ;
int main(void)
{
	unsigned int reps = 49990 ;
	/*----------------------------------------------------------------
	*	You can modify d[] to alter the frequency of the letters, and
	*	thereby gerrymander your	gibberish.
	----------------------------------------------------------------*/
	char d[] =   {  "           eeeeee ttttt ooooo iiiii nn"
	                "           sss hhh rrr dd ll uu abc"
	                "           def ghi jkl mno pqr stu vwx yz"
	             } ;
	size_t size;
	char ch;

	size = sizeof(d) ;			/* keep track of source array	*/
	srand(time((unsigned int) NULL));	/* initialize rand() 		*/
	(void) system("clear") ;		/* clear terminal screen      */
	(void) initscr() ;			/* start curses               */
	LINES=atoi(getenv("LINES")) ;
	COLUMNS=atoi(getenv("COLUMNS")) ;
	while (1)
	{
		move(rand() % LINES,rand() % COLUMNS) ; /* move somewhere      */
		ch = d[rand() % (size - 1) ];	/* select random letter  */
		addch(ch) ;			/* print it                   */
#ifdef MESA
		if ((reps % 10) == 0)
#endif
		{
			refresh() ;			/* display result             */
#ifdef MESA
			sleep(1,'s') ;			/* pause....                  */
#else
			usleep(25) ;		/* pause....                  */
#endif
		}
		/*sleep(.75,'s') ; */		/* pause....                  */
	} /* while */
	die() ;						/* shut down curses           */
} /* main() ends */

int die(void )
{
	signal (SIGINT, SIG_IGN) ;
	mvcur(0, COLS -1, LINES - 1, 0 ) ;
	endwin() ;
	exit(0) ;
} /* die() ends */
