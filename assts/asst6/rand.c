/*-----------------------------------------------------------------
*
*
-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main ()
{
	srand(time(NULL)) ;
	printf("%d\n",rand( ) % 10 ) ;
	return EXIT_SUCCESS ;
} // main ends
