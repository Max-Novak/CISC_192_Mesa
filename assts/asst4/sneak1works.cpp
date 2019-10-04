/*-----------------------------------------------------------------
*	sneak1.cpp	-	
*
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <ncurses.h>
#include <iostream>
#include <iomanip>

using namespace std ;

int print_array(void ) ;
int lines, columns ;
char ** line ;
int main (int argc, char *argv[], char **env)
{
	int buf[4000] ;
	char linebuf[81] ;
	int i, j,  c ;
	initscr() ;
	// curses provides some variables:
	extern int lines ; 
	lines= LINES ;
	extern int columns ;
	columns = COLS ;
	//mvwprintw(stdscr, 0, 0, "LINES: %d  COLS: %d\n", lines, columns) ;
	//refresh() ;
	char screenmap[LINES+2][COLS+2] ;
	for (i = 0 ; i < LINES+2 ; i++)
	for (j = 0 ; j < COLS+2 ; j++)
		screenmap[i][j] = 0 ;
	//mvaddstr(2,8,linebuf) ;
	//refresh() ;
	i = j = 0 ;
	while (! cin.eof())
	{
		c = cin.get() ;
		if (cin.eof()) break ;
		move(i,j) ;
		screenmap[i][j] = c ;
		echochar(c) ;
		refresh() ;
		j++ ;
		if (j > COLS)
		{
			screenmap[i][j] = '\0' ;
			j = 0 ; 
			i++ ;
			if (i > LINES)
			{
				i = 0 ;
				j = 0 ;
	//			sleep(3) ;
				wclear(stdscr) ;
			}
		}

		if (c == '\n' || c == '\r')
		{
			while (j < COLS) screenmap[i][j++] = '\0' ;
			j = 0 ; 
			i ++ ;
			if (i >= LINES)
			{
	//			sleep(3) ;
				i = 0 ; 
				j = 0 ; 
				wclear(stdscr) ;
			}
		} // if
	//sleep(3) ;
	} // while
	// DISPLAY
	for (i = 0 ; i < LINES-1 ; i++)
		for (j = 0 ; j < COLS-1 ; j++)
		{
			mvwprintw(stdscr,i, j, "%c", screenmap[i][j]) ;
			refresh() ;
		}
		refresh() ;
	endwin() ;

//	system("clear") ;
//	for (i = 0 ; i < LINES -2 ; i++)
//		for (j = 0 ; j < COLS -1 ; j++)
//			printf("%c", screenmap[i][j]) ;
} // main

