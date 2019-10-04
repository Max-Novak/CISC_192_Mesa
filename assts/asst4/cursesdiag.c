#include <curses.h>
main()
{
    int has,can,Colors,Color_pairs,i;

    /* code */

    initscr();
    start_color();

    has=has_colors(); /* TRUE=term has colors */
    can=can_change_color(); /* TRUE=term can change colors */
    Colors=COLORS; /* number of colors term supports */
    Color_pairs=COLOR_PAIRS; /* num color pairs term supports */

    init_pair(1,COLOR_BLUE,COLOR_GREEN); /* init_pair(pairNum,fg,bg) */
    attrset(COLOR_PAIR(1)); /* set color attribute */

    printw("HI THERE1"); /* set some colored text */

    refresh(); /* show text */
//sleep(2); /* time to see it */
    endwin();

    printf("has_colors()=%d COLORS=%d COLOR_PAIRS=%d\n",has,Colors,Color_pairs);
    printf("can_change_color()=%d\n",can);
}


