/*-----------------------------------------------------------------
*	randrange.cpp	-	create a range of random characters between
*                    a low and high limit.
NOTE: This doesn't gurantee literality or numericity, since the 
ASCII sequence has gaps between high and low case letters full
of punct and digit data.
use: lo hi how_many
excmple: a.out a z 10
Sun Jul 19 20:45:51 PDT 2009
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std ;

int randomrange(int lo, int hi)
{
	return ( lo + rand() % (1 +(hi - lo)) ) ;
} // randomRange ends

int main (int argc, char *argv[], char **env)
{
	srand(time(NULL)) ;
	if (argc != 4) { puts("randrange { lo hi how_many") ; exit(-1) ; }
	int reps = atoi(argv[3]) ;
	int lo = argv[1][0] ;
	int hi = argv[2][0] ;
	if (lo < hi) swap (lo,hi) ;
	for (int i = 0 ; i < reps ; i++)
		printf("%c", randomrange(lo, hi) ) ;
	putchar('\n') ;
} // main
