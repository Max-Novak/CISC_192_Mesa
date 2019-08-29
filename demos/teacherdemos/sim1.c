/*-----------------------------------------------------------------------
*	sim1.c	-	simulation: two numbers "chase" a "fleeing" third. 
* The "predators" are slammer beetles (Hypothecarapacies Telco): 
* bugs which evolved to huge size, which kill by flanking their prey 
* and mutually ramming it between them.  If they are even a few seconds off 
* their timing, they miss the crush, and only frighten their prey away, 
* so a kill is only recorded when they are both close enough to the 
* prey (+-5sec) and are both at exactly the right place and time to 
* work together.
Note: the use of backspace and usleep().
-----------------------------------------------------------------------*/
#include <time.h>
#include <unistd.h>
#include <stdio.h>
unsigned short i, x, y, z ;
unsigned int kills = 0 ;
double tries = 0.0 ;
int p ( unsigned short int ) ; 
main() 
{
const int MOD = 330 ;
time_t scratch ;
int count = 0 ;
srand(time(&scratch)) ;
x = rand() ; y = rand() ; z = rand() ;
	system("clear") ;
//for( i=0; i < 26; i++) putchar('\n') ;
do {
	count++ ;
	if (!(count % MOD)) y = rand() ;
	//printf("%05u %05u %05u\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", x, y, z) ;
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b%05u %05u %05u", x, y, z) ;
	usleep(5000) ;
	/*--------------------------------------------------------------------
	*	stable state: when x > y-5 && x < y+5 and z > y-5 && z < y+5
	--------------------------------------------------------------------*/
	if 	(x > (y-5) && ( x < (y+5)) && (z > (y-5)) && ( z < (y+5) ) ) 
	{ 
		if(x==z)
		{
			tries = tries + 1.0 ;
			/* drop down a line */
			printf("  %u killed in %.0f tries\n", ++kills, tries) ;  
		}
		else
		{
			putchar('\n') ;
		}
		y = rand() ;                    /* move y */
	} /* if */
	else 
	{
		tries = tries + 1 ;
		x = p(x) ;
		z = p(z) ;
	}       /* else */
} while (1) ;
}/* main */

int 
p (in) 
unsigned short int in; 
{
	if (in <y-5 || in > y+5)
		return  (in < y-5) ? in+(y-in)/2 : in-(in-y)/2 ;
	else
		return rand() ;
} /* p() ends */

