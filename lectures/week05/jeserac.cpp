/*jeserac.c-------------------------------------------------------------
*	jeserac.c	-	prime numbers displayed on a  lattice of the integers
*				after Arthur C Clarke's image in The City And The Stars.
*				Copyright August 19th, 1987 by 
*				TEK, all rights reserved. 
Tue Mar  1 14:48:01 PST 2016 Added in my cprintf() for colored text.
(From domegame.cpp).
Converted to cpp from C.
-----------------------------------------------------------------------*/

using namespace std ;


#define UNIX unix
#undef DOS
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>

#define ESC 27

void normal()
{
#ifdef DOS
(void) putchar(ESC);
fputs("[0m",stdout);
#elifdef UNIX
#endif
return ;
}

void boldface()
{
#ifdef DOS
(void) putchar(ESC); fputs("[1m",stdout);
#elifdef UNIX
#endif
return ;
}

void underline()
{
#ifdef DOS
(void) putchar(ESC); fputs("[4m",stdout);
#elifdef UNIX
#endif
return ;
}

void ClrScr()
{
#ifdef DOS
(void) putchar(ESC); fputs("[2J",stdout);
#elifdef UNIX
	system("clear") ;
#endif
return ;
}

void cprintf(const char * text , int back, int fore)
{
   printf("\033[%2d;%2dm%s\033[0m",  back, fore, text) ;
}
	char buf[1024] ;

/*  GLOBAL DECLARATIONS */

 int index;
 float quotient;
 unsigned int int_lim     = 0, /* max length of interval */
  	max_interval,                /* longest interval between primes */	
 	primes = 1, 
 	total=1,
  	breakpoint,
 	numsperline,
 	interval[500],  /* array of pointers to interval lengths */t,
	limit,
	linepos         = 0, /* current printing char */
	number          = 0, /* number being tested for primacy */
	interval_start  = 0, /* start of longest interval */
	interval_end    = 0, /* end of longest interval */
	last_prime      = 0, /* last prime found => interval_start */
	divisor         = 0, /* incrimented divisor for test */
	count           = 0, /* counter for line & para housekeeping */
	interval_length = 0; /* running interval counter */
/* END DECLARATIONS */

void ruler(unsigned int numsperline)
{
unsigned int lindex;
for (lindex = 0; lindex < 7; lindex++)
	(void) putchar(' ');
(void) putchar('0');
	for (lindex = 1; lindex <= numsperline; lindex++)
	{
		if ((lindex % breakpoint) == 0)
		{
		    (void) putchar('-');
		    sprintf(buf,"%u",lindex);
			 cprintf(buf,YELLOW,LTBLUE) ;
		    if (lindex > 9)
		      lindex++;
		}
		else
			(void) putchar('-');
	}
	(void) putchar('\n');
}

void setup(int argc,char *argv[])
{
  int x;
  ClrScr();
if ((argc == 1) || (atoi(argv[2]) > 50 ) || (atoi(argv[2]) < 1))
{
printf("    \"Jeserac sat motionless within a whirlpool of numbers.\n");
printf("Primes...paraded past...the complete sequence of all those\n");
printf("numbers that possessed no factors except themselves and unity.\n");
printf("    \"Jeserac was no mathematician, though sometimes he liked to\n");
printf("believe he was...It was his pleasure to hack his way through \n");
printf("the arithmetical jungle, and sometimes he discovered wonders\n");
printf("that more skillful explorers had missed. \n");
printf("    \"He set up the matrix of all possible integers, and started his\n");
printf("computer stringing the primes across its surface as beads might\n");
printf("be arranged at the intersections of a mesh...\"\n");
printf("\n     (From 'The City and the Stars' by Arthur C. Clarke, 1953.)\n");
printf("Program JESERAC.EXE by TEK (),\n");
printf("written in Turbo C.\n\n");
printf("With gratitude to Mr. Clarke for that timeless afternoon in 1962\n");
printf("when I first entered the eternal city of Diaspar.\n");
printf("\nPress return \n");
(void) getchar() ;
ClrScr();
#ifdef DOS
printf("This program uses DOS ANSI.SYS escape codes. Check your CONFIG.SYS file\n");
printf("for the line \"device=ansi.sys\"\n");
#endif
printf("\nEnter \"JESERAC xxx yyy <CR>\" xxx = highest and yyy = spacing\n");
printf("yyy must be > 0 and <= 50.\n");
printf("Try JESERAC3 2000 10, then try JESERAC3 2000 29.\n");
printf("TEK\n");
exit(EXIT_FAILURE);
} /* if argc == 1 */
	limit = (unsigned) atoi(argv[1]);
	breakpoint = (unsigned) atoi(argv[2]);
/* LINE LENGTH ROUTINE */
	numsperline = 0;
	for (x = 0; x < 50; x++)
	{
		numsperline += breakpoint;
		if (numsperline > 50)
		{
			numsperline -= breakpoint;
			break;
		}
	}

	for (count = 0; count < 500; count++)
		interval[count] = 0;
	count = 0;
	printf("JESERAC.EXE by TEK, July, 1987\n");
	printf("Primes from 1 to %u in order\n", limit);
	printf("'*' = Prime, '.' = Non-prime.\n");
	ruler(numsperline);
	printf("%5u  ", count);
	underline(); 
	boldface(); (void) putchar('|'); (void) putchar('*');
	normal();
	linepos++;
} /* END PROC SETUP */



/* BEGIN MAIN PROGRAM */
int main(int argc, char * argv[])
{
unsigned int num_lines_printed = 0;

setup(argc, argv); /* do initial housekeeping */

/* BEGIN MAIN LOGIC LOOP */
last_prime = 2;
interval_start = 2;
/* FIND AND DISPLAY PRIMES IN SPECIFIED RANGE OF INTEGERS */
for (number = 2; count < (limit-1);  number++, count++)
{
	for (divisor = 2;( number % divisor != 0) &&
                 (divisor < ((unsigned int) (number / 2 ) + 1) );
                 divisor++)
	           ;                /* null loop body */
	/* IF NUMBER IS PRIME */
	if (divisor == ((unsigned int) (number / 2) +1))
	{
		//boldface(); (void) putchar('*'); normal();

   sprintf(buf,"*") ;
   //cprintf(buf, YELLOW, LTBLUE) ;
   cprintf("*", YELLOW, LTBLUE) ;

		primes++;
		/* INT_LIM IS THE LONGEST INTERVAL EXPERIENCED TO DATE */
		if (int_lim < interval_length)
		{
			int_lim = interval_length;
			interval_start = last_prime;
			interval_end = number;
		}
		/* IN ANY EVENT LOAD LAST PRIME FOR NEXT INTERVAL MEASURE */
		last_prime = number;
		interval[interval_length] += 1;
		interval_length = 0; /* reset for next interval */
	} /* ELSE NUMBER IS NON-PRIME */
	else
	{
		(void) putchar('.');
		interval_length++;
	}
	total++;     /* in any event, it's another number */

	/* NUMBER HAS BEEN DEALT WITH: DO LINE HOUSEKEEPING */
	/* NEW COLUMN ROUTINE */
	if (++linepos % breakpoint == 0)
	{
		underline(); boldface(); (void) putchar('|'); normal();
	}
	/* NEW LINE ROUTINE */
	if (linepos >= numsperline)
	{
		sprintf(buf,"   %u", number); /* last number on line */
		cprintf(buf, YELLOW, LTBLUE) ;
		(void) putchar('\n');
		num_lines_printed++;
		/* NEW PARAGRAPH ROUTINE */
		if (num_lines_printed == breakpoint)
		{
			quotient = (float) primes / (float) total;
			sprintf(buf,"Primes: %u  Total: %u Ratio: %f End on: %u\n",
			primes, number, quotient, limit);
			cprintf(buf, YELLOW, LTBLUE) ;
			
			sprintf(buf,"Max interval: %u Interval start: %u Interval end: %u\n\n",
				int_lim, interval_start, interval_end);
			cprintf(buf, YELLOW, LTBLUE) ;
			if ((count + 2) < limit)
				ruler(numsperline);
			num_lines_printed = 0;
			(void) getchar() ;
		}                             /* if */
		/* END PARAGRAPH ROUTINE */
		/* NEW LINE STARTS HERE */
		if ((count + 2) < (limit))
		{
			sprintf(buf,"%5d  ", number + 1);
			cprintf(buf, YELLOW, LTBLUE) ;
			underline(); boldface(); (void) putchar('|'); normal();
			linepos = 0;
		}
	} /* if linepos */
}  /* END OF MAIN LOGIC LOOP */
quotient = (float) primes / (float) total;
printf("\nPrimes: %u   Total: %u   Ratio: %f   End on: %u\n",
primes, total, quotient, limit);
printf("Max interval: %u Interval start: %u Interval end: %u\n\n",
	int_lim, interval_start, interval_end);
printf("\nPress return for statistics\n");
(void) getchar() ;
printf("Size of interval between primes, by frequency:\n");
for (count = 1; count <= int_lim + 1; count += 2)
{   
	if (count % 20 == 0)
	{
		printf("\nPress return \n");
		(void) getchar() ;
	}
	printf("%u: %u\n", count, interval[count]);
}
printf("Press return: ");
(void) getchar();
return 0 ; 
} /* END OF PROGRAM */

