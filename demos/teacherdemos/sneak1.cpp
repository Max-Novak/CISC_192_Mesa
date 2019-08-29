/*-----------------------------------------------------------------
*	sneak1.cpp	-	SNEAKERS is a film about computer hackers.
*                 the opening credits are self-solving anagrams,
*                 the actual hacking involves a display much 
*                 like this program.
*                 It stars Dan Ackroyd, James Earl Jones, Ben Kingsley, 
*                 Sidney Poitier, Robert Redford.  It's a great
*                 movie for Christmas break:). TEK
Sun Mar 22 20:25:42 PDT 2009
This code took about 6 hours to write, but three or four tries
to get clear on how I wanted to write it.  That's usual.
-----------------------------------------------------------------*/
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ncurses.h>
#include <iostream>
#include <iomanip>
#include <unistd.h>

using namespace std ;

// Global Data:

void 	displayit(void)  ;
void 	clear_buffer(void)  ;
char 	** screenmap ,
      ** line ;
int 	lines, 
      columns ,
      i, 
		j,  
		c ;
const int READ_TIME = 4 ;

int main (int argc, char *argv[], char **env)
{
	srand(time(NULL)) ;

	// start curses
	initscr() ;
	leaveok(stdscr,TRUE) ;

	extern int lines ; 
	extern int columns ;

	lines= LINES ;
	lines -= 2 ;

	columns = COLS ;
	columns -= 2 ;

	// allocate storage based on the terminal screen
	screenmap = new char*[lines+2] ;
	for (i = 0 ; i < (lines + 2) ; i++)
		screenmap[i] = new char[columns+2] ;
	// initialize storage
	for (i = 0 ; i < lines ; i++)
		for (j = 0 ; j < columns+1 ; j++)
			screenmap[i][j] = 0 ;

	// MAIN INPUT LOOP
	// read screen into screenmap array
	//=================================================================================
	i = j = 0 ;
	while (! cin.eof())
	{
		c = cin.get() ;
		if (cin.eof()) 
		{ 
			while (j < columns) 
				screenmap[i][j++] = '\0' ;
			displayit() ;              // input finished early
			clear_buffer() ;
			break ; 
		}
		screenmap[i][j] = c ;
	//	move(i,j) ;                   // used in development
	//	echochar(c) ;
	//	refresh() ;
		j++ ;
		if (j > columns)
		{
			// I don't think we'll ever get here, due to the way
			// I'm handling newlines.  It would take ginormously
			// long lines of text, which won't happen....
			while (j < columns) 
				screenmap[i][j++] = '\0' ; // null string termination

			j = 0 ; 
			i++ ;
			if (i > lines ) // if it will take more than one screen...
			{
				i = 0 ;
				j = 0 ;
				displayit() ;
				wclear(stdscr) ;
				clear_buffer() ;
				continue ; 
			} // if i > lines
		} // if J > columns

		if (c == '\n' || c == '\r')      // end of input line
		{
			while (j < columns) screenmap[i][j++] = '\0' ;
			j = 0 ; 
			i++ ;
			if (i >= lines)
			{
				displayit() ;              // fill screen with what we have....
				wclear(stdscr) ;           // clean up for next page...
				clear_buffer() ;
				i = 0 ; 
				j = 0 ; 
				continue ;  
			}
		} // if
	}    // while (!cin.eof()) 
	//====================================================================================
	// since we handle eof in main loop, all we need to do now 
	// is to shut down curses.
	endwin() ;
}  // main


inline void clear_buffer(void)
{
	int a, b ;
	for (a = 0 ; a < lines ; a++)
		for (b = 0 ; b < columns ; b++)
			screenmap[a][b] = '\0' ;
} // clear_buffer() ends

//inline void displayit(void) 
void displayit(void) 
{

	// DISPLAY RANDOM CHARS IN OUTPUT SHAPE OF REAL TEXT
	// JUST AS IN THE MOVIE...
	for (i = 0 ; i < lines ; i++)
		for (j = 0 ; j < columns ; j++)
		{
			if (isgraph(screenmap[i][j]))
			{
				mvwprintw(stdscr, i,j,"%c", 33 + rand() % 94) ;
			}

		}
	mvwprintw(stdscr, lines,columns,"%c", ' ') ;
	refresh() ; // initial display of cyphertext
	mvwprintw(stdscr, lines,columns,"%c", ' ') ;
	sleep(READ_TIME-1) ;	

	bool donearray[lines][columns] ;
	for (i = 0 ; i < lines ; i ++)
	{
		for (j = 0 ; j < columns - 1 ; j ++)
		{
			donearray[i][j] = false ;
		}
	}

	bool done = true ;
	// don't waste time on elements you won't process
	for (i = 0 ; i < lines ; i++)
		for (j = 0 ; j < columns ; j++)
			if (!isgraph(screenmap[i][j]))
				donearray[i][j] = true ;
	do
	{
		done = true ;
		i = j = 0 ;
		// speed up toward the end, just like a real decryption would
		while(donearray[i][j])
		{
			i = rand() % (lines) ;
			if (donearray[i][j])
				j = rand() % (columns ) ;
		} // while 
		//if ( !donearray[i][j])
		if ( isgraph(screenmap[i][j]))
		{
			if (rand() % 100 == 0)
			{
				mvwprintw(stdscr,i, j, "%c", screenmap[i][j]) ;
				//if (0 == (j % 25) ) refresh() ;
					//usleep(1) ; // the FEEL of the program
				donearray[i][j] = true ;
			} else
			{
				mvwprintw(stdscr, i,j,"%c", 33 + (rand() % 94) ) ;
			}   // else
			refresh() ;
		} // if isgraph

		for (i = 0 ; i < lines ; i ++)
		{
			for (j = 0 ; j < columns  ; j ++)
			{
				if (false ==donearray[i][j]) 
					done = false ;
			} // for j
		}    // for i
	} while (!done) ;
	refresh() ;
	sleep(READ_TIME) ; // READ GIBBERISH
} // displayit() ends
