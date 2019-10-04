/*-----------------------------------------------------------------
*	xcurses.c	-	basic shell for curses development
Wed Oct  3 13:07:31 PDT 2018
Theoni Elizabeth Harrisburg, M.S.
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

int main ()
{

    int has,can,Colors,Color_pairs;
	 int ROWS, COLS, row, col, i, j ;

    initscr();
    start_color();
    has=has_colors(); /* TRUE=term has colors */
    can=can_change_color(); /* TRUE=term can change colors */
    Colors=COLORS; /* number of colors term supports */
    Color_pairs=COLOR_PAIRS; /* num color pairs term supports */

	
	getmaxyx(stdscr, ROWS, COLS) ;

    init_pair(1,COLOR_BLUE,COLOR_GREEN); /* init_pair(pairNum,fg,bg) */
    attrset(COLOR_PAIR(1)); /* set color attribute */

    printw("HI THERE1"); /* set some colored text */
    refresh(); /* show text */
getchar() ;

     border(ROWS, ROWS, COLS, COLS, 0, 0, 0, 0)   ;
refresh() ;
getchar() ;






    endwin();
    printf("has_colors()=%d COLORS=%d COLOR_PAIRS=%d\n",has,Colors,Color_pairs);
    printf("can_change_color()=%d\n",can);
	printf("Maxx: %d  Maxy: %d\n", COLS, ROWS) ;

} // main ends








/*
     int border(ls, rs, ts, bs, tl, tr, bl, br)  
    int wborder(win, ls, rs, ts, bs, tl, tr, bl, br)  
    int box(win, vert, hor)  
    Draw a border around the edges of a window ( or win). In the following table you see the characters and their default values when zero in a call to box(...). In the picture you can see the position from the characters in a box.

      
    Table 8.3: Ncurses - border characters

      
    Figure 8.2: Ncurses - box characters

    int vline(ch, n)  
    int wvline(win, ch, n)  
    int hline(ch, n)  
    int whline(win, ch, n)  
    These functions draw a vertical or horizontal line starting at the current cursor position. ch is the character to use and n is the number of characters to draw. The cursor position is not advanced. 
:set noai

/*
     border(ls, rs, ts, bs, tl, tr, bl, br)   ;
    int wborder(win, ls, rs, ts, bs, tl, tr, bl, br)  
    int box(win, vert, hor)  
    Draw a border around the edges of a window ( or win). In the following table you see the characters and their default values when zero in a call to box(...). In the picture you can see the position from the characters in a box.

      
    Table 8.3: Ncurses - border characters

      
    Figure 8.2: Ncurses - box characters

    int vline(ch, n)  
    int wvline(win, ch, n)  
    int hline(ch, n)  
    int whline(win, ch, n)  
    These functions draw a vertical or horizontal line starting at the current cursor position. ch is the character to use and n is the number of characters to draw. The cursor position is not advanced. 
//sleep(2);
*/
