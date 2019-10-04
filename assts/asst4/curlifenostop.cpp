/*------------------------------------------------------------
*	curlife_002.cpp - a curses-based version of Conway's "Life" game.
*	First version written 1983 by TEK in Applesoft BASIC.  Written
*	Nov, 1998 by TEK in GNU C and ncurses.  Modified to create
*	default startup file Dec 1999 by TEK.  Ported to gcc/Solaris
*	Dec, 2000 by TEK.  to compile under Linux: cc -o curlife
*	curlife.c -lncurses to compile at rohan.sdsu.edu (Solaris):
*	gcc -o curlife curlife.c -lcurses Note to the student: this
*	program seizes control of the system kill interrupt, so the
*	user can't arbitrarily kill the run.  To understand the reason
*	for this, read the die() function code, and enter "man signal"
*	at the Unix prompt.  Once you understand this, please use it
*	with compassion, and invisibly, as here.  Nobody likes a
*	control
*	freak. 
Let's try to incorporate up to 15 genders in the reproduction
algorithm, and if it works, use ANSI colors that show up on
a vt-100 terminal.  (For this, look at the domegame.cpp code.)
Sun Aug 18 13:09:34 PDT 2019
------------------------------------------------------------*/

#include <signal.h>
#include <curses.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#define STARTR 1
#define STARTC 0
#undef FAST 
char LIVE = '@' ;
char DEAD = '.' ;
unsigned int count ;
unsigned	int last_count = 0  ;
unsigned	int last_count_age ;
unsigned int max_stasus = 300 ;
int delay = 10000 ;  // num of milliseconds between screens
int ROWS, COLS ;
int ** screen, **workscreen ;
main(int argc, char *argv[], char **env)
{

	int iterations_nochange = 0 ;
	ROWS = atoi(getenv("LINES")) ;
	COLS = atoi(getenv("COLUMNS")) ;
	COLS -- ;
	printf("ROWS: %d  COLS: %d\n", ROWS, COLS) ;
	screen = new int* [ROWS+1];
	for (int i = 0 ; i < COLS ; ++i)
		screen[i] = new int[COLS] ;
		
	workscreen = new int*[ROWS+1];
	for (int i = 0 ; i < COLS ; ++i)
		workscreen[i] = new int[COLS] ;
		
	FILE * ifp ;
	void 	die(int); 
	int clear_work(void), show_screen(void), 
		IS_START_FILE = 0 ,
		work2screen(void),  i, j, c , generation = 0 ;
	char banner[41] ;
/* if the user wanted alternate characters for the LIVE and
	DEAD characters, here they go */
if (argc > 1)
{
	LIVE = argv[1][0] ;
	DEAD = argv[2][0] ;
}

/*-----------	
	trap Control-C interrupt, so checkpoint file written. 
-----------*/
	signal (SIGINT, die) ;
	signal (SIGKILL, die) ;
	if (NULL == (ifp = fopen("lifestart", "r") )) 
	{
		IS_START_FILE = 0 ;
		/*printf("Can't open %s\n", argv[1]) ;
		exit (-1) ; */
	} /* if NULL */
	else	
		IS_START_FILE = 1 ; 				
/*----------
	initialize curses.
----------*/
	initscr() ;
	if (!start_color()) 
	{
		addstr("Term doesn't support color!") ;
		inch() ;
	}
/*
	each gender will need their own COLOR_PAIR
*/
	init_pair(1, COLOR_GREEN, COLOR_BLACK) ;
	attron( COLOR_PAIR(1)) ;

/*----------
	if start file, read it, otherwise make one,
	and restart program.
----------*/
	if (IS_START_FILE)
	{
		for (i = 0 ; i < ROWS ; i++) 
		{	/* load starting screen */
			for (j = 0 ; (c = fgetc(ifp)) != EOF && j < COLS ; j++) 
				if(c != '\n' && c != '\r') 
				{
					screen[i][j] = c ;
					move(STARTR + i,STARTC + j) ; 
					addch( screen[i][j] ) ;
					/* refresh() ; */	/* slow screen load */
				}
		} /* for i */ 	
		refresh() ;		/* fast screen load */
	}
	else /* (NO_START_FILE) */
	{
		for (i = 0 ; i < ROWS ; i++) 
			for (j = 0 ; j < COLS ; j++) 
				screen[i][j] = DEAD ;
			/* create an R-Pentomino */
			screen[9][33] = screen[9][34] = screen[10][34] = \
			 screen[10][35] = screen[11][34] = LIVE ;
		if (NULL != (ifp = fopen("lifestart", "w") )) 
		{
			for (i = 0 ; i < ROWS ; i++) 
			{
				for (j = 0 ; j < COLS ; j++) 
					fputc(screen[i][j], ifp) ;
				fputc('\n', ifp) ;
			}
			fclose(ifp) ;
		} /* if NULL */
		signal (SIGINT, SIG_IGN) ;
		signal (SIGINT, SIG_IGN) ;
		mvcur(0, COLS -1, LINES - 1, 0 ) ;
		refresh() ;		/* fast screen load */
		endwin() ; 
		puts("Restart, if you see this, slow machine.") ;
		//execve(&argv[0], &argv[1], env) ;
		execve(argv[0], &argv[1], env) ;

//int execve(const char *filename, char *const argv[], char *const envp[]);


	} /* else */

/*----------
	Main loop logic.  This is the simplest method of
	programming this algorithm, so a beginner should
	grasp the logic in finite time.  It's certainly
	not the fastest way to do it.
	Also, when you have a large field, it's likely you'll encounter
	more than just a few periodics ("oscellators") so total lives may
	be periodic between two total values > 1.
	This needs a better general antiperiodicity algorythm.
----------*/
while(1) 	/* endless loop */
{
	int score = 0 ;
	clear_work() ;
	{
		iterations_nochange ++ ;
		// if enough, call random 
	}
/*----------
	do left upper corner
----------*/
	if (screen [ROWS-1] [COLS-1] == LIVE)	score++ ;
	if (screen [ROWS-1] [0     ] == LIVE)	score++ ;
	if (screen [ROWS-1] [1     ] == LIVE)	score++ ;
	if (screen [0     ] [COLS-1] == LIVE) 	score++ ;
	if (screen [0     ] [1     ] == LIVE) 	score++ ;
	if (screen [1     ] [COLS-1] == LIVE) 	score++ ;
	if (screen [1     ] [0     ] == LIVE) 	score++ ;
	if (screen [1     ] [1     ] == LIVE) 	score++ ;
	workscreen[i][j] = DEAD ;
	if(screen[0][0] == LIVE && (score == 2 || score == 3)) 
	{
		workscreen[0][0] = LIVE ;
	}
	if(screen[0][0] == DEAD && score == 3)
	{
		workscreen[0][0] = LIVE ;
	}

/*----------
	do middle of first row 
----------*/
	i = 0 ; 			
	for (j = 1 ; j < COLS - 1 ; j++) 
	{
		score = 0 ;
		if (screen [ROWS-1] [j-1   ] == LIVE)	score++ ;
		if (screen [ROWS-1] [j     ] == LIVE) 	score++ ;
		if (screen [ROWS-1] [j+1   ] == LIVE)	score++ ;
		if (screen [0     ] [j-1   ] == LIVE) 	score++ ;
		if (screen [0     ] [j+1   ] == LIVE) 	score++ ;
		if (screen [1     ] [j-1   ] == LIVE) 	score++ ;
		if (screen [1     ] [j     ] == LIVE) 	score++ ;
		if (screen[1][j+1] == LIVE) 	score++ ;
		workscreen[0][j] = DEAD ;
		if(screen[0][j] == LIVE && (score == 2 || score == 3))
		{
			workscreen[0][j] = LIVE ;
		}
		if(screen[0][j] == DEAD && score == 3)
		{
			workscreen[0][j] = LIVE ;
		}
	}

/*----------
	do right upper corner
----------*/
	score = 0 ; 		
	if (screen [ROWS-1] [COLS-2] == LIVE) 	score++ ;
	if (screen [ROWS-1] [COLS-1] == LIVE) 	score++ ;
	if (screen [ROWS-1] [0     ] == LIVE) 	score++ ;
	if (screen [0     ] [COLS-2] == LIVE) 	score++ ;
	if (screen [0     ] [0     ] == LIVE) 	score++ ;
	if (screen [1     ] [COLS-2] == LIVE) 	score++ ;
	if (screen [1     ] [COLS-1] == LIVE) 	score++ ;
	if (screen [1     ] [0     ] == LIVE) 	score++ ;
	workscreen[0][COLS-1] = DEAD ;
	if(screen[0][COLS-1] == LIVE && (score == 2 || score == 3))
	{
		workscreen[0][COLS-1] = LIVE ;
	}
	if(screen[0][COLS-1] == DEAD && score == 3)
	{
		workscreen[0][COLS-1] = LIVE ;
	}

/*----------
	do middle rows of screen
----------*/
	for ( i = 1 ; i < ROWS-1 ; i++)  
	{
		score = 0 ; 			/* do first cell */
		if (screen [i-1    ] [COLS-1] == LIVE)	score++ ;
		if (screen [i-1    ] [0     ] == LIVE) 	score++ ;
		if (screen [i-1    ] [1     ] == LIVE) 	score++ ;
		if (screen [i      ] [COLS-1] == LIVE) 	score++ ;
		if (screen [i      ] [1     ] == LIVE) 	score++ ;
		if (screen [i+1    ] [COLS-1] == LIVE)	score++ ;
		if (screen [i+1    ] [0     ] == LIVE) 	score++ ;
		if (screen [i+1    ] [1     ] == LIVE) 	score++ ;
		workscreen[i][0] = DEAD ;
		if(screen[i][0] == LIVE && (score == 2 || score == 3))
		{
			workscreen[i][0] = LIVE ;
		}
		if(screen[i][0] == DEAD && score == 3)
		{
			workscreen[i][0] = LIVE ;
		}
			

		for (j = 1 ; j < COLS-1  ; j++) /* do middle of line */ 
		{
			score = 0 ;
			if (screen [i-1   ] [j-1   ] == LIVE)	score++ ;
			if (screen [i-1   ] [j     ] == LIVE) 	score++ ;
			if (screen [i-1   ] [j+1   ] == LIVE) 	score++ ;
			if (screen [i     ] [j-1   ] == LIVE) 	score++ ;
			if (screen [i     ] [j+1   ] == LIVE) 	score++ ;
			if (screen [i+1   ] [j-1   ] == LIVE) 	score++ ;
			if (screen [i+1   ] [j     ] == LIVE) 	score++ ;
			if (screen [i+1   ] [j+1   ] == LIVE) 	score++ ;
			workscreen[i][j] = DEAD ;
			if(screen[i][j] == LIVE && (score == 2 || score == 3))
			{
				workscreen[i][j] = LIVE ;
			}
			if(screen[i][j] == DEAD && score == 3)
			{
				workscreen[i][j] = LIVE ;
			}

		} /* middle of lines */

		score = 0 ; 		/* do last cell on middle line */
		if (screen [i-1   ] [COLS-2] == LIVE)	score++ ;
		if (screen [i-1   ] [COLS-1] == LIVE)	score++ ;
		if (screen [i-1   ] [0     ] == LIVE)	score++ ;
		if (screen [i     ] [COLS-2] == LIVE) 	score++ ;
		if (screen [i     ] [0     ] == LIVE) 	score++ ;
		if (screen [i+1   ] [COLS-2] == LIVE)	score++ ;
		if (screen [i+1   ] [COLS-1] == LIVE)	score++ ;
		if (screen [i+1   ] [0     ] == LIVE) 	score++ ;
		workscreen[i][COLS-1] = DEAD ;
		if(screen[i][COLS-1] == LIVE && (score == 2 || score == 3))
		{
			workscreen[i][COLS-1] = LIVE ;
		}

		if(screen[i][COLS-1] == DEAD && score == 3)
		{
			workscreen[i][COLS-1] = LIVE ;
		}
	} /* main part of screen */

/*----------
	do last row of screen 
----------*/

	score = 0 ; 				/* do left lower corner */
	if (screen [ROWS-2] [COLS-1] == LIVE)	score++ ;
	if (screen [ROWS-2] [0     ] == LIVE)	score++ ;
	if (screen [ROWS-2] [1     ] == LIVE) 	score++ ;
	if (screen [ROWS-1] [COLS-1] == LIVE) 	score++ ;
	if (screen [ROWS-1] [1     ] == LIVE) 	score++ ;
	if (screen [0     ] [COLS-1] == LIVE) 	score++ ;
	if (screen [0     ] [0     ] == LIVE) 	score++ ;
	if (screen [0     ] [1     ] == LIVE) 	score++ ;
	workscreen[ROWS-1][0] = DEAD ;
	if(screen[ROWS-1][0] == LIVE && (score == 2 || score == 3))
	{
		workscreen[ROWS-1][0] = LIVE ;
	}
	if(screen[ROWS-1][0] == DEAD && score == 3)
	{
		workscreen[ROWS-1][0] = LIVE ;
	}

	for (j = 1 ; j < COLS - 1 ; j++) 	/* do middle of last line */ 
	{
		score = 0 ;
		if (screen [ROWS-2] [j-1   ] == LIVE)	score++ ;
		if (screen [ROWS-2] [j     ] == LIVE) 	score++ ;
		if (screen [ROWS-2] [j+1   ] == LIVE)	score++ ;
		if (screen [ROWS-1] [j-1   ] == LIVE)	score++ ;
		if (screen [ROWS-1] [j+1   ] == LIVE)	score++ ;
		if (screen [0     ] [j-1   ] == LIVE) 	score++ ;
		if (screen [0     ] [j     ] == LIVE) 	score++ ;
		if (screen [0     ] [j+1   ] == LIVE) 	score++ ;
		workscreen[ROWS-1][j] = DEAD ;
		if(screen[ROWS-1][j] == LIVE && (score == 2 || score == 3))
		{
			workscreen[ROWS-1][j] = LIVE ;
		}
		if(screen[ROWS-1][j] == DEAD && score == 3)
		{
			workscreen[ROWS-1][j] = LIVE ;
		}
	}
	score = 0 ; 		/* do right lower corner */
	if (screen [ROWS-2] [COLS-2] == LIVE)	score++ ;
	if (screen [ROWS-2] [COLS-1] == LIVE) 	score++ ;
	if (screen [ROWS-2] [0     ] == LIVE)	score++ ;
	if (screen [ROWS-1] [COLS-2] == LIVE) 	score++ ;
	if (screen [ROWS-1] [0     ] == LIVE) 	score++ ;
	if (screen [0     ] [COLS-2] == LIVE) 	score++ ;
	if (screen [0     ] [COLS-1] == LIVE) 	score++ ;
	if (screen [0     ] [0     ] == LIVE) 	score++ ;
	workscreen[ROWS-1][COLS-1] = DEAD ;
// look for static display
	if(screen[ROWS-1][COLS-1] == LIVE && (score == 2 || score == 3))
	{
		workscreen[ROWS-1][COLS-1] = LIVE ;
	}

	if(screen[ROWS-1][COLS-1] == DEAD && score == 3)
	{
		workscreen[ROWS-1][COLS-1] = LIVE ;
	}
/*----------
	display result of generation
----------*/
	work2screen() ;
	show_screen() ;

/*----------
	update stats
----------*/
	/*--------------------------------------------------*/
	move(ROWS + 1 ,5) ;
	sprintf(banner,"              " ) ; 
	addstr(banner) ;
	usleep(delay) ;
	refresh() ; 
	move(ROWS + 1 ,5) ;
	sprintf(banner,"%u ::: %u", generation++, count) ;
	FILE * numseries = fopen ("liferec.txt","a") ;
	if (numseries)
	{
		fprintf(numseries, "%s\n", banner) ;
		fclose(numseries) ;
	}
	addstr(banner) ;
	refresh() ; 
	/*--------------------------------------------------*/
} ; /* endless while */
} /* main ends */

/*--------------------------------------------------
	we've trapped the kill signals, so we can't be stopped
	without writing a checkpoint file.
	When user presses ^C or ^\, this code takes control:
--------------------------------------------------*/
void die(int retval) 	/*terminate & write a checkpoint file */
{
	int i , j, c ;
	FILE *ifp ;
	if (NULL != (ifp = fopen("lifescratch", "w") )) 
	{
		for (i = 0 ; i < ROWS ; i++) 
		{
			for (j = 0 ; j < COLS ; j++) 
				fputc(screen[i][j], ifp) ;
			fputc('\n', ifp) ;
		}
		fclose(ifp) ;
	} /* if NULL */
	signal (SIGINT, SIG_IGN) ;
	mvcur(0, COLS -1, LINES - 1, 0 ) ;
	endwin() ; 
	exit(0) ;
} /* die() */

int work2screen() 
{
	int i, j ;
	for (i = 0 ; i < ROWS  ; i++)
		for (j = 0 ; j < COLS  ; j++)
			screen[i][j] = workscreen[i][j] ;
} /* work2screen() */

int show_screen() 
{ int i, j ;
	extern unsigned int  count ;
	count = 0 ;
	for (i = 0 ; i < ROWS  ; i++)
	{
		for (j = 0 ; j < COLS ; j++)
		{
			move(STARTR + i,STARTC + j) ; 
			addch( screen[i][j] ) ;
			if (screen[i][j] == LIVE) 
				count++ ;
		} // for j
	}
			//count is done
	if (count == last_count || count +1 == last_count || count - 1 == last_count)  // what, no change?
	{
		last_count_age++ ;
		if (last_count_age >= max_stasus)
		{
			count = 0 ;
	//		last_count = 0 ;
			last_count_age = 0 ;
			for (int col = 0 ; col < COLS; col ++ )
			{
/*-------------------------------------------------------
	here is one of the universal constants which does exhibit a marked effect on the world:
	when the mod value for rand() is 2, the universe tends to jump backward into Planck Time
	capriciously.  Bad for life evolution.  When the value is 8, the universe tends to hang
	in an entropic death characterized by oscillators with large periodicities.  When 
	the value is 4, the universe tends to accept a "local, temporary" GUT freeze, which kicks off a
	large emission of proto-matter, but doesn't remake the universe and restart time.
---------------------------------------------------------------------------------------*/
				for (int row = 0 ; row < LINES ; ++row) 
				{
					if ( (screen[row][col] == DEAD) && (rand() % 4))  // TEH experimental)
					{
						screen[row][col] = LIVE ;  
					}
					else
					{	
						screen[row][col] = DEAD ; 
					} 
				} // for row
		} // for col
		} // if(last_count_age > max_status)
	} // if count == last_count
	else
	{
		last_count = count ;
	}
			refresh() ; 
} /* show_screen() */

int clear_work() {
	int i, j ;
	for (i = 0 ; i < ROWS  ; i++)
		for (j = 0 ; j < COLS ; j++)
			workscreen[i][j] = DEAD;
} /* clear_work() */
