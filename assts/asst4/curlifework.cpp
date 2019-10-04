/*------------------------------------------------------------
*	curlife.c - a curses-based version of Conway's "Life" game.
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
*	control freak. 
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
int ROWS, COLS ;
int ** board, **workboard ;
main(int argc, char *argv[], char **env)
{
	ROWS = atoi(getenv("LINES")) ;
	COLS = atoi(getenv("COLUMNS")) ;
	COLS -- ;
	printf("ROWS: %d  COLS: %d\n", ROWS, COLS) ;
	board = new int* [ROWS+1];
	for (int i = 0 ; i < COLS ; ++i)
		board[i] = new int[COLS] ;
		
	workboard = new int*[ROWS+1];
	for (int i = 0 ; i < COLS ; ++i)
		workboard(i] = new int[COLS] ;
		
	FILE * ifp ;
	void 	die(int); 
	int clear_work(void), show_board(void), 
		IS_START_FILE = 0 ,
		work2board(void),  i, j, c , generation = 0 ;
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

	init_pair(1, COLOR_GREEN, COLOR_BLACK) ;
	attron( COLOR_PAIR(1)) ;

/*----------
	if start file, read it, otherwise make one,
	and restart program.
----------*/
	if (IS_START_FILE)
	{
		for (i = 0 ; i < ROWS ; i++) 
		{	/* load starting board */
			for (j = 0 ; (c = fgetc(ifp)) != EOF && j < COLS ; j++) 
				if(c != '\n' && c != '\r') 
				{
					board[i][j] = c ;
					move(STARTR + i,STARTC + j) ; 
					addch( board[i][j] ) ;
					/* refresh() ; */	/* slow board load */
				}
		} /* for i */ 	
		refresh() ;		/* fast board load */
	}
	else /* (NO_START_FILE) */
	{
		for (i = 0 ; i < ROWS ; i++) 
			for (j = 0 ; j < COLS ; j++) 
				board[i][j] = DEAD ;
			/* create an R-Pentomino */
			board[9][33] = board[9][34] = board[10][34] = \
			 board[10][35] = board[11][34] = LIVE ;
		if (NULL != (ifp = fopen("lifestart", "w") )) 
		{
			for (i = 0 ; i < ROWS ; i++) 
			{
				for (j = 0 ; j < COLS ; j++) 
					fputc(board[i][j], ifp) ;
				fputc('\n', ifp) ;
			}
			fclose(ifp) ;
		} /* if NULL */
		signal (SIGINT, SIG_IGN) ;
		signal (SIGINT, SIG_IGN) ;
		mvcur(0, COLS -1, LINES - 1, 0 ) ;
		refresh() ;		/* fast board load */
		endwin() ; 
		puts("Restarting, and if you see this, you've got a slow machine.") ;
		//execve(&argv[0], &argv[1], env) ;
		execve(argv[0], &argv[1], env) ;

//		int execve(const char *filename, char *const argv[], char *const envp[]);


	} /* else */

/*----------
	Main loop logic.  This is the simplest method of
	programming this algorithm, so a beginner should
	grasp the logic in finite time.  It's certainly
	not the fastest way to do it.
----------*/


//======================================================

color DEAD = color.black
color LIVE = color.gray

//' OUTER SCREEN ITERATION LOOP
//'while(true) 
	score = 0 
	for i = 0 to ROWS
		for j = 0 to COLS
			workboard(i, j).live = false 
			workboard(i.j).backcolor = DEAD
		next j
	next i

/*----------
	do left upper corner
----------*/
	if (board (ROWS-1 ,COLS-1).live = true)	 then score = score + 1
	if (board (ROWS-1 ,0     ).live = true)	 then score = score + 1
	if (board (ROWS-1 ,1     ).live = true)	 then score = score + 1
	if (board (0      ,COLS-1).live = true) 	 then score = score + 1
	if (board (0      ,1     ).live = true) 	 then score = score + 1
	if (board (1      ,COLS-1).live = true) 	 then score = score + 1
	if (board (1      ,0     ).live = true) 	 then score = score + 1
	if (board (1      ,1     ).live = true) 	 then score = score + 1
	workboard(i,j).live = false
	if(board(0,0).live = true and (score = 2 or score = 3))
		workboard(0,0).live = true 
	if(board(0,0).live = false AND score = 3)
		workboard(0,0).live = true 

	//'do middle of first row 
	i = 0  			
	for j = 1 to COLS -1
		score = 0 
		if (board(ROWS-1, j-1   ).live = true)	 then score = score + 1
		if (board(ROWS-1, j     ).live = true) 	 then score = score + 1
		if (board(ROWS-1, j+1   ).live = true)	 then score = score + 1
		if (board(0     , j-1   ).live = true) 	 then score = score + 1
		if (board(0     , j+1   ).live = true) 	 then score = score + 1
		if (board(1     , j-1   ).live = true) 	 then score = score + 1
		if (board(1     , j     ).live = true) 	 then score = score + 1
		if (board(1,j+1).live = true) 	 then score = score + 1
		workboard(0,j).live=false
		if(board(0,j).live = true AND (score = 2 OR score = 3))
			workboard(0,j).live = true 
		if(board(0,j).live = false AND score = 3)
			workboard(0,j).live = true 
	next j

	//'do right upper corner
	score = 0  		
	if (board(ROWS-1, COLS-2).live = true) 	 then score = score + 1
	if (board(ROWS-1, COLS-1).live = true) 	 then score = score + 1
	if (board(ROWS-1, 0     ).live = true) 	 then score = score + 1
	if (board(0     , COLS-2).live = true) 	 then score = score + 1
	if (board(0     , 0     ).live = true) 	 then score = score + 1
	if (board(1     , COLS-2).live = true) 	 then score = score + 1
	if (board(1     , COLS-1).live = true) 	 then score = score + 1
	if (board(1     , 0     ).live = true) 	 then score = score + 1
	workboard(0,COLS-1).live = false
	if(board(0,COLS-1).live = true AND (score = 2 OR score = 3))
		workboard(0,COLS-1) = .live = true 
	if(board(0,COLS-1)live = false AND score = 3)
		workboard(0,COLS-1).live = true 

	//do middle rows of board
	for i = 1 to ROWS -1
	//' first cell
		score = 0  
		if (board(i-1    , COLS-1).live = true)	 then score = score + 1
		if (board(i-1    , 0     ).live = true) 	 then score = score + 1
		if (board(i-1    , 1     ).live = true) 	 then score = score + 1
		if (board(i      , COLS-1).live = true) 	 then score = score + 1
		if (board(i      , 1     ).live = true) 	 then score = score + 1
		if (board(i+1    , COLS-1).live = true)	 then score = score + 1
		if (board(i+1    , 0     ).live = true) 	 then score = score + 1
		if (board(i+1    , 1     ).live = true) 	 then score = score + 1
		workboard(i,0).live = false
		if(board(i,0).live = true AND (score = 2 OR score = 3))
			workboard(i,0).live = true 
		if(board(i,0).live = false AND score = 3)
			workboard(i,0).live = true 

	//'main screen rows
	for j = 1 to COLS -1
			score = 0 
			if (board(i-1   , j-1   ).live = true)	 then score = score + 1
			if (board(i-1   , j     ).live = true) 	 then score = score + 1
			if (board(i-1   , j+1   ).live = true) 	 then score = score + 1
			if (board(i     , j-1   ).live = true) 	 then score = score + 1
			if (board(i     , j+1   ).live = true) 	 then score = score + 1
			if (board(i+1   , j-1   ).live = true) 	 then score = score + 1
			if (board(i+1   , j     ).live = true) 	 then score = score + 1
			if (board(i+1   , j+1   ).live = true) 	 then score = score + 1
			workboard(i,j).live = false 
			if(board(i,j).live = true AND (score = 2 OR score = 3))
				workboard(i,j).live = true 
			if(board(i,j).live = false AND score = 3)
				workboard(i,j).live = true 
	next j

		score = 0  		/* do last cell on middle line */
		if (board(i-1   , COLS-2).live = true)	 then score = score + 1
		if (board(i-1   , COLS-1).live = true)	 then score = score + 1
		if (board(i-1   , 0     ).live = true)	 then score = score + 1
		if (board(i     , COLS-2).live = true) 	 then score = score + 1
		if (board(i     , 0     ).live = true) 	 then score = score + 1
		if (board(i+1   , COLS-2).live = true)	 then score = score + 1
		if (board(i+1   , COLS-1).live = true)	 then score = score + 1
		if (board(i+1   , 0     ).live = true) 	 then score = score + 1
		workboard(i,COLS-1).live = false
		if(board(i,COLS-1).live = true AND (score = 2 OR score = 3))
			workboard(i,COLS-1).live = true 
		if(board(i,COLS-1)live = false AND score = 3)
			workboard(i,COLS-1).live = true 
	next i 


	score = 0  				' do left lower corner 
	if (board(ROWS-2, COLS-1).live = true)	 then score = score + 1
	if (board(ROWS-2, 0     ).live = true)	 then score = score + 1
	if (board(ROWS-2, 1     ).live = true) 	 then score = score + 1
	if (board(ROWS-1, COLS-1).live = true) 	 then score = score + 1
	if (board(ROWS-1, 1     ).live = true) 	 then score = score + 1
	if (board(0     , COLS-1).live = true) 	 then score = score + 1
	if (board(0     , 0     ).live = true) 	 then score = score + 1
	if (board(0     , 1     ).live = true) 	 then score = score + 1
	workboard(ROWS-1,0).live = false
	if(board(ROWS-1,0).live = true AND (score = 2 OR score = 3))
		workboard(ROWS-1,0).live = true 
	if(board(ROWS-1,0).live = false AND score = 3)
		workboard(ROWS-1,0).live = true 

	for j = 1 to COLS -1
		score = 0 
		if (board(ROWS-2, j-1   ).live = true)	 then score = score + 1
		if (board(ROWS-2, j     ).live = true) 	 then score = score + 1
		if (board(ROWS-2, j+1   ).live = true)	 then score = score + 1
		if (board(ROWS-1, j-1   ).live = true)	 then score = score + 1
		if (board(ROWS-1, j+1   ).live = true)	 then score = score + 1
		if (board(0     , j-1   ).live = true) 	 then score = score + 1
		if (board(0     , j     ).live = true) 	 then score = score + 1
		if (board(0     , j+1   ).live = true) 	 then score = score + 1
		workboard(ROWS-1,j).live = false
		if(board(ROWS-1,j).live = true AND (score = 2 OR score = 3))
			workboard(ROWS-1,j).live = true 
		if(board(ROWS-1,j).live = false AND score = 3)
			workboard(ROWS-1,j).live = true 
	next j

	score = 0  		/* do right lower corner */
	if (board(ROWS-2, COLS-2).live = true)	 then score = score + 1
	if (board(ROWS-2, COLS-1).live = true) 	 then score = score + 1
	if (board(ROWS-2, 0     ).live = true)	 then score = score + 1
	if (board(ROWS-1, COLS-2).live = true) 	 then score = score + 1
	if (board(ROWS-1, 0     ).live = true) 	 then score = score + 1
	if (board(0     , COLS-2).live = true) 	 then score = score + 1
	if (board(0     , COLS-1).live = true) 	 then score = score + 1
	if (board(0     , 0     ).live = true) 	 then score = score + 1
	workboard(ROWS-1,COLS-1).live = false
	if(board(ROWS-1,COLS-1).live = true AND (score = 2 OR score = 3))
		workboard(ROWS-1,COLS-1).live = true 
	if(board(ROWS-1,COLS-1).live = false AND score = 3)
		workboard(ROWS-1,COLS-1).live = true 

	
==========================================================================


/*----------
	display result of generation
----------*/
	'work2board() ;
	show_board() ;

/*----------
	update stats
----------*/
	/*--------------------------------------------------*/
	move(ROWS + 1 ,5) ;
	sprintf(banner,"              " ) ; 
	addstr(banner) ;
	refresh() ; 
	move(ROWS + 1 ,5) ;
	sprintf(banner,"%u ::: %u", generation++, count) ;
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
				fputc(board[i][j], ifp) ;
			fputc('\n', ifp) ;
		}
		fclose(ifp) ;
	} /* if NULL */
	signal (SIGINT, SIG_IGN) ;
	mvcur(0, COLS -1, LINES - 1, 0 ) ;
	endwin() ; 
	exit(0) ;
} /* die() */

int work2board() 
{
	int i, j ;
	for (i = 0 ; i < ROWS  ; i++)
		for (j = 0 ; j < COLS  ; j++)
			board[i][j] = workboard(i][j] ;
} /* work2board() */

int show_board() { int i, j ;
	extern unsigned int  count ;
	count = 0 ;
	for (i = 0 ; i < ROWS  ; i++)
		for (j = 0 ; j < COLS ; j++)
		{
			move(STARTR + i,STARTC + j) ; 
			addch( board[i][j] ) ;
			if (board[i][j] == LIVE) 
				count++ ;
#ifndef FAST
			refresh() ; 
#endif
		}
#ifdef FAST
		refresh() ; 
#endif
} /* show_board() */

int clear_work() {
	int i, j ;
	for (i = 0 ; i < ROWS  ; i++)
		for (j = 0 ; j < COLS ; j++)
			workboard(i][j] = DEAD;
} /* clear_work() */
