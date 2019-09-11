/*--------------------------------------------------------
 *	KnightsTour.java	-	Deitel P.341 et seq., solution to the 
 *	Knight's Tour problems in Deitel && Deitel 6th, p.343, 
 *	Exercise 7,.22.  
 *	Begun: TEK	 Sun Oct 30 16:35:10 PST 2005
 *	Finished: TEK    Thu Nov 3 2005
 * Began translation from Java -> C++ Mon Jul  5 14:51:05 PDT 2010
 * Done  translation from Java -> C++ Mon Jul  5 16:13:37 PDT 2010
 *	KnithtsTour.cpp
 *	The BOARD contains PRIORITY values
 *	which may be used to refine the choice of Next Move.
 *	This is suitable for either an Introductory or 
 *	Intermediate course in programming.
 * lab release: this one does moves, and updates priorities 
 * correctly.
 * NOTE: this program doesn't use curses.  It doesn't need to,
 * so lack of a library is not a good excuse: programmers
 * (and all engineers) must be innovators.
--------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cctype>
#include <unistd.h>
#include <string>

class Square
{
	// How do you do?  I am a Square.  
	// I am a Classy Object, so I can speak to you.
	// This is what I know:
	public: 
	int 
		x,         /* my position in row. */
		y ,        /* my position in column. */
		priority,  /* number of other squares who can still reach me */
		           /* if zero, I've been visited, or else I'm an orphan (sniff). */
		move ;     /* iteration of game in which I was visited (for a future hack). */
	/* These are what I can do: */
//		public void setY(int m) { y = m ; }
//		public void setX(int m) { x = m ; }
//		public void setPriority(int m) {priority = m ; }
//		public void setMove(int m) { move = m ; }
} ; // Square class definition ends

//============================================================
// There's no Inheritance here, just old-fashioned composition.
// (KnightsTour HAS A Square, as opposed to: KnightsTour IS A Square.)


class KnightsTour 
{
	public: 
	Square board[8][8]  ; // static allocation, chess boards don't grow.
	int 
		* horizontal  , 
		* vertical    ,
		CurrentRow    , 
		CurrentColumn ,
		count         ,  
		result        ;
	void incrimentCount() { count++ ; } 
	int getCount() { return count ; }

	KnightsTour() // constructor
	{
		count = 0 ;  
		result = 0 ;
		horizontal = new int[8] , 
		vertical = new int[8] ;
	} // constructor

	~KnightsTour() // destructor
	{
		delete[] horizontal ;
		delete[] vertical ;
	} // destructor


//////////////////////////////////
// TOOLSET
//////////////////////////////////

	/*
	 * prioritize() finds an optimal move to make given 
	 * the current location.
	 */
	 int prioritize(Square x)
	 {
	 	int i = 0 , testRow, testCol ;
		int minPriority, minMove ;
		int *p = new int[8] , * m = new int[8] ;
		// find _possible_ moves 
		// and count them, 
		// allocate array, 
		// evaluate
		//printf("in prioritize():: x.x: %d x.y: %d\n", x.x, x.y) ;

 		// is a move 0 possible?
    	testRow = CurrentRow -1 ;
	  	testCol = CurrentColumn +2 ;
	   if (  testRow > -1 && testRow < 8 
	   	&& testCol > -1 && testCol < 8)
    	{
 			p[0] = board[testRow][testCol].priority ;
    	}
    	// is a move 1 possible?
    	testRow = CurrentRow -2 ; testCol = CurrentColumn +1 ;
    	if (  testRow > -1 && testRow < 8 
			&& testCol > -1 && testCol < 8) 
		{
 			p[1] = board[testRow][testCol].priority ;
    	}
    	// is a move 2 possible?
    	testRow = CurrentRow -2 ; testCol = CurrentColumn -1 ;
    	if (  testRow > -1 && testRow < 8 
			&& testCol > -1 && testCol < 8) 
		{
 			p[2] = board[testRow][testCol].priority ;
    	}
    	// is a move 3 possible?
    	testRow = CurrentRow -1 ; testCol = CurrentColumn -2 ;
    	if (  testRow > -1 && testRow < 8 
			&& testCol > -1 && testCol < 8) 
		{
 			p[3] = board[testRow][testCol].priority ;
    	}
    	// is a move 4 possible?
    	testRow = CurrentRow +1 ; testCol = CurrentColumn -2 ;
    	if (  testRow > -1 && testRow < 8 
			&& testCol > -1 && testCol < 8) 
		{
 			p[4] = board[testRow][testCol].priority ;
    	}
    	// is a move 5 possible?
    	testRow = CurrentRow +2 ; testCol = CurrentColumn -1 ;
    	if (  testRow > -1 && testRow < 8 
			&& testCol > -1 && testCol < 8) 
		{
 			p[5] = board[testRow][testCol].priority ;
    	}
    	// is a move 6 possible?
    	testRow = CurrentRow +2 ; testCol = CurrentColumn +1 ;
    	if (  testRow > -1 && testRow < 8 
			&& testCol > -1 && testCol < 8) 
		{
 			p[6] = board[testRow][testCol].priority ;
    	}
    	// is a move 7 possible?
    	testRow = CurrentRow +1 ; testCol = CurrentColumn +2 ;
    	if (  testRow > -1 && testRow < 8 
			&& testCol > -1 && testCol < 8) 
		{
 			p[7] = board[testRow][testCol].priority ;
    	}
	
		// get priorities sorted, sort moves accordingly
		for ( i = 0 ; i < 8 ; i++) 
			m[i] = i ; 
		// moves array loaded
		minPriority = 99 ; 
		minMove = 0 ;
		// find the lowest non-zero priority
		for ( i = 0 ; i < 8 ; i++) {
			if(minPriority > p[i] ) {
				if (p[i] > 0) {
					minPriority = p[i] ;
					minMove = i ;
				}
			} 
		}
		return minMove ;
	 } // prioritize

	/* 
	 * makeMove takes a move which has already been selected,
	 * and updates the board to reflect that move.
	 */
	int makeMove(int m)
	{
		int testCol = CurrentColumn + horizontal[m]  ;
		int testRow = CurrentRow + vertical[m] ;
		/*
		 * if the move is not possible, 
		 * reject it silently
		 */
		if (  testCol < 0 || testCol > 7 || testRow < 0 
		|| testRow > 7 || board[testRow][testCol].move != 0)
		{
			return 0 ;
		}
		// re-prioritize all the squares THIS one can reach 
		// before leaving it set current priority to 0
		board[CurrentRow][CurrentColumn].priority = 0 ;

		// is a move 0 possible?
		testRow = CurrentRow -1 ; testCol = CurrentColumn +2 ;
		if (testRow > -1 && testRow < 8 
		&& testCol > -1 && testCol < 8) {
			board[testRow][testCol].priority -- ;
			if ( board[testRow][testCol].priority < 0)
				board[testRow][testCol].priority = 0 ;
		}
		// is a move 1 possible?
		testRow = CurrentRow -2 ; testCol = CurrentColumn +1 ;
		if (testRow > -1 && testRow < 8 
		&& testCol > -1 && testCol < 8) {
			board[testRow][testCol].priority -- ;
			if ( board[testRow][testCol].priority < 0)
				board[testRow][testCol].priority = 0 ;
		}
		// is a move 2 possible?
		testRow = CurrentRow -2 ; testCol = CurrentColumn -1 ;
		if (testRow > -1 && testRow < 8 
		&& testCol > -1 && testCol < 8) {
			board[testRow][testCol].priority -- ;
			if ( board[testRow][testCol].priority < 0)
				board[testRow][testCol].priority = 0 ;
		}
		// is a move 3 possible?
		testRow = CurrentRow -1 ; testCol = CurrentColumn -2 ;
		if (testRow > -1 && testRow < 8 
		&& testCol > -1 && testCol < 8) {
			board[testRow][testCol].priority -- ;
			if ( board[testRow][testCol].priority < 0)
				board[testRow][testCol].priority = 0 ;
		}
		// is a move 4 possible?
		testRow = CurrentRow +1 ; testCol = CurrentColumn -2 ;
		if (testRow > -1 && testRow < 8 
		&& testCol > -1 && testCol < 8) {
			board[testRow][testCol].priority -- ;
			if ( board[testRow][testCol].priority < 0)
				board[testRow][testCol].priority = 0 ;
		}
		// is a move 5 possible?
		testRow = CurrentRow +2 ; testCol = CurrentColumn -1 ;
		if (testRow > -1 && testRow < 8 
		&& testCol > -1 && testCol < 8) {
			board[testRow][testCol].priority -- ;
			if ( board[testRow][testCol].priority < 0)
				board[testRow][testCol].priority = 0 ;
		}
		// is a move 6 possible?
		testRow = CurrentRow +2 ; testCol = CurrentColumn +1 ;
		if (testRow > -1 && testRow < 8 
		&& testCol > -1 && testCol < 8) {
			board[testRow][testCol].priority -- ;
			if ( board[testRow][testCol].priority < 0)
				board[testRow][testCol].priority = 0 ;
		}
		// is a move 7 possible?
		testRow = CurrentRow +1 ; testCol = CurrentColumn +2 ;
		if (testRow > -1 && testRow < 8 
		&& testCol > -1 && testCol < 8) {
			board[testRow][testCol].priority -- ;
			if ( board[testRow][testCol].priority < 0)
				board[testRow][testCol].priority = 0 ;
		}
		// end re-prioritize

		CurrentRow += vertical[m] ;
		CurrentColumn += horizontal[m] ;
		incrimentCount() ;
		board[CurrentRow][CurrentColumn].move = getCount() ; 
		return count ; 
	} //makeMove 

	void dumpBoard(void)
	{
		for (int j = 0 ; j < 8 ; j++)
		{
			printf( "---------------------------------\n") ;
			for (int i = 0 ; i < 8 ; i++)
			{
				if( board[j][i].move != 0 )
					printf("|%3d", 
						board[j][i].move) ;
				else
					printf("|   ") ;
			}
				printf("|  ") ;

			// print priorities
			for (int i = 0 ; i < 8 ; i++)
				printf(" %02d ", 
					board[j][i].priority) ;
			printf("\n") ;
			// print priorities
		} // for int j
		printf( "---------------------------------\n") ;
	} // dumpBoard

	char * decode_move(int m)
	{
		char *s ;
		switch(m)
		{
			case 0: s = (char *) "  up 1, right 2" ; break ;	
			case 1: s = (char *) "  up 2, right 1" ; break ;
			case 2: s = (char *) "  up 2, left  1" ; break ;
			case 3: s = (char *) "  up 1, left  2" ; break ;
			case 4: s = (char *) "down 1, left  2" ; break ;
			case 5: s = (char *) "down 2, left  1" ; break ;
			case 6: s = (char *) "down 2, right 1" ; break ;
			case 7: s = (char *) "down 1, right 2" ; break ;
		} 
		return s ;
	} // decode_move ends

void LoadBoard(void)
{
		int y, x ;
		// MOVES DESCRIPTIONS:
		horizontal[0] =  2 ; vertical[0] = -1 ;
		horizontal[1] =  1 ; vertical[1] = -2 ;
		horizontal[2] = -1 ; vertical[2] = -2 ;
		horizontal[3] = -2 ; vertical[3] = -1 ;
		horizontal[4] = -2 ; vertical[4] =  1 ;
		horizontal[5] = -1 ; vertical[5] =  2 ;
		horizontal[6] =  1 ; vertical[6] =  2 ;
		horizontal[7] =  2 ; vertical[7] =  1 ;

		// load each cell with its own address
		for ( y = 0 ; y < 8 ; y++)
			for ( x = 0 ; x < 8 ; x++)
			{
				//printf("setting board[%d][%d].x to: %d\n", y, x, x) ;
				board[y][x].y = y  ;
				board[y][x].x = x  ;
			}
		// load priorities
		//  row 0
		board[0][0].priority = 2 ;	
		board[0][1].priority = 3 ;	
		board[0][2].priority = 4 ;	
		board[0][3].priority = 4 ;	
		board[0][4].priority = 4 ;	
		board[0][5].priority = 4 ;
		board[0][6].priority = 3 ;
		board[0][7].priority = 2 ;	
		
		// row 1
		board[1][0].priority = 3 ;
		board[1][1].priority = 4 ;
		board[1][2].priority = 6 ;
		board[1][3].priority = 6 ;	
		board[1][4].priority = 6 ;
		board[1][5].priority = 6 ;
		board[1][6].priority = 4 ;
		board[1][7].priority = 3 ;	

		// row 2
		board[2][0].priority = 4 ;
		board[2][1].priority = 6 ;
		board[2][2].priority = 8 ;
		board[2][3].priority = 8 ;	
		board[2][4].priority = 8 ;
		board[2][5].priority = 8 ;
		board[2][6].priority = 6 ;
		board[2][7].priority = 4 ;	

		// row 3
		board[3][0].priority = 4 ;
		board[3][1].priority = 6 ;
		board[3][2].priority = 8 ;
		board[3][3].priority = 8 ;	
		board[3][4].priority = 8 ;
		board[3][5].priority = 8 ;
		board[3][6].priority = 6 ;
		board[3][7].priority = 4 ;	

		// row 4
		board[4][0].priority = 4 ;
		board[4][1].priority = 6 ;
		board[4][2].priority = 8 ;
		board[4][3].priority = 8 ;	
		board[4][4].priority = 8 ;
		board[4][5].priority = 8 ;
		board[4][6].priority = 6 ;
		board[4][7].priority = 4 ;	

		// row 5
		board[5][0].priority = 4 ;
		board[5][1].priority = 6 ;
		board[5][2].priority = 8 ;
		board[5][3].priority = 8 ;
		board[5][4].priority = 8 ;
		board[5][5].priority = 8 ;
		board[5][6].priority = 6 ;
		board[5][7].priority = 4 ;	

		// row 6
		board[6][0].priority = 3 ;
		board[6][1].priority = 4 ;
		board[6][2].priority = 6 ;
		board[6][3].priority = 6 ;	
		board[6][4].priority = 6 ;
		board[6][5].priority = 6 ;
		board[6][6].priority = 4 ;
		board[6][7].priority = 3 ;	

	// row 7
		board[7][0].priority = 2 ;
		board[7][1].priority = 3 ;
		board[7][2].priority = 4 ;
		board[7][3].priority = 4 ;	
		board[7][4].priority = 4 ;
		board[7][5].priority = 4 ;
		board[7][6].priority = 3 ;
		board[7][7].priority = 2 ;	
} // LoadBoard ends

	void run(int starty, int startx)
	{
		int i ;
		count = 1 ; 
		LoadBoard() ;
			for ( int j = 0 ; j < 8 ; j++) {
				for ( i = 0 ; i < 8 ; i++) {
					board[j][i].move = 0 ;
				} // for int i
			} // for int j
		CurrentRow = starty  ; 
		CurrentColumn = startx ;
		board[starty][startx].move = 1 ;
		board[starty][startx].priority = 0 ;
		dumpBoard() ;
		for (int j = 0 ; j < 64; j++) 
		{
		/*
		 * heuristic code: identify possible moves,
		 * rank them, place number of the 
		 * "best" move in i.
		 */
			i = prioritize( board[CurrentRow][CurrentColumn]) ; 
				// pass ref to current address
			result = makeMove(i) ;
			if ( 0 != result )  
			{
				/*printf("move number: %d %s (move: %d)\n", 
					i,  decode_move(i) , result) ;  */
				dumpBoard() ;
			} // if
		} // j
	}
} ; // class KnightsTour ends


int main()
{
	KnightsTour A ;
	int starty, startx ;

	/*------------------------------------------------
	 * MAIN LOOP controls repetitions of game
	 * starting in each of the chess board's 64 cells.
	 * (This isn't properly part of the Knights Tour class, 
	 * instead, it governs how many different runs that 
	 * class will make, so it's properly part of main().
	 ------------------------------------------------*/
	for ( starty = 0 ; starty < 8 ; starty++) 
	{
		for (startx = 0 ; startx < 8 ; startx++) 
		{
			A.run(starty, startx) ;
		} // startx
	} // starty
} // main() ends
