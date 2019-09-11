/*-----------------------------------------------------------------
*	randomseed2.cpp	-	seed the randomizer by measuring time b/t
*                       keystrokes as user types.
Thu Jul  9 16:18:50 PDT 2009
-----------------------------------------------------------------*/
#include <cstdio>
#include <cctype>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include "/var2/local/include/getchne.h"

using namespace std ;

/*
struct timeval {
time_t      tv_sec;      seconds 
suseconds_t tv_usec;     microseconds 
};
*/

suseconds_t keyseed(void) 
{
	struct timeval timeval ;
	#define REPS 14 
	#ifdef DEBUG
		printf("sizeof(suseconds_t: %d\n", sizeof(suseconds_t)) ;
	#endif
	suseconds_t times[REPS] , start, stop ;
	suseconds_t seed  = 0 ;
	int i, count = 0 ;
	cout << "type something" ;
	do
	{
		gettimeofday(&timeval,NULL) ;
		start = timeval.tv_usec ;   //microseconds
		getchne() ; // getch() in Visual C++
		putchar('\b') ;
		putchar(' ') ;
		putchar('\b') ;
		gettimeofday(&timeval,NULL) ;
		stop = timeval.tv_usec ;
		#ifdef DEBUG
				printf("stop: %u  start: %u\n", stop, start) ;
		#endif
		times[count] = stop  - start ; // store in array
		count++ ;
	} while (count < REPS) ;
	// puts("===============================================================") ;

	for (i = 0 ; i < REPS ; i++)
	{
		//	printf("times[%2d]: %4u\n", i, times[i]) ;
		seed ^= times[i] ; // combine using XOR to get a seed
	}
	#ifdef DEBUG
		printf("seed: %u\n", seed ) ;
	#endif
	return seed ;
} //keyseed ends

int main ()
{
	clock_t seed = (keyseed()) ;
	printf("seed: %u\n", seed ) ;
	srand(seed) ;
	for (int i = 0 ; i < 10 ; i++)
		printf("%10d\n", rand() % 1000 ) ;
} // main ends
