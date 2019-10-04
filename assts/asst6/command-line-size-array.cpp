
/*-----------------------------------------------------------------
*	command-line-size-array.cpp	-	set array size from CLI
*	Sun Feb 23 15:10:25 PST 2014
-----------------------------------------------------------------*/
#include <time.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std ;


int 
main (int argc, char *argv[], char **env) {
	if (argc < 2) {  cerr << "a.out SIZE\n" ; exit(-1) ; }
	int SIZE = atoi(argv[1]) ;
//	int array[SIZE] ;   // either this...
	int *array = new int[SIZE] ;  // or this is fine, try both:)
	cout << "Int size  : " << sizeof(int)   << endl ;
	cout << "Array size: " << SIZE << endl ;
} /* main ends */
